#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

#define NP 12
#define N 100005

using namespace std;

typedef long long ll;

int n, q;
ll pw[NP];

ll getdst(ll x) {
    return *lower_bound(pw,pw+NP,x) - x;
}

struct RT {
    bool dirtyval[4*N];
    bool dirtyadd[4*N];

    ll ddel[4*N];

    // ddel not applied
    ll dval[4*N];
    ll ddst[4*N];

    // ddel applied
    ll mdst[4*N];

    void prop(int i, int rs, int re) {
        if (dirtyval[i] && dirtyadd[i]) {
            dval[i] += ddel[i];
            ddst[i] -= ddel[i];
            ddel[i] = 0;
            dirtyadd[i] = false;
        }

        if (dirtyval[i]) {
            if (rs+1 != re) {
                dirtyval[2*i+1] = dirtyval[2*i+2] = true;
                dirtyadd[2*i+1] = dirtyadd[2*i+2] = false;
                ddel[2*i+1] = ddel[2*i+2] = 0;
                dval[2*i+1] = dval[2*i+2] = dval[i];
                ddst[2*i+1] = ddst[2*i+2] = mdst[2*i+1] = mdst[2*i+2] = ddst[i];
                dirtyval[i] = false;
            }
        } else if (dirtyadd[i]) {
            if (rs+1 != re) {
                dirtyadd[2*i+1] = dirtyadd[2*i+2] = true;
                ddel[2*i+1] += ddel[i]; ddel[2*i+2] += ddel[i];
                mdst[2*i+1] -= ddel[i]; mdst[2*i+2] -= ddel[i];
            }
            dirtyadd[i] = false;
            ddel[i] = 0;
        }
    }

    void sv(int i, int rs, int re, int qs, int qe, ll qx, ll qd) {
        prop(i,rs,re);
        if (rs == qs && re == qe) {
            dirtyval[i] = true;
            dval[i] = qx;
            ddst[i] = mdst[i] = qd;
        } else {
            int md = (rs+re)/2;
            if (qs < md) sv(2*i+1, rs, md, qs, min(qe,md), qx, qd);
            if (qe > md) sv(2*i+2, md, re, max(qs,md), qe, qx, qd);
            mdst[i] = min(mdst[2*i+1], mdst[2*i+2]);
        }
    }

    ll qv(int i, int rs, int re, int qi) {
        prop(i,rs,re);
        if (rs+1 == re) {
            return dval[i];
        } else {
            int md = (rs+re)/2;
            if (qi < md) return qv(2*i+1, rs, md, qi);
            else return qv(2*i+2, md, re, qi);
        }
    }

    void inc(int i, int rs, int re, int qs, int qe, ll dv) {
        prop(i,rs,re);
        if (rs == qs && re == qe) {
            dirtyadd[i] = true;
            ddel[i] += dv;
            mdst[i] -= dv;
        } else {
            int md = (rs+re)/2;
            if (qs < md) inc(2*i+1, rs, md, qs, min(qe,md), dv);
            if (qe > md) inc(2*i+2, md, re, max(qs,md), qe, dv);
            mdst[i] = min(mdst[2*i+1], mdst[2*i+2]);
        }
    }

    void flush(int i, int rs, int re) {
        if (mdst[i] > 0) return;
        if (dirtyval[i]) {
            ll val = dval[i]+ddel[i];
            dirtyadd[i] = false;
            ddel[i] = 0;

            dirtyval[i] = true;
            dval[i] = val;
            ddst[i] = getdst(val);
            mdst[i] = ddst[i];
        } else {
            prop(i,rs,re);
            int md = (rs+re)/2;
            flush(2*i+1, rs, md);
            flush(2*i+2, md, re);
            mdst[i] = min(mdst[2*i+1], mdst[2*i+2]);
        }
    }
} rt;

int main() {
    pw[0] = 1;
    FO(i,1,NP) pw[i] = pw[i-1] * 42;
    rt.dirtyval[0] = true;
    scanf("%d %d", &n, &q);
    FO(i,0,n) {
        ll t; scanf("%lld", &t);
        rt.sv(0, 0, n, i, i+1, t, getdst(t));
    }
    FO(_,0,q) {
        int qt; scanf("%d", &qt);
        if (qt == 1) {
            int i; scanf("%d", &i); i--;
            ll res = rt.qv(0, 0, n, i);
            printf("%lld\n", res);
        } else if (qt == 2) {
            int l, r; ll x; scanf("%d %d %lld", &l, &r, &x); l--;
            rt.sv(0, 0, n, l, r, x, getdst(x));
        } else {
            int l, r; ll x; scanf("%d %d %lld", &l, &r, &x); l--;
            while (1) {
                rt.inc(0, 0, n, l, r, x);
                rt.flush(0, 0, n);
                if (rt.mdst[0] > 0) break;
            }
        }
    }
}