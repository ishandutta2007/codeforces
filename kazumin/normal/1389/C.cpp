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

int32_t main() {
    boost();

    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int n = s.size();
        int ans = n;
        for (int d1 = 0; d1 < 10; d1++) {
            for (int d2 = 0; d2 < 10; d2++) {
                int f = 1, cnt = 0;
                for (int i = 0; i < n; i++) {
                    if (s[i] - '0' == d1 && f == 1) f = 0, cnt++;
                    else if (s[i] - '0' == d2 && f == 0) f = 1, cnt++;
                }
                if (cnt % 2 == 1 && d1 != d2) cnt--;
                ans = min(ans, n - cnt);
            }
        }
        printf("%lld\n", ans);
    }

    return 0;
}