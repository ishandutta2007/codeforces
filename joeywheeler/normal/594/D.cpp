#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

#define MOD 1000000007ll

using namespace std;

typedef long long ll;

struct RT {
    static constexpr int N = 200005;
    typedef ll T;

    T v[4*N];
    static constexpr T IDENTITY = 1;
    T op(const T &a, const T &b) {
        return (a*b)%MOD;
    }

    void init(int i, int rs, int re) {
        v[i] = IDENTITY;
        int md = (rs+re)/2;
        if (rs+1 != re) {
            init(2*i+1, rs, md);
            init(2*i+2, md, re);
        }
    }

    T q(int i, int rs, int re, int qs, int qe) {
        if (rs==qs && re==qe) return v[i];
        else {
            int md=(rs+re)/2;
            T r = IDENTITY;
            if (qs<md) r = op(r, q(2*i+1, rs, md, qs, min(qe,md)));
            if (qe>md) r = op(r, q(2*i+2, md, re, max(qs,md), qe));
            return r;
        }
    }

    void u(int i, int rs, int re, int qi, T qv) {
        if (rs+1==re) v[i] = op(v[i],qv);
        else {
            int md=(rs+re)/2;
            if (qi<md) u(2*i+1, rs, md, qi, qv);
            else u(2*i+2, md, re, qi, qv);
            v[i] = op(v[2*i+1], v[2*i+2]);
        }
    }
};

ll pw(ll a, ll b) {
    ll r = 1;
    while (b) {
        if (b&1) r = (r*a)%MOD;
        a = (a*a)%MOD;
        b /= 2;
    }
    return r;
}

ll inv(ll x) {
    return pw(x,MOD-2);
}

RT ra;
int n, a[200005], q;
vector<int> f[200005];
vector<pair<int,int> > l[200005];
int lf[1000005];
int lo[1000005];
int v[1000005];
int iv[1000005];
ll ans[200005];

int main() {
    FO(i,2,1000005) if (!lf[i]) {
        for (int j = i; j < 1000005; j += i) if (!lf[j]) {
            lf[j] = i;
        }
    }
    scanf("%d", &n);
    ra.init(0,0,n);
    FO(i,0,n) {
        scanf("%d", &a[i]);
        ra.u(0,0,n,i,a[i]);
        int x = a[i];
        while (x > 1) {
            int p = lf[x];
            if (f[i].empty() || f[i].back() != p) {
                f[i].push_back(p);
            }
            x /= p;
        }
    }
    //printf("? %lld\n", ra.q(0,0,n,0,3));
    memset(lo,-1,sizeof lo);
    FO(i,2,1000005) if (lf[i] == i) {
        v[i] = (MOD + 1 - inv(i))%MOD;
        iv[i] = inv(v[i]);
    }
    scanf("%d", &q);
    FO(i,0,q) {
        int L, r; scanf("%d%d", &L, &r); L--; r--;
        l[r].emplace_back(L,i);
    }
    FO(i,0,n) {
        for (int p : f[i]) {
            if (lo[p] != -1) {
                ra.u(0,0,n,lo[p],iv[p]);
            }
            lo[p] = i;
            ra.u(0,0,n,lo[p],v[p]);
        }
        for (auto qu : l[i]) {
            int L, qi; tie(L,qi) = qu;
            ans[qi] = ra.q(0,0,n,L,i+1);
        }
    }
    FO(i,0,q) printf("%lld\n", ans[i]);
}