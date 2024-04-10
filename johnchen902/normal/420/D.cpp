//#include <iostream>
//using std::cerr;
//using std::endl;

#include <cstdlib> // rand()

namespace treap {

struct Treap {
    Treap *l, *r;
    int pri, size, data;
    Treap(int d): l(), r(), pri(std::rand()), size(1), data(d) {}
//    ~Treap() { delete l; delete r; }
};

int size(Treap *t) {
    return t ? t->size : 0;
}
void pull(Treap* t){
    t->size = size(t->l) + size(t->r) + 1;
}
Treap* merge(Treap* a, Treap* b) {
    if(!a) return b;
    if(!b) return a;
    if(a->pri > b->pri) {
        a->r = merge(a->r, b);
        pull(a);
        return a;
    } else {
        b->l = merge(a, b->l);
        pull(b);
        return b;
    }
}
void split(Treap *t, int k, Treap*&a, Treap*&b){
    if(!t) a = b = 0;
    else if(size(t->l) <= k) {
        a = t;
        split(t->r, k - size(t->l) - 1, a->r, b); // XXX k ???
        pull(a);
    } else {
        b = t;
        split(t->l, k, a, b->l);
        pull(b);
    }
}
/*Treap* insert(Treap *t, int k, int data){
    Treap *a, *b;
    split(t, k, a, b);
    return merge(merge(a, new Treap(data)), b);
}*/
Treap* remove(Treap *t, int k){
//    if(t) cerr << "t " << t->data << endl; else cerr << "t null" << endl;
    Treap *a, *b, *c, *d;
    split(t, k - 1, a, b);
//    if(a) cerr << "a " << a->data << endl; else cerr << "a null" << endl;
//    if(b) cerr << "b " << b->data << endl; else cerr << "b null" << endl;
    split(b, k - size(a), c, d);
//    if(c) cerr << "c " << c->data << endl; else cerr << "c null" << endl;
//    if(d) cerr << "d " << d->data << endl; else cerr << "d null" << endl;
//    delete c;
    return merge(a, d);
}
Treap* kth(Treap* t, int k){
//    cerr << "kth(" << t << ", " << k << ")" << endl;

    if(k < size(t->l))
        return kth(t->l, k);
    else if(k == size(t->l))
        return t;
    else
        return kth(t->r, k - size(t->l) - 1);
}

}

#include <cstdio>
#include <algorithm>
#include <ctime>

const int maxn = 1000000;

int val[maxn];
bool used[maxn];

using namespace treap;

int main(){
    std::srand(std::time(0));

    int n, m;
    std::scanf("%d%d", &n, &m);
    Treap* treap = new Treap(0);
    for(int i = 1; i < n; i++)
        treap = merge(treap, new Treap(i));
    std::fill_n(val, n, -1);
//    for(int j = 0; j < size(treap); j++)
//        cerr << kth(treap, j)->data << " ";
//    cerr << endl;
    for(int i = 0; i < m; i++){
        int x, y;
        std::scanf("%d%d", &x, &y);
        x--;
        y--;
//        cerr << "kth..." << endl;
        int opos = kth(treap, y)->data;
        int fndval = val[opos];
        if(fndval != -1 && fndval != x){
//            cerr << "opos = " << opos << endl;
//            cerr << "fndval = " << fndval << endl;
            std::puts("-1");
//            delete treap;
            return 0;
        }
        if(fndval == -1){
            if(used[x]){
//                cerr << x << " is used" << endl;
                std::puts("-1");
//                delete treap;
                return 0;
            } else {
                used[x] = true;
                val[opos] = x;
            }
        }
//        cerr << "removing" << y << "..." << endl;
        treap = remove(treap, y);

//        for(int j = 0; j < size(treap); j++)
//            cerr << kth(treap, j)->data << " ";
//        cerr << endl;

//        cerr << "merging..." << endl;
        treap = merge(new Treap(opos), treap);

//        for(int j = 0; j < size(treap); j++)
//            cerr << kth(treap, j)->data << " ";
//        cerr << endl;

//        for(int j = 0; j < n; j++)
//            cerr << used[j] << " " << val[j] << endl;
    }
    for(int i = 0, j = 0; i < n; i++){
        int fnd = val[i];
        if(fnd == -1){
            while(used[j])
                j++;
            used[j] = true;
            fnd = j;
        }
        std::printf("%d%c", fnd + 1, i == n - 1 ? '\n' : ' ');
    }
//    delete treap;
}