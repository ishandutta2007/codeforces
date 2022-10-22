#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define ld long double
#define pii pair<int, int>
#define f first
#define s second
#define boost() cin.tie(0), cin.sync_with_stdio(0)

const int MN = 2000005, MOD = 998244353;

int t, n, k, v[MN];

int32_t main() {
    boost();

    cin >> t;
    while (t--) {
        cin >> n >> k;
        for (int i = 1; i <= n; i++) cin >> v[i];
        int ans = 1;
        for (int i = n; i > n - k; i--) if (v[i] > 0) ans = 0;
        for (int i = n - k; i > 0; i--) {
            if (v[i] > 0) continue;
            if (v[i] == 0) ans = ans * (k + 1) % MOD;
            else ans = ans * (i + k) % MOD;
        }
        for (int i = 1; i <= k; i++) ans = ans * i % MOD;
        printf("%lld\n", ans);
    }

    return 0;
}