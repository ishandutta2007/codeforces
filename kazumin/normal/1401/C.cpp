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

int n, a[100005], locked[100005];

int32_t main() {
    boost();

    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        int mn = 0x3f3f3f3f;
        for (int i = 1; i <= n; i++) cin >> a[i], mn = min(mn, a[i]);
        vector<int> v;
        for (int i = 1; i <= n; i++) {
            if (a[i] % mn) locked[i] = 1;
            else v.push_back(a[i]);
        }
        sort(v.begin(), v.end());
        int id = 0;
        for (int i = 1; i <= n; i++) {
            if (!locked[i]) a[i] = v[id++];
        }
        int mx = 0;
        int meme = 1;
        for (int i = 1; i <= n; i++) {
            mx = max(mx, a[i]);
            if (a[i] < mx) meme = 0;
        }
        if (meme) printf("YES\n");
        else printf("NO\n");
        for (int i = 1; i <= n; i++) a[i] = locked[i] = 0;
    }

    return 0;
}