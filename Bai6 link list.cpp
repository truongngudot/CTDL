Bước 1 Duyệt toàn bộ danh sách từ đầu đến cuối danh sách
Bước 2: Tạo một node p và gán bằng node đầu danh (pHead) sách: p = ds.pHead;
Bước 3 gán phần tử đầu danh sách bằng node p trỏ đến next: ds.pHead = p->next
Bước 4 Xóa đi node p ở bước 2: delete p; và gán phần tử cuối danh sách bằng NULL: ds.pTail = NULL;
#include <iostream>
#include <vector>
using namespace std;
 
// A Linked List Node
class Node
{
  public:
    int data;                // data field
    Node* next = nullptr;     // pointer to the next node
 
    Node() {}
    Node(int data): data(data) {}
    Node(int data, Node *next): data(data), next(next) {}
};
 
// Helper function to create a new node with the given data and
// pushes it onto the list's front
void push(Node* &head, int data)
{
    Node* newNode = new Node(data);
    newNode->next = head;
    head = newNode;
}
 
// Iterative function to delete a linked list
void deleteList(Node* &head)
{
    Node* prev = head;
 
    while (head)
    {
        head = head->next;
 
        cout << "Deleting " << prev->data << endl;
        delete(prev);
        prev = head;
    }
}
 
int main()
{
    // input keys
    vector<int> keys = { 1, 2, 3, 4, 5 };
    int n = keys.size();
 
    // points to the head node of the linked list
    Node* head = nullptr;
 
    // construct a linked list
    for (int i = n - 1; i >= 0; i--) {
        push(head, keys[i]);
    }
 
    deleteList(head);
 
    if (head == nullptr) {
        cout << "List deleted";
    }
 
    return 0;
}
