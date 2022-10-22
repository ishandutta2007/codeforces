#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

#define ll long long
#define int ll
#define ld long double
#define pii pair<int, int>
#define f first
#define s second
#define readl(_s) getline(cin, (_s));
#define boost() cin.tie(0); cin.sync_with_stdio(0)

const int MN = 200005;

int n, m, a[MN], rev[MN], del[MN], b[MN], x, k, y, u, ans;

int calc(int l, int r) {
    if (l > r) return 0;
    int cnt = r - l + 1;
    vector<int> v;
    int ret = 0;
    int lim = max(a[l - 1], a[r + 1]); //threshold for which berserk will work
    for (int i = l; i <= r; i++) if (a[i] > lim) v.push_back(i);
    if (v.size()) {
        if (cnt < k) return -1;
        if (y * k <= x) {
            int ex = cnt - k;
            return ex * y + x;
        } else {
            int ex = cnt % k;
            int rem = cnt / k;
            return ex * y + rem * x;
        }
    } else {
        if (y * k <= x) {
            return cnt * y;
        } else {
            int ex = cnt % k;
            int rem = cnt / k;
            return ex * y + rem * x;
        }
    }
}

int32_t main() {
    boost();

    cin >> n >> m >> x >> k >> y;
    for (int i = 1; i <= n; i++) cin >> a[i], rev[a[i]] = i;
    int pre = 0;
    for (int i = 1; i <= m; i++) {
        cin >> u;
        b[rev[u]] = u;
        if (rev[u] < pre) return 0 * printf("-1\n");
        int val = calc(pre + 1, rev[u] - 1);
        if (val < 0) return 0 * printf("-1\n");
        ans += val;
        pre = rev[u];
    }
    int val = calc(pre + 1, n);
    if (val < 0) return 0 * printf("-1\n");
    ans += val;
    printf("%lld\n", ans);

    return 0;
}