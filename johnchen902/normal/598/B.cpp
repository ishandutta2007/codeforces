#include <cstdio>
#include <cstdlib>
using namespace std;
struct Node {
    decltype(rand()) pr;
    size_t sz;
    char ch;
    Node *lc, *rc;
    
    Node() : pr(rand()), sz(1), lc(nullptr), rc(nullptr) {}
    Node(char c) : pr(rand()), sz(1), ch(c), lc(nullptr), rc(nullptr) {}
    void update_size();
    void print() const;
};

size_t sz(Node* n) {
    return n ? n->sz : 0;
}

void Node::update_size() {
    this->sz = ::sz(lc) + ::sz(rc) + 1;
}

void Node::print() const {
    if(lc)
        lc->print();
    putchar(ch);
    if(rc)
        rc->print();
}

Node* merge(Node* lhs, Node* rhs) {
    if(!lhs)
        return rhs;
    if(!rhs)
        return lhs;
    if(lhs->pr < rhs->pr) {
        lhs->rc = merge(lhs->rc, rhs);
        lhs->update_size();
        return lhs;
    } else {
        rhs->lc = merge(lhs, rhs->lc);
        rhs->update_size();
        return rhs;
    }
}

void split(Node *n, Node *&ls, Node *&rs, size_t k) {
    if(n) {
        if(sz(n->lc) >= k) {
            rs = n;
            split(n->lc, ls, rs->lc, k);
            rs->update_size();
        } else {
            ls = n;
            split(n->rc, ls->rc, rs, k - sz(n->lc) - 1);
            ls->update_size();
        }
    } else {
        ls = rs = nullptr;
    }
}

Node s[10000];

int main() {
    int n = 0;
    Node *root = nullptr;
    for(char c; (c = getchar()) != '\n'; ) {
        s[n].ch = c;
        root = merge(root, s + n);
        n++;
    }

    int m;
    scanf("%d", &m);
    while(m--) {
        int l, r, k;
        scanf("%d %d %d", &l, &r, &k);
        l--;
        k %= r - l;

        Node *tmp, *p1, *p2, *p3, *p4;
        split(root, tmp, p4, r);
        split(tmp, p1, tmp, l);
        split(tmp, p2, p3, r - l - k);

        root = merge(p1, merge(p3, merge(p2, p4)));
    }
    root->print();
    putchar('\n');
}