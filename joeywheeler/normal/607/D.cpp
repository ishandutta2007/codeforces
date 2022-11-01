#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

#define MOD 1000000007ll

using namespace std;

typedef long long ll;

struct RT {
    static constexpr int N = 200005;

    ll sum[4*N];
    ll dirty[4*N];

    RT() {
        FO(i,0,4*N) sum[i] = 0, dirty[i] = 1;
    }

    void push(int i, int rs, int re) {
        if (rs+1 != re) {
            sum[2*i+1] *= dirty[i];
            sum[2*i+2] *= dirty[i];
            sum[2*i+1] %= MOD;
            sum[2*i+2] %= MOD;

            dirty[2*i+1] *= dirty[i];
            dirty[2*i+2] *= dirty[i];
            dirty[2*i+1] %= MOD;
            dirty[2*i+2] %= MOD;
        }
        dirty[i] = 1;
    }

    void sv(int i, int rs, int re, int qi, ll qv) {
        push(i, rs, re);
        if (rs+1 == re) {
            sum[i] = qv;
        } else {
            int md = (rs+re)/2;
            if (qi < md) {
                sv(2*i+1, rs, md, qi, qv);
            } else {
                sv(2*i+2, md, re, qi, qv);
            }
            sum[i] = (sum[2*i+1] + sum[2*i+2]) % MOD;
        }
    }

    void mul(int i, int rs, int re, int qs, int qe, ll mv) {
        push(i, rs, re);
        if (rs == qs && re == qe) {
            dirty[i] = mv;
            sum[i] = (sum[i]*mv) % MOD;
        } else {
            int md = (rs+re)/2;
            if (qs < md) mul(2*i+1, rs, md, qs, min(qe,md), mv);
            if (qe > md) mul(2*i+2, md, re, max(qs,md), qe, mv);
            sum[i] = (sum[2*i+1] + sum[2*i+2]) % MOD;
        }
    }

    ll qus(int i, int rs, int re, int qs, int qe) {
        //printf("[%d,%d]: %lld\n", rs, re, sum[i]);
        push(i, rs, re);
        if (rs == qs && re == qe) {
            return sum[i];
        } else {
            int md = (rs+re)/2;
            ll res = 0;
            if (qs < md) res += qus(2*i+1, rs, md, qs, min(qe,md));
            if (qe > md) res += qus(2*i+2, md, re, max(qs,md), qe);
            res %= MOD;
            return res;
        }
    }
} rt1, rt2;

ll pw(ll a, ll b) {
    ll r = 1;
    while (b) {
        if (b&1) r = (r*a)%MOD;
        a = (a*a)%MOD;
        b /= 2;
    }
    return r;
}

ll inv(ll a) {
    return pw(a, MOD-2);
}

int l[200005], r[200005];
vector<int> c[200005];
int w[200005];
int n, q;
int t[200005], p[200005];
int T;
int nc[200005];
int par[200005];

void go(int i) {
    l[i] = T; T++;
    for (int j : c[i]) go(j);
    r[i] = T;
    //printf("l,r[%d]=%d,%d\n", i, l[i], r[i]);
}

int main() {
    n = 1;
    scanf("%d %d", &w[1], &q);
    FO(i,0,q) {
        scanf("%d %d", t+i, p+i);
        if (t[i] == 1) {
            n++;
            par[n] = p[i];
            scanf("%d", w+n);
            c[p[i]].push_back(n);
        }
    }
    go(1);
    FO(i,0,n) rt2.sv(0, 0, n, i, 1);
    rt1.sv(0, 0, n, 0, w[1]);

    //rt2.mul(0, 0, n, 0, n, 2);
    //printf("%lld\n", rt2.qus(0, 0, n, 0, 1));

    //return 0;
    int m = 1;
    FO(i,0,q) {
        if (t[i] == 1) {
            m++;
            // activate node m
            // p[i] gets another child
            rt1.mul(0, 0, n, l[p[i]], r[p[i]], ((nc[p[i]]+2) * inv(nc[p[i]]+1)) % MOD);
            rt2.mul(0, 0, n, l[p[i]], r[p[i]], ((nc[p[i]]+2) * inv(nc[p[i]]+1)) % MOD);
            //printf("MUL %d, %d %lld\n", l[p[i]], r[p[i]], ((nc[p[i]]+2) * inv(nc[p[i]]+1)) % MOD);
            nc[p[i]]++;
            //printf("SV TO %lld\n", rt2.qus(0, 0, n, l[m], l[m]+1) * w[m]);
            rt1.sv(0, 0, n, l[m], rt2.qus(0, 0, n, l[m], l[m]+1) * w[m] % MOD);
        } else {
            // query node p[i]
            int nd = p[i];
            ll sv = rt1.qus(0, 0, n, l[nd], r[nd]);
            //printf("[%d,%d) sv=%lld\n", l[nd], r[nd], sv);
            //FO(i,0,n) printf("%lld ", rt2.qus(0, 0, n, i, i+1));
            //printf("\n");
            //FO(i,0,n) printf("%lld ", rt1.qus(0, 0, n, i, i+1));
            //printf("\n");
            if (nd != 1) {
                sv = sv * inv(rt2.qus(0, 0, n, l[par[nd]], l[par[nd]]+1)) % MOD;
            }
            printf("%lld\n", sv);
        }
    }
    //FO(i,0,n) printf("%lld ", rt2.qus(0, 0, n, i, i+1));
}