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

int a[300005], nxt[300005], idx[300005], bit[300005];

void upd(int x, int val) {
    for (int i = x; i < 300005; i += i & -i) bit[i] += val;
}

int qry(int x) {
    int ret = 0;
    for (int i = x; i > 0; i -= i & -i) ret += bit[i];
    return ret;
}

int main() {
    boost();

    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++) cin >> a[i], nxt[i] = 1, idx[a[i]] = i;
        a[n + 1] = 0;
        int can = 1;
        vector<int> v;
        for (int i = 1; i <= n; i++) {
            int id = idx[i];
            if (id == 1) break;
            int rem = qry(n + 1) - qry(id);
            if (id + rem == n) {can = 0; break;}
            upd(id, 1);
            v.push_back(id);
        }
        for (int p : v) upd(p, -1);
        if (can) printf("YES\n");
        else printf("NO\n");
    }

    return 0;
}