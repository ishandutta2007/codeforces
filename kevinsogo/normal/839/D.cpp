#include <bits/stdc++.h>
using namespace std;

#define V 1001111
#define mod 1000000007
typedef long long ll;

ll p2(int e) {
    if (e == 0) return 1;
    if (e & 1) return (p2(e - 1) << 1) % mod;
    ll res = p2(e >> 1);
    return res * res % mod;
}

ll cta[V+1];
ll ct[V+1];
int main() {
    int n;
    scanf("%d", &n);
    while (n--) {
        int a;
        scanf("%d", &a);
        cta[a]++;
    }
    ll ans = 0;
    for (int i = V; i >= 2; i--) {
        for (int j = i; j <= V; j += i) {
            ct[i] += cta[j];
        }
        ct[i] = ct[i] * p2(ct[i]) % mod;
        for (int j = i << 1; j <= V; j += i) {
            ct[i] -= ct[j];
        }
        ct[i] %= mod;
        ans += i * ct[i];
        ans %= mod;
    }
    ans = ans * (mod + 1 >> 1) % mod;
    if (ans < 0) ans += mod;
    printf("%lld\n", ans);
}