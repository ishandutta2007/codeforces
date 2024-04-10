#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 1000005;
const int MOD = 1e9+7;
int vis[N], prime[N], pn;
ll phi(ll num) {
    ll ans = num;
    for (int i = 0; i < pn && prime[i] <= num; i++) {
        if (num % prime[i] == 0) ans = ans / prime[i] * (prime[i] - 1);
        while (num % prime[i] == 0)
            num /= prime[i];
    }
    if (num > 1) ans = ans / num * (num - 1);
    return ans;
}

ll n, k;

int main() {
    for (int i = 2; i < N; i++) {
        if (vis[i]) continue;
        prime[pn++] = i;
        if (1ll * i * i >= 1ll * N) continue;
        for (int j = i * i; j < N; j += i) vis[j] = 1;
    }
    scanf("%lld%lld", &n, &k);
    ll ans = phi(n);
    for (ll i = 2; i <= k; i++) {
        if (i % 2) ans = phi(ans);
        if (ans == 1) break;
    }
    printf("%lld\n", ans % MOD);
    return 0;
}