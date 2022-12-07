#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
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

char s[10];

int main() {
    scanf("%s", s);
    ll x = 0;
    x = x * 10 + (s[0] - '0');
    x = x * 10 + (s[2] - '0');
    x = x * 10 + (s[4] - '0');
    x = x * 10 + (s[3] - '0');
    x = x * 10 + (s[1] - '0');
    printf("%05lld\n", quick_mod(x, 5, 100000));
    return 0;
}