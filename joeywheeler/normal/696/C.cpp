#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

#define MOD 1000000007ll

using namespace std;

typedef long long ll;

ll pw(ll a, ll b) {
    ll r = 1;
    while (b) {
        if (b&1) r = r * a % MOD;
        a = a * a % MOD;
        b /= 2;
    }
    return r;
}

int main() {
    ll n2p = MOD-2;
    ll tp = 2;
    int k; scanf("%d", &k);
    int np = 1;
    FO(z,0,k) {
        ll a; scanf("%lld", &a);
        n2p = pw(n2p, a) % MOD;
        tp = pw(tp, a) % MOD;
        if (a % 2 == 0) np = 0;
    }
    n2p = n2p * pw(MOD-2, MOD-2) % MOD;
    tp = tp * pw(2, MOD-2) % MOD;

    n2p = (n2p + MOD - 1) % MOD * pw(MOD-3, MOD-2) % MOD;
    if (np) n2p = (MOD-n2p) % MOD;

    printf("%lld/%lld\n", n2p, tp);
}