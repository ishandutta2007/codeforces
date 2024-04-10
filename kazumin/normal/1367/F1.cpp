#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

#define ll long long
#define ld long double
#define pii pair<int, int>
#define f first
#define s second
#define readl(_s) getline(cin, (_s));
#define boost() cin.tie(0); cin.sync_with_stdio(0)

const int MN = 3006;

int n, a[MN], b[MN], dp[MN];
map<int, int> mp;

int main() {
    boost();

    int t;
    cin >> t;
    while (t--) {
        mp.clear();
        cin >> n;
        for (int i = 1; i <= n; i++) cin >> a[i], b[i] = a[i];
        sort(b + 1, b + n + 1);
        for (int i = 1; i <= n; i++) mp[b[i]] = i;
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            a[i] = mp[a[i]];
            dp[i] = 1;
            for (int j = 1; j < i; j++) if (a[j] == a[i] - 1) dp[i] = dp[j] + 1;
            ans = max(ans, dp[i]);
        }
        printf("%d\n", n - ans);
    }

    return 0;
}