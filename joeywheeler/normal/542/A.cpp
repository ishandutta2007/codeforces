#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

#define N 200005
using namespace std;

struct RT {
    pair<int,int> a[8*N];

    pair<int,int> q(int i, int rs, int re, int qs, int qe) {
        if (rs==qs && re==qe) return a[i];
        else {
            int md = (rs+re)/2;
            pair<int,int> res(-1,-1);
            if (qs<md) res = max(res, q(2*i+1, rs, md, qs, min(qe,md)));
            if (qe>md) res = max(res, q(2*i+2, md, re, max(qs,md), qe));
            return res;
        }
    }

    void u(int i, int rs, int re, int qi, pair<int,int> qv) {
        if (rs+1==re) a[i] = max(a[i],qv);
        else {
            int md = (rs+re)/2;
            if (qi < md) u(2*i+1, rs, md, qi, qv);
            else u(2*i+2, md, re, qi, qv);
            a[i] = max(a[2*i+1], a[2*i+2]);
        }
    }
} rt1, rt2;

int n, m;
tuple<int,int,int> a[N];
tuple<int,int,int,int> b[N];

int ls[2*N];
int nl;

int x, y; long long ans;

void upd(int X, int Y, long long ANS) {
    if (ANS > ans) {
        x = X; y = Y; ans = ANS;
    }
}

void go() {
    sort(ls,ls+nl);
    nl = unique(ls,ls+nl)-ls;

    FO(I,0,n) {
        int l, r, i;
        tie(r,l,i) = a[I];

        int li = lower_bound(ls,ls+nl,l)-ls;
        //printf("SET %d: (%d,%d)\n", l, r, i);
        rt1.u(0, 0, nl, li, make_pair(r, i));
    }
    FO(I,0,m) {
        int l, r, c, i;
        tie(r,l,c,i) = b[I];

        int li = lower_bound(ls,ls+nl,l)-ls;
        pair<int,int> j = rt1.q(0, 0, nl, 0, li+1);
        //printf("[0,%d]: %d, %d\n", l, j.first, j.second);
        upd(i,j.second,c * 1ll * (min(j.first,r)-l));
    }
    sort(a,a+n);
    sort(b,b+m);

    int J = 0;
    FO(I,0,m) {
        int l, r, j;
        if (J < n) tie(r,l,j) = a[J];
        while (J < n && r <= get<0>(b[I])) {
            int li = lower_bound(ls,ls+nl,l)-ls;
            rt2.u(0, 0, nl, li, make_pair(r-l, j));
            J++;
            if (J < n) tie(r,l,j) = a[J];
        }
        int c, i;
        tie(r,l,c,i) = b[I];

        int li = lower_bound(ls,ls+nl,l)-ls;
        pair<int,int> K = rt2.q(0, 0, nl, li, nl);
        upd(i,K.second,c * 1ll * K.first);
    }
}

int main() {
    scanf("%d %d", &n, &m);
    FO(i,0,n) {
        int l, r; scanf("%d %d", &l, &r);
        a[i] = make_tuple(r, l, i);
        ls[nl++] = l;
    }
    FO(i,0,m) {
        int l, r, c; scanf("%d %d %d", &l, &r, &c);
        ls[nl++] = l;
        b[i] = make_tuple(r, l, c, i);
    }
    go();

    nl = 0;
    rewind(stdin);
    scanf("%d %d", &n, &m);
    FO(i,0,n) {
        int l, r; scanf("%d %d", &l, &r);
        r = 1000000005-r;
        l = 1000000005-l;
        swap(l,r);
        ls[nl++] = l;
        a[i] = make_tuple(r, l, i);
    }
    FO(i,0,m) {
        int l, r, c; scanf("%d %d %d", &l, &r, &c);
        r = 1000000005-r;
        l = 1000000005-l;
        swap(l,r);
        ls[nl++] = l;
        b[i] = make_tuple(r, l, c, i);
    }
    memset(&rt1, 0, sizeof rt1);
    memset(&rt2, 0, sizeof rt2);
    go();


    printf("%lld\n", ans);
    if (ans) printf("%d %d\n", y+1, x+1);
}