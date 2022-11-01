#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

typedef bitset<1000> T;

int n, m;
T msk;
T prime;
int a[100005];
vector<int> u[100005];
int l[100005], r[100005], O;
int iv[100005];

T rot(const T &b, int x) {
    // x in [0,m) 0 goes to x
    return ((b<<x)|(b>>(m-x)))&msk;
}

void go(int i, int p) {
    iv[O] = a[i];
    l[i] = O++;
    for (int j : u[i]) if (j != p) {
        go(j,i);
    }
    r[i] = O;
}

struct RT {
    T rt[400005];
    int d[400005];

    void init(int i, int rs, int re) {
        if (rs+1 != re) {
            int md = (rs+re)/2;
            init(2*i+1, rs, md);
            init(2*i+2, md, re);
            rt[i] = rt[2*i+1] | rt[2*i+2];
        } else {
            rt[i][iv[rs]] = 1;
        }
    }

    void add(int i, int rs, int re, int qs, int qe, int v) {
        if (qs == rs && qe == re) {
            d[i] += v;
            d[i] %= m;
            rt[i] = rot(rt[i], v);
        } else {
            int md = (rs+re)/2;
            if (qs<md) add(2*i+1, rs, md, qs, min(qe,md), v);
            if (qe>md) add(2*i+2, md, re, max(qs,md), qe, v);
            rt[i] = rot(rt[2*i+1]|rt[2*i+2],d[i]);
        }
    }

    T qu(int i, int rs, int re, int qs, int qe) {
        if (qs == rs && qe == re) {
            return rt[i];
        } else {
            int md = (rs+re)/2;
            T res;
            if (qs<md) res = qu(2*i+1, rs, md, qs, min(qe,md));
            if (qe>md) res |= qu(2*i+2, md, re, max(qs,md), qe);
            return rot(res, d[i]);
        }
    }
} rt;

int main() {
    scanf("%d%d", &n, &m);
    FO(i,0,m) msk[i] = 1;
    FO(i,1,n+1) {
        scanf("%d", a+i);
        a[i] %= m;
    }
    FO(i,0,n-1) {
        int x, y; scanf("%d%d", &x, &y);
        u[x].push_back(y);
        u[y].push_back(x);
    }
    FO(i,2,m) prime[i] = 1;
    FO(j,2,m) for (int k = 2*j; k < m; k += j) prime[k] = 0;

    go(1,0);
    rt.init(0,0,n);
    //FO(i,1,n+1) printf("l,r[%d]=%d,%d\n", i, l[i], r[i]);
    //FO(i,0,n) printf("iv[%d]=%d\n", i, iv[i]);

    int q; scanf("%d", &q);
    FO(z,0,q) {
        int t; scanf("%d", &t);
        if (t == 1) {
            int v, x; scanf("%d%d", &v, &x);
            rt.add(0,0,n,l[v],r[v],x%m);
        } else {
            int v; scanf("%d", &v);
            T res = rt.qu(0,0,n,l[v],r[v]) & prime;
            printf("%d\n", res.count());
        }
    }
}