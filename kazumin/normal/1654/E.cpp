#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define ld long double
#define pii pair<int, int>
#define f first
#define s second
#define boost() cin.tie(0), cin.sync_with_stdio(0)

const int MN = 100005, SQRT = 300;

int n, a[MN], ans = 1, vis[MN * 2];

int32_t main() {
    boost();

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int d = -SQRT; d <= SQRT; d++) {
        vector<int> v;
        for (int i = 1; i <= n; i++) v.push_back(a[i] + d * i);
        sort(v.begin(), v.end());
        int len = 0, pre = v[0];
        for (int p : v) {
            if (p == pre) len++;
            else pre = p, len = 1;
            ans = max(ans, len);
        }
        ans = max(ans, len);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= min(n, i + 335); j++) {
            int d = a[j] - a[i];
            if (d % (j - i)) continue;
            d /= j - i;
            if ((-SQRT <= d && d <= SQRT) || vis[d + MN]) continue;
            vis[d + MN] = 1;
            int cnt = 2;
            for (int k = j + 1; k <= min(n, i + 335); k++) {
                int pred = a[i] + d * (k - i);
                if (pred < 1 || pred > MN) break;
                if (a[k] == pred) cnt++;
            }
            ans = max(ans, cnt);
        }
        for (int j = i + 1; j <= min(n, i + 335); j++) {
            int d = a[j] - a[i];
            if (d % (j - i)) continue;
            d /= j - i;
            vis[d + MN] = 0;
        }
    }
    printf("%lld\n", n - ans);

    return 0;
}