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

const int MN = 200005;

int t, n, k, vis[MN];
string s;

int main() {
    boost();

    cin >> t;
    while (t--) {
        cin >> n >> k >> s;
        int ans = 0;
        vector<int> v;
        for (int i = 0; i < s.size(); i++) {
            vis[i] = 0;
            if (s[i] == '1') vis[i] = 1, v.push_back(i);
        }
        for (int p : v) {
            for (int i = p + 1; i <= min((int) s.size() - 1, p + k); i++) {
                if (vis[i]) break;
                vis[i] = 1;
            }
            for (int i = p - 1; i >= max(0, p - k); i--) {
                if (vis[i]) break;
                vis[i] = 1;
            }
        }
        //for (int p = 0; p < n; p++) printf("%d", vis[p]);
        for (int p = 0; p < n; p++) {
            if (vis[p]) continue;
            ans++;
            for (int i = p + 1; i <= min((int) s.size() - 1, p + k); i++) {
                if (vis[i]) break;
                vis[i] = 1;
            }
            for (int i = p - 1; i >= max(0, p - k); i--) {
                if (vis[i]) break;
                vis[i] = 1;
            }
        }
        printf("%d\n", ans);
    }

    return 0;
}