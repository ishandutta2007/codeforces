#include <bits/stdc++.h>
using namespace std;
#define int long long
struct Node {
    Node *l;
    Node *r;
    int data;
    Node(int x) : l(nullptr), r(nullptr), data(x) {};
};
class List {
    private :
        Node *Begin;
        Node *End;
        int len;

    public :
        List() : Begin(nullptr), End(nullptr), len(0) {};
        void push_back(int k) {
            Node* t = new Node(k);
            if(End) {
               End -> r = t;
               t -> l = End;
               End = t;
            }
            else {
                Begin = t;
                End = t;
            }
            len++;
        }
        void push_front(int k) {
            Node* t = new Node(k);
            if(Begin) {
                Begin -> l = t;
                t -> r = Begin;
                Begin = t;
            }
            else {
                Begin = t;
                End = t;
            }
            len++;
        }
        int pop_back() {
            if(! Begin) {
                exit(1);
            }
            Node* t = End;
            End = End -> l;
            int res = t -> data;
            delete t;
            len--;
            return res;
        }
        int pop_front() {
            if(! Begin) {
                exit(1);
            }
            Node* t = Begin;
            Begin = Begin -> r;
            len--;
            int res = t -> data;
            delete t;
            return res;
        }
        void push_back(List* l) {
            if(End) {
                End -> r = l -> Begin;
            }
            else {
                Begin = l -> Begin;
            }
            l -> Begin -> l = End;
            End = l -> End;
            len += l -> len;
            l -> Begin = nullptr;
            l -> End = nullptr;
            l -> len = 0;
        }
        void push_front(List* r) {
            if(Begin) {
                Begin -> l = r -> End;
            }
            else {
                End = r -> End;
            }
            r -> End -> r = Begin;
            Begin = r -> Begin;
            len += r -> len;
            r -> Begin = nullptr;
            r -> End = nullptr;
            r -> len = 0;
        }
        int front() {
            if(Begin) {
                return Begin -> data;
            }
            exit(1);
        }
        int back() {
            if(End) {
                return End -> data;
            }
            exit(1);
        }
        int size() {
            return len;
        }
        void print() {
            while(Begin) {
                cout << Begin -> data << '\n';
                Begin = Begin -> r;
            }
        }
};
signed main() {
    List a;
    string s;
    cin >> s;
    for(int i = s.size() - 1; i >= 0; i--) {
        int x = i + 1;
        if(s[i] == 'r') {
            a.push_front(x);
        }
        else {
            a.push_back(x);
        }
    }
    a.print();
}