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

const int MN = 35;

int t, n, m, a[MN][MN];

int main() {
    boost();

    cin >> t;
    while (t--) {
        cin >> n >> m;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                cin >> a[i][j];
            }
        }
        int ans = 0;
        for (int sum = 2; sum <= n + m; sum++) {
            int rsum = n + m - sum + 2;
            if (rsum <= sum) break;
            int zc = 0, oc = 0;
            for (int r = 1; r <= n; r++) {
                int c = sum - r;
                if (c < 1 || c > m) continue;
                if (a[r][c]) oc++;
                else zc++;
            }
            for (int r = 1; r <= n; r++) {
                int c = rsum - r;
                if (c < 1 || c > m) continue;
                if (a[r][c]) oc++;
                else zc++;
            }
            ans += min(zc, oc);
        }
        printf("%d\n", ans);
    }

    return 0;
}