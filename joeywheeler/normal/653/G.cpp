#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

#define MOD 1000000007ll

using namespace std;

typedef long long ll;

ll f[300005], vf[300005];
ll pwmd(ll a, ll b) {
    ll r = 1;
    while (b) {
        if (b&1) r=r*a%MOD;
        a=a*a%MOD;
        b/=2;
    }
    return r;
}
ll c(int n, int k) { return f[n] * vf[k] % MOD * vf[n-k] % MOD; }

int n;
int coef[300005], t[300005];

map<int,vector<int> > m;
int spf[300005];

void add(int x) {
    while (x != 1) {
        int p = spf[x];
        int c = 0;
        while (x%p == 0) {
            c++; x /= p;
        }
        m[p].push_back(c);
    }
}

long long res;

void go(vector<int> v) {
    sort(v.begin(),v.end());
    reverse(v.begin(),v.end());
    FO(i,0,sz(v)) res += coef[n-i-1] * 1ll * v[i];
    res %= MOD;
}

int main() {
    f[0] = 1;
    FO(i,1,300005) f[i] = i*f[i-1]%MOD;
    vf[300004] = pwmd(f[300004], MOD-2);
    for (int i = 300003; i >= 0; i--) vf[i] = vf[i+1]*(i+1)%MOD;
    scanf("%d", &n);

    FO(i,1,n) {
        t[i] = t[i-1] + c(n-1,i-1);
        if (t[i] >= MOD) t[i] -= MOD;
    }
    FO(i,0,n) {
        coef[i] = (MOD + t[i] - t[n-i-1]) % MOD;
    }

    FO(i,2,300005) if (!spf[i]) {
        for (int j = i; j < 300005; j += i) if (!spf[j]) spf[j] = i;
    }
    FO(i,0,n) {
        int x; scanf("%d", &x);
        add(x);
    }
    FO(i,0,300005) if (m.count(i)) go(m[i]);

    printf("%lld\n", res);
}