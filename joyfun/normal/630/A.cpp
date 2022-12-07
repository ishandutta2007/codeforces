#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;

ll quick_mod(ll x, ll k, ll MOD) {
    ll ans = 1LL;
    x %= MOD;
    while (k > 0) {
        if (k&1) ans = ans * x % MOD;
        x = x * x % MOD;
        k >>= 1;
    }
    return ans;
}

ll n;

int main() {
    scanf("%lld", &n);
    printf("%lld\n", quick_mod(5, n, 100));
    return 0;
}