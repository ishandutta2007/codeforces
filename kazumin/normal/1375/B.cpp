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

int a[305][305];

int main() {
    boost();

    int t, n, m;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        bool can = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                int lim = 4;
                if (i == 1 || i == n) lim--;
                if (j == 1 || j == m) lim--;
                cin >> a[i][j];
                if (a[i][j] > lim) can = 0;
            }
        }
        if (!can) printf("NO\n");
        else {
            printf("YES\n");
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= m; j++) {
                    int lim = 4;
                    if (i == 1 || i == n) lim--;
                    if (j == 1 || j == m) lim--;
                    printf("%d ", lim);
                }
                printf("\n");
            }
        }
    }

    return 0;
}