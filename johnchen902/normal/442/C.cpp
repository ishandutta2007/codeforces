#include <cstdio>
#include <cstdlib>
#include <list>
using namespace std;

struct Treap {
    int v, heap;
    int size;
    int minv, minid;
    Treap *lchild, *rchild;
    Treap(int vv): v(vv), heap(rand()), size(1), minv(v), minid(0), lchild(nullptr), rchild(nullptr) {}
    void pull();
    void debug();
};

inline int size_of(Treap * t) {
    return t ? t->size : 0;
}

void Treap::pull() {
    size = size_of(lchild) + 1 + size_of(rchild);
    minv = v;
    minid = size_of(lchild);
    if(lchild && lchild->minv < minv) {
        minv = lchild->minv;
        minid = lchild->minid;
    }
    if(rchild && rchild->minv < minv) {
        minv = rchild->minv;
        minid = size_of(lchild) + 1 + rchild->minid;
    }
}

void Treap::debug() {
    printf("{l=");
    if(lchild) lchild->debug(); else printf("nullptr");
    printf(",v=%d,h=%d,s=%d,m=%d,mi=%d,r=", v, heap, size, minv, minid);
    if(rchild) rchild->debug(); else printf("nullptr");
    printf("}");
}

Treap* merge(Treap* lhs, Treap* rhs) {
    if(!lhs) return rhs;
    if(!rhs) return lhs;
    if(lhs->heap < rhs->heap) {
        lhs->rchild = merge(lhs->rchild, rhs);
        lhs->pull();
        return lhs;
    } else {
        rhs->lchild = merge(lhs, rhs->lchild);
        rhs->pull();
        return rhs;
    }
}

void split(Treap* t, int k, Treap*& lhs, Treap*& rhs) {
    if(!t) {
        lhs = rhs = nullptr;
    } else if(k <= size_of(t->lchild)) {
        rhs = t;
        split(t->lchild, k, lhs, t->lchild);
        t->pull();
    } else {
        lhs = t;
        split(t->rchild, k - 1 - size_of(t->lchild), t->rchild, rhs);
        t->pull();
    }
}

inline Treap* split(Treap* t, int k, Treap*& lhs) {
    Treap* rhs;
    split(t, k, lhs, rhs);
    return rhs;
}

long long score;

void solve(Treap*& t) {
    while(t->size > 2) {
        int todo;
        if(t->minid == 0) {
            Treap *t1, *t2;
            split(t, 1, t1, t2);
            solve(t2);
            t = merge(t1, t2);
            todo = 1;
        } else if(t->minid == t->size - 1) {
            Treap *t1, *t2;
            split(t, t->size - 1, t1, t2);
            solve(t1);
            t = merge(t1, t2);
            todo = 1;
        } else {
            todo = t->minid;
        }
        Treap *t1, *t2, *t3, *t4, *t5;
        split(split(split(split(t, todo - 1, t1), 1, t2), 1, t3), 1, t4, t5);

        delete t3;
        score += min(t2->v, t4->v);
        t = merge(merge(merge(t1, t2), t4), t5);
    }
}

int main(){
    int n;
    scanf("%d", &n);
    if(n == 1) {
        puts("0");
        return 0;
    }
    Treap * t = nullptr;
    for(int i = 0; i < n; i++) {
        int v;
        scanf("%d", &v);
        t = merge(t, new Treap(v));
    }
    solve(t);
    Treap *t1, *t2;
    split(t, 1, t1, t2);
    delete t1;
    delete t2;

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wformat"
    printf("%I64d\n", score);
#pragma GCC diagnostic pop
}