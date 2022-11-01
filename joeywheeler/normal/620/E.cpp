#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

#define N 400005

using namespace std;

typedef long long ll;

struct rt {
    int dc[4*N];
    ll m[4*N];

    void p(int i) {
        if (dc[i] && 2*i+2 < 4*N) {
            dc[2*i+1] = dc[i];
            m[2*i+1] = 1ll << dc[i];
            dc[2*i+2] = dc[i];
            m[2*i+2] = 1ll << dc[i];
        }
        dc[i] = 0;
    }

    void u(int i, int rs, int re, int qs, int qe, int qc) {
        p(i);
        if (rs == qs && re == qe) {
            dc[i] = qc;
            m[i] = 1ll << qc;
        } else {
            int md = (rs+re)/2;
            if (qs < md) u(2*i+1, rs, md, qs, min(qe, md), qc);
            if (qe > md) u(2*i+2, md, re, max(qs, md), qe, qc);
            m[i] = m[2*i+1] | m[2*i+2];
        }
    }

    ll q(int i, int rs, int re, int qs, int qe) {
        if (dc[i] != 0) return 1ll << dc[i];
        if (rs == qs && re == qe) {
            return m[i];
        } else {
            ll res = 0;
            int md = (rs+re)/2;
            if (qs < md) res |= q(2*i+1, rs, md, qs, min(qe, md));
            if (qe > md) res |= q(2*i+2, md, re, max(qs, md), qe);
            return res;
        }
    }
};

rt t;
int n, m;
vector<int> u[N];
int l[N], r[N], O;
int oc[N];

void go(int i, int p) {
    l[i] = O++;
    for (int j : u[i]) if (j != p) {
        go(j,i);
    }
    r[i] = O;
}

void go2(int i, int p) {
    t.u(0,0,N,l[i],r[i],oc[i]);
    for (int j : u[i]) if (j != p) {
        go2(j,i);
    }
}

int main() {
    scanf("%d%d", &n, &m);
    FO(i,0,n) scanf("%d", &oc[i+1]);
    FO(i,0,n-1) {
        int x, y; scanf("%d%d", &x, &y);
        u[x].push_back(y);
        u[y].push_back(x);
    }
    go(1,0);
    go2(1,0);
    FO(z,0,m) {
        int ty; scanf("%d", &ty);
        if (ty == 1) {
            int v, c; scanf("%d%d", &v, &c);
            t.u(0,0,N,l[v],r[v],c);
        } else {
            int v; scanf("%d", &v);
            printf("%d\n", __builtin_popcountll(t.q(0,0,N,l[v],r[v])));
        }
    }
}