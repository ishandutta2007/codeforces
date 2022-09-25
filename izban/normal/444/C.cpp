#include <iostream>
#include <string>
#include <map>
#include <math.h>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <set>
#include <queue>
#include <sstream>
#include <deque>
#include <memory.h>
#include <cassert>
#include <ctime>
#include <cstring>


using namespace std; 

#define ll long long
#pragma comment(linker, "/STACK:64000000")

const int maxn = 200200;
const int inf = 1000000007;
const int mod = 1000000007;
const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};

struct item {
    item *l, *r;
    int prior, cnt;
    ll value, toAdd, sum;
    
    item() {
        l = r = 0;
        prior = toAdd = value = cnt = 0;
        sum = 0;
    }
};

typedef item * pitem;

int cnt(pitem t) {
    return t ? t->cnt : 0;
}

int gcnt(pitem t) {
    return cnt(t);
}

ll sum(pitem t) {
    return t ? t->sum + 1LL * t->cnt * t->toAdd : 0;
}

ll gsum(pitem t) {
    return sum(t);
}

void push(pitem t) {
    if (t) {
        t->cnt = cnt(t->l) + cnt(t->r) + 1;
        t->sum = sum(t->l) + sum(t->r) + t->value;
        if (t->toAdd) {
            t->value += t->toAdd;
            t->sum += 1LL * t->toAdd * t->cnt;
            if (t->l) t->l->toAdd += t->toAdd;
            if (t->r) t->r->toAdd += t->toAdd;
            t->toAdd = 0;
        }
    }
}

void merge(pitem &t, pitem l, pitem r) {
    push(t); push(l); push(r);
    if (!l || !r) 
        t = l ? l : r;
    else if (l->prior > r->prior) 
        merge(l->r, l->r, r), t = l;
    else 
        merge(r->l, l, r->l), t = r;
    push(t); push(l); push(r);
}   

void split(pitem t, pitem &l, pitem &r, int key) {
    push(t); push(l); push(r);
    if (!t) return void(l = r = 0);
    if (cnt(t->l) >= key)
        split(t->l, l, t->l, key), r = t;
    else
        split(t->r, t->r, r, key - cnt(t->l) - 1), l = t;
    push(t); push(l); push(r);
}

struct iitem {
    iitem *l, *r;
    int prior, cnt, color;
    ll sum;
    pitem t;
    
    iitem() {
        l = r = 0;
        prior = cnt = color = 0;
        t = 0;
        sum = 0;
    }
    
    iitem(pitem tt, int cc) {
        l = r = 0;
        t = tt;
        sum = gsum(tt);
        prior = rand();
        cnt = gcnt(tt);
        color = cc;
    }
};

typedef iitem * piitem;

int cnt(piitem t) {
    return t ? t->cnt : 0;
}

ll sum(piitem t) {
    return t ? t->sum : 0;
}

void push(piitem t) {
    if (t) {
        push(t->t);
        t->cnt = cnt(t->l) + cnt(t->r) + cnt(t->t);
        t->sum = sum(t->l) + sum(t->r) + sum(t->t);
    }
}

void merge(piitem &t, piitem l, piitem r) {
    push(t); push(l); push(r);
    if (!l || !r) 
        t = l ? l : r;
    else if (l->prior > r->prior) 
        merge(l->r, l->r, r), t = l;
    else 
        merge(r->l, l, r->l), t = r;
    push(t); push(l); push(r);
}   

void split(piitem t, piitem &l, piitem &r, int key) {
    push(t); push(l); push(r);
    if (!t) return void(l = r = 0);
    if (cnt(t->l) + cnt(t->t) > key)
        split(t->l, l, t->l, key), r = t;
    else
        split(t->r, t->r, r, key - cnt(t->l) - cnt(t->t)), l = t;
    push(t); push(l); push(r);
}

piitem getLeft(piitem t) {
    push(t);
    if (t->l) return getLeft(t->l);
    return t;
}

int n, m;
piitem t;

void MMMULTIMERGE(piitem t, pitem &to, int nx) {
    if (!t) return;
    MMMULTIMERGE(t->l, to, nx);
    t->t->toAdd += abs(t->color - nx);
    push(t->t);
    merge(to, to, t->t);
    MMMULTIMERGE(t->r, to, nx);
}

void SSSPLIT(piitem &t1, piitem &t2, int key) {
    if (key == 0) return;
    piitem t3 = 0;
    piitem t4 = getLeft(t2);
    split(t2, t3, t2, cnt(t4->t));
    pitem t5 = 0, t6 = 0, t7 = t3->t;
    split(t7, t5, t6, key);
    merge(t1, t1, new iitem(t5, t4->color));
    merge(t2, new iitem(t6, t4->color), t2);
}

void MMMEGASPLIT(piitem t, piitem &t1, piitem &t2, piitem &t3, int l, int r) {
    split(t, t1, t2, l);
    SSSPLIT(t1, t2, l - cnt(t1));
    split(t2, t2, t3, r - l + 1);
    SSSPLIT(t2, t3, r - l + 1 - cnt(t2));  
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    
    ios_base::sync_with_stdio(0);
    
    while (cin >> n >> m) {
        t = 0;
        for (int i = 1; i <= n; i++) {
            pitem t1 = new item();
            t1->cnt = 1;
            t1->prior = rand();
            piitem tt = new iitem(t1, i);
            merge(t, t, tt);
        }
        
        for (int it = 0; it < m; it++) {
            int T;
            cin >> T;
            if (T == 1) {
                int l, r, x;
                cin >> l >> r >> x;
                l--; r--;
                piitem t1 = 0, t2 = 0, t3 = 0;
                MMMEGASPLIT(t, t1, t2, t3, l, r);
                
                assert(cnt(t1) == l && cnt(t2) == r - l + 1 && cnt(t1) + cnt(t2) + cnt(t3) == n);
                pitem newt = 0;
                MMMULTIMERGE(t2, newt, x);
                t2 = new iitem(newt, x);
                merge(t, t1, t2);
                merge(t, t, t3);                
            }
            if (T == 2) {
                int l, r;
                cin >> l >> r;
                l--; r--;
                piitem t1 = 0, t2 = 0, t3 = 0;
                MMMEGASPLIT(t, t1, t2, t3, l, r);
                assert(cnt(t1) == l && cnt(t2) == r - l + 1 && cnt(t1) + cnt(t2) + cnt(t3) == n);
                
                cout << sum(t2) << endl;
                merge(t, t1, t2);
                merge(t, t, t3);
            }
        }
    }
    
    return 0;
}