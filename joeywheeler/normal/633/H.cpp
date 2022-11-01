#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

int MOD;

struct Matrix {
    const static int N = 3;
    int n;
    int v[N][N];

    void init(int _n) {
        n = _n;
        FO(i,0,n) FO(j,0,n) v[i][j] = 0;
    }

    void ident() {
        FO(i,0,n) FO(j,0,n) v[i][j] = i==j;
    }

    void fib(int a) {
        init(3);
        int nv[3][3] = {
            {1,1,0},
            {1,0,0},
            {a,a,1},
        };
        FO(i,0,3) FO(j,0,3) v[i][j] = nv[i][j];
    }

    Matrix operator*(const Matrix &o) const {
        Matrix res; res.init(n);
        FO(i,0,n) FO(j,0,n) {
            FO(k,0,n) res.v[i][j] += v[i][k] * o.v[k][j];
            res.v[i][j] %= MOD;
        }
        return res;
    }
};

Matrix rt[60005];
int n;
int a[30005];
int gp[30005];
int sa[30005];
int occ[30005];

void u(int i, int a) {
    i += n;
    if (a == -1) rt[i].ident();
    else rt[i].fib(a%MOD);
    for (i/=2; i; i /= 2) rt[i] = rt[2*i] * rt[2*i+1];
}

Matrix q(int l, int r) {
    Matrix rl, rr; rl.init(3); rr.init(3);
    rl.ident(); rr.ident();
    for (l+=n,r+=n;l<r;l/=2,r/=2) {
        if (l&1) rl = rl * rt[l++];
        if (r&1) rr = rt[--r] * rr;
    }
    return rl * rr;
}

int gp_(int x) {
    return n-1-(lower_bound(sa,sa+n,x)-sa);
}

void add(int i, int v) {
    int x = a[i], p = gp[i];
    occ[p] += v;
    if (occ[p] == 0) u(p,-1);
    else u(p,x);
}

bool cmp(pair<pair<int,int>, int> p1, pair<pair<int,int>, int> p2) {
    return make_pair(p1.first.first/300, p1.first.second) <
        make_pair(p2.first.first/300, p2.first.second);
}

pair<pair<int,int>, int> qu[30005];
int g;
int ans[30005];

int main() {
    scanf("%d%d", &n, &MOD);
    FO(i,0,2*n) rt[i].init(3), rt[i].ident();
    FO(i,0,n) scanf("%d", a+i), sa[i] = a[i];
    sort(sa,sa+n);
    FO(i,0,n) gp[i] = gp_(a[i]);
    scanf("%d", &g);
    FO(i,0,g) {
        int l, r;
        scanf("%d%d", &l, &r); l--;
        qu[i] = make_pair(make_pair(l,r),i);
    }
    sort(qu,qu+g,cmp);
    int l = 0, r = 0;
    FO(z,0,g) {
        int ql, qr, qi; tie(ql,qr) = qu[z].first;
        qi = qu[z].second;
        while (r < qr) {
            add(r,1);
            r++;
        }
        while (r > qr) {
            r--;
            add(r,-1);
        }
        while (l<ql) {
            add(l,-1);
            l++;
        }
        while (l>ql) {
            l--;
            add(l,1);
        }
        Matrix mt = q(0,n);
        int res = mt.v[2][1] % MOD;
        ans[qi] = res;
    }
    FO(i,0,g) printf("%d\n", ans[i]);
}