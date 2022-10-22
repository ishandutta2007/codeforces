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

int n, a[MN], b[MN];

int32_t main() {
    boost();

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    for (int s = 0; s <= 21; s++) {
        int cnt = 0;
        for (int i = 1; i <= n; i++) if (a[i] & (1 << s)) cnt++;
        for (int i = 1; i <= cnt; i++) b[i] |= (1 << s);
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) ans += b[i] * b[i];
    printf("%lld\n", ans);

    return 0;
}