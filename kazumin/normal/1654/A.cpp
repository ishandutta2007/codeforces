#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define ld long double
#define pii pair<int, int>
#define f first
#define s second
#define boost() cin.tie(0), cin.sync_with_stdio(0)

int val(int x, int y) {
    if (!x || !y) return 0;
    return max(x, y);
}

int32_t main() {
    boost();

    int t;
    cin >> t;
    while (t--) {
        int n, a[1005];
        memset(a, 0, sizeof(a));
        cin >> n;
        for (int i = 1; i <= n; i++) cin >> a[i];
        int sum = 0, ans = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = i + 1; j <= n; j++) {
                ans = max(ans, a[i] + a[j]);
            }
        }
        printf("%lld\n", ans);
    }

    return 0;
}