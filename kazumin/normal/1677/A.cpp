#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define pii pair<int, int>
#define f first
#define s second
#define boost() cin.tie(0), cin.sync_with_stdio(0)

const int MN = 5005;

int n, a[MN], pre[MN][MN], suf[MN][MN];

int32_t main() {
    boost();

    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++) cin >> a[i];
        for (int i = 1; i <= n; i++) {
            pre[i][0] = 0;
            for (int j = 1; j < i; j++) {
                pre[i][j] = pre[i][j - 1];
                if (a[j] < a[i]) pre[i][j]++;
            }
        }
        for (int i = n; i > 0; i--) {
            suf[i][n + 1] = 0;
            for (int j = n; j > i; j--) {
                suf[i][j] = suf[i][j + 1];
                if (a[j] < a[i]) suf[i][j]++;
            }
        }
        ll ans = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = i + 1; j <= n; j++) {
                ans += (ll) pre[j][i - 1] * (ll) suf[i][j + 1];
            }
        }
        printf("%lld\n", ans);
    }

    return 0;
}