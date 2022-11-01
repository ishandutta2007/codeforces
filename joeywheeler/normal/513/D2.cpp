// worst soln / 10

#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

#define M 1000005

using namespace std;

void NO() {
    printf("IMPOSSIBLE\n");
    exit(0);
}

struct RT {
    int v[4*M];
#define md (rs+re)/2

    void init(int i, int rs, int re) {
        if (rs+1==re) v[i] = rs;
        else {
            init(2*i+1, rs, md);
            init(2*i+2, md, re);
            v[i] = max(v[2*i+1],v[2*i+2]);
        }
    }

    int q(int i, int rs, int re, int qs, int qe) {
        if (rs==qs&&re==qe) return v[i];
        else {
            int a = -1;
            if (qs<md) a = max(a, q(2*i+1, rs, md, qs, min(qe,md)));
            if (qe>md) a = max(a, q(2*i+2, md, re, max(qs,md), qe));
            return a;
        }
    }

    void u(int i, int rs, int re, int qi, int qv) {
        if (rs+1==re) v[i] = qv;
        else {
            if (qi < md) u(2*i+1, rs, md, qi, qv);
            else u(2*i+2, md, re, qi, qv);
            v[i] = max(v[2*i+1],v[2*i+2]);
        }
    }
#undef md
} rt;

int n, c;
int f[M];
int ll[M];

int ra[100005], rb[100005], rs[100005];
int ans[M], sa, T;

int fo[M], lo[M], lft[M], rgt[M];

void go(int l, int r) {
    fo[l] = lo[l] = ++T;
    lft[l] = rgt[l] = -1;

    //printf("GO %d,%d\n", l, r);

    if (l==r) {
        ans[sa++] = l;
        return;
    }

    int md = l;
    if (l != ll[l]) md = rt.q(0,0,M,l+1,ll[l]+1);
    if (md > r) NO();

    if (l+1 <= md) {
        go(l+1,md);
        lft[l] = l+1;
    }
    ans[sa++] = l;
    if (md+1 <= r) {
        go(md+1,r);
        rgt[l] = md+1;
    } else if (md != r) NO();

    //printf("%d -> %d, %d\n", l, lft[l], rgt[l]);

    lo[l] = ++T;
}

bool anc(int a, int b) {
    if (a == -1) return false;
    return fo[a] <= fo[b] && lo[b] <= lo[a];
}

int main() {
    scanf("%d %d", &n, &c);
    FO(i,0,c) {
        int a, b; char t;
        scanf("%d %d %c%*s", &a, &b, &t);
        if (a >= b) NO();

        ra[i] = a; rb[i] = b; rs[i] = t;

        f[a] = max(f[a],b);
        if (t == 'L') ll[a] = max(ll[a], b);
    }
    rt.init(0,0,M);
    for (int i = n; i >= 1; i--) {
        f[i] = max(f[i], i);
        ll[i] = max(ll[i], i);
        if (f[i]!=i) {
            //printf("f[%d]=%d, l[%d]=%d\n", i, f[i], i, ll[i]);
            f[i] = rt.q(0,0,M,i,f[i]+1);
        }
        rt.u(0,0,M,i,f[i]);
    }
    go(1,n);

    FO(i,0,c) {
        if (rs[i] == 'L' && !anc(lft[ra[i]], rb[i])) {
            //printf("FAIL %d,%d,%c\n", ra[i], rb[i], rs[i]);
            NO();
        }
        if (rs[i] == 'R' && !anc(rgt[ra[i]], rb[i])) {
            //printf("FAIL %d,%d,%c\n", ra[i], rb[i], rs[i]);
            NO();
        }
    }
    FO(i,0,n) printf("%d ", ans[i]);
    printf("\n");
}