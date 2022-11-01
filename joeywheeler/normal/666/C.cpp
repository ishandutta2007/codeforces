#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

#define MOD 1000000007ll

using namespace std;

typedef long long ll;
ll f[100005];
ll vf[100005];

ll pw(ll a, ll b) {
    ll r = 1;
    while (b) {
        if (b&1) r = (r*a)%MOD;
        a = (a*a)%MOD;
        b /= 2;
    }
    return r;
}

char buf[100005];
int m, l;
vector<tuple<int,int,int> > qu;
ll s[100005];
ll p25[100005];

ll c(int n, int k) {
    return f[n] * vf[k] % MOD * vf[n-k] % MOD;
}

void pc(int nl) {
    l = nl;
    FO(i,0,l) s[i] = 0;
    FO(i,l,100005) {
        s[i] = s[i-1]*26 + c(i-1,l-1) * p25[i-l];
        s[i] %= MOD;
        //printf("%d:s[%d]=%lld\n", l, i, s[i]);
    }
}

int main() {
    f[0] = 1;
    FO(i,1,100005) f[i] = i*f[i-1]%MOD;
    vf[100004] = pw(f[100004], MOD-2);
    for (int i = 100003; i >= 0; i--) vf[i] = vf[i+1]*(i+1)%MOD;
    p25[0] = 1;
    FO(i,1,100005) p25[i] = p25[i-1]*25%MOD;

    scanf("%d", &m);
    scanf(" %s", buf); l = strlen(buf);
    FO(z,0,m) {
        int t; scanf("%d", &t);
        if (t == 1) {
            scanf(" %s", buf);
            l = strlen(buf);
        } else {
            int n; scanf("%d", &n);
            qu.emplace_back(l, n, z);
        }
    }

    sort(qu.begin(),qu.end());
    l = -1;
    vector<pair<int,ll> > ans;
    for (auto q : qu) {
        int nl, n, z; tie(nl,n,z) = q;
        if (nl != l) {
            pc(nl);
        }
        ans.emplace_back(z,s[n]);
    }
    sort(ans.begin(),ans.end());
    for (auto a : ans) printf("%lld\n", a.second);
}