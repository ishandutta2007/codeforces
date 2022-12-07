#include <iostream>
#include <algorithm>
#include <cstdio>
#include <memory.h>

using namespace std;
typedef long long ll;
const int N = 5555;
const int MOD = 1000000007;

ll s[N];
ll f[N][N];

int main() {
    int n, k, a, b;
    cin >> n >> a >> b >> k;

    f[0][a] = 1;
    for (int step = 0; step < k; ++step) {
        memset(s, 0, sizeof(s));

        for (int i = 1; i <= n; ++i) {
            int l, r;
            if (i < b) {
                r = b - 1;
                l = i - ((b - 1) - i);
                l = max(l, 1);
            } else {
                l = b + 1;
                r = i + (i - (b + 1));
                r = min(r, n);
            }
            s[l] += f[step][i];
            s[i] -= f[step][i];
            s[i + 1] += f[step][i];
            s[r + 1] -= f[step][i];
        }

        ll cur = 0;
        for (int i = 1; i <= n; ++i) {
            cur += s[i];
            f[step + 1][i] = ((cur % MOD) + MOD) % MOD;
        }
    }

    ll ans = 0;
    for (int i = 1; i <= n; ++i) ans += f[k][i];
    cout << ans % MOD << endl;

    return 0;
}