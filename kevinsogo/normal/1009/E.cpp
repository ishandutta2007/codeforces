#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 998244353;

int main() {
    int n;
    scanf("%d", &n);
    vector<ll> p2(n + 2);
    p2[1] = 1;
    for (int i = 1; i <= n; i++) {
        p2[i + 1] = p2[i] * 2 % mod;
    }
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        ll a;
        scanf("%lld", &a);
        ans += (p2[n - i] + (n - 1 - i) * p2[n - 1 - i]) % mod * a % mod;
    }
    printf("%lld\n", ans % mod);
}