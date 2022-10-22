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

const int MN = 2005;

int t, n, a[MN];

int main() {
    boost();

    cin >> t;
    while (t--) {
        cin >> n;
        vector<int> o, e;
        for (int i = 1; i <= 2 * n; i++) {
            cin >> a[i];
            if (a[i] % 2) o.push_back(i);
            else e.push_back(i);
        }
        if (e.size() % 2) e.pop_back(), o.pop_back();
        else if (e.size() > o.size()) e.pop_back(), e.pop_back();
        else o.pop_back(), o.pop_back();
        while (e.size()) {
            int f = e.back(); e.pop_back();
            int s = e.back(); e.pop_back();
            printf("%d %d\n", f, s);
        }
        while (o.size()) {
            int f = o.back(); o.pop_back();
            int s = o.back(); o.pop_back();
            printf("%d %d\n", f, s);
        }
    }

    return 0;
}