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

const int MN = 30;

int n, q, k, a[MN][MN];

int32_t main() {
    boost();

    cin >> n;
    for (int sum = 2; sum <= 2 * n; sum++) {
        int s = sum - 1;
        for (int r = 1; r <= n; r++) {
            int c = sum - r;
            if (c < 1 || c > n) continue;
            if (r & 1) a[r][c] = 1LL << s;
            else a[r][c] = 0;
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) cout << a[i][j] << " ";
        cout << "\n";
        cout << flush;
    }
    cout << flush;
    cin >> q;
    while (q--) {
        vector<pii> pth;
        cin >> k;
        int r = 1, c = 1;
        pth.push_back({r, c});
        while (r < n || c < n) {
            int b = r + c;
            if (!a[r][c]) {
                if (k & (1LL << b)) r++;
                else c++;
            } else {
                if (k & (1LL << b)) c++;
                else r++;
            }
            pth.push_back({r, c});
        }
        for (pii p : pth) {
            cout << p.f << " " << p.s << "\n";
            cout << flush;
        }
        cout << flush;
    }

    return 0;
}