#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

#define MOD 1000000007

using namespace std;

typedef long long ll;

struct Matrix {
    const static int N = 5;
    int n;
    ll v[N][N];

    void init(int _n) {
        n = _n;
        FO(i,0,n) FO(j,0,n) v[i][j] = 0;
    }

    void ident() {
        FO(i,0,n) FO(j,0,n) v[i][j] = 0;
        FO(i,0,n) v[i][i] = 1;
    }

    Matrix operator+(const Matrix &o) const {
        assert(n == o.n);

        Matrix res; res.init(n);
        FO(i,0,n) FO(j,0,n) {
            res.v[i][j] = v[i][j] + o.v[i][j];
            if (res.v[i][j] >= MOD) res.v[i][j] -= MOD;
        }

        return res;
    }

    Matrix operator*(const Matrix &o) const {
        assert(n == o.n);

        Matrix res; res.init(n);
        ll mod2 = MOD*1ll*MOD;
        FO(i,0,n) FO(j,0,n) {
            FO(k,0,n) {
                res.v[i][j] += v[i][k] * o.v[k][j];
                if (res.v[i][j] >= mod2) res.v[i][j] -= mod2;
            }
            res.v[i][j] %= MOD;
        }

        return res;
    }

    Matrix operator^(long long k) {
        Matrix res; res.init(n); res.ident();
        Matrix a = *this;
        while (k) {
            if (k&1) res = res*a;
            a = a*a;
            k /= 2;
        }
        return res;
    }
};

Matrix m;

Matrix rt[400005];
Matrix dt[400005];
int n;

void init(int i, int rs, int re) {
    if (rs+1 == re) {
        rt[i].init(2);
        rt[i].v[0][0] = 1;
        dt[i].init(2);
        dt[i].ident();
    } else {
        int md = (rs+re)/2;
        init(2*i+1, rs, md);
        init(2*i+2, md, re);
        rt[i] = rt[2*i+1] + rt[2*i+2];
        dt[i].init(2);
        dt[i].ident();
    }
}

void upd(int i, int rs, int re, int qs, int qe, Matrix f) {
    if (rs == qs && re == qe) {
        dt[i] = dt[i] * f;
        rt[i] = rt[i] * f;
    } else {
        int md = (rs+re)/2;
        if (qs < md) upd(2*i+1, rs, md, qs, min(qe,md), f);
        if (qe > md) upd(2*i+2, md, re, max(qs,md), qe, f);
        rt[i] = (rt[2*i+1] + rt[2*i+2]) * dt[i];
    }
}

Matrix qu(int i, int rs, int re, int qs, int qe) {
    if (rs == qs && re == qe) {
        return rt[i];
    } else {
        int md = (rs+re)/2;
        Matrix res;
        res.init(2);
        if (qs < md) res = res + qu(2*i+1, rs, md, qs, min(qe,md));
        if (qe > md) res = res + qu(2*i+2, md, re, max(qs,md), qe);
        res = res * dt[i];
        return res;
    }
}

int main() {
    m.init(2);
    m.v[0][0] = m.v[0][1] = m.v[1][0] = 1;

    int q;
    scanf("%d %d", &n, &q);

    init(0, 0, n);
    FO(i,0,n) {
        int a; scanf("%d", &a);
        upd(0, 0, n, i, i+1, m ^ (a-1));
    }

    FO(z,0,q) {
        int t; scanf("%d", &t);
        if (t == 1) {
            int l, r, x; scanf("%d %d %d", &l, &r, &x);
            l--;
            upd(0, 0, n, l, r, m ^ x);
        } else {
            int l, r; scanf("%d %d", &l, &r);
            l--;
            Matrix res = qu(0, 0, n, l, r);
            printf("%lld\n", res.v[0][0]);
        }
    }
}