#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())


using namespace std;

typedef long long ll;

ll B[2] = {400007ll, 800007ll};
ll MOD[2] {1000000003ll, 1000000005ll};
ll pw[2][200005];
map<pair<ll,int>, int> hv;

struct str {
    ll s[200005];
    ll sh[2][200005];

    void init(pair<ll,int> *p, int n) {
        FO(i,0,n) s[i] = hv[p[i]];
        FO(i,0,n) {
            FO(j,0,2) sh[j][i+1] = (sh[j][i] + s[i] * pw[j][i]) % (MOD[j]);
        }
    }

    pair<ll,ll> hsh(int i, int j) {
        ll v1 = (sh[0][j]-sh[0][i]+MOD[0]) * pw[0][200003-i] % MOD[0];
        ll v2 = (sh[1][j]-sh[1][i]+MOD[1]) * pw[1][200003-i] % MOD[1];
        return {v1,v2};
    }
};
str ss, pp; 

vector<pair<ll,int> > cpr(vector<pair<ll,int> > a) {
    vector<pair<ll,int> > r;
    r.push_back(a[0]);
    FO(i,1,sz(a)) if (a[i].second == r.back().second) r.back().first += a[i].first;
    else r.push_back(a[i]);
    return r;
}

vector<pair<ll,int> > rd(int n) {
    vector<pair<ll,int> > r(n);
    FO(i,0,n) {
        scanf("%lld", &r[i].first);
        char c;
        scanf(" %*c %c", &c);
        r[i].second = c;
    }
    return cpr(r);
}

int main() {
    pw[0][0] = pw[1][0] = 1;
    FO(i,1,200005) FO(j,0,2) pw[j][i] = pw[j][i-1]*B[j]%MOD[j];
    int n, m; scanf("%d%d", &n, &m);
    auto s = rd(n);
    auto p = rd(m);

    for (auto x : s) {
        if (!hv.count(x)) {
            int l = sz(hv);
            hv[x] = l+1;
        }
    }
    for (auto x : p) {
        if (!hv.count(x)) {
            int l = sz(hv);
            hv[x] = l+1;
        }
    }

    n = sz(s); m = sz(p);

    if (m == 1) {
        ll res = 0;
        for (auto x : s) {
            if (x.second == p[0].second) {
                res += max(0ll, x.first-p[0].first+1);
            }
        }
        printf("%lld\n", res);
        return 0;
    }

    ss.init(&s[0], n); pp.init(&p[0], m);
    long long res = 0;
    FO(i,0,n) {
        if (p[0].second == s[i].second && p[0].first <= s[i].first && i+m-1 < n) {
            if (ss.hsh(i+1, i+m-1) == pp.hsh(1,m-1)) {
                if (s[i+m-1].second == p[m-1].second && p[m-1].first <= s[i+m-1].first) res++;
            }
        }
    }
    printf("%lld\n", res);
}