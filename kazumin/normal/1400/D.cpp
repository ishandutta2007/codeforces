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

const int MN = 3005;

int n, a[MN];
vector<int> pos[MN];

int bsearch(int num, int id) {
    if (id > pos[num].back()) return pos[num].size();
    int lo = 0, hi = pos[num].size() - 1, mid;
    while (lo < hi) {
        mid = (lo + hi + 1) >> 1;
        if (pos[num][mid] < id) lo = mid;
        else hi = mid - 1;
    }
    if (id > pos[num][lo]) return lo + 1;
    return lo;
}

int tsearch(int num, int id) {
    if (id < pos[num].front()) return pos[num].size();
    int lo = 0, hi = pos[num].size() - 1, mid;
    while (lo < hi) {
        mid = (lo + hi) >> 1;
        if (pos[num][mid] > id) hi = mid;
        else lo = mid + 1;
    }
    if (id < pos[num][lo]) return pos[num].size() - lo;
    return pos[num].size() - 1 - lo;
}

int32_t main() {
    boost();

    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            pos[a[i]].push_back(i);
        }
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = i + 1; j <= n; j++) {
                int p1 = bsearch(a[j], i);
                int p2 = tsearch(a[i], j);
                //printf("%d %d %d %d\n", i, j, bsearch(a[j], i), tsearch(a[i], j));
                ans += p1 * p2;
            }
        }
        printf("%lld\n", ans);
        for (int i = 1; i <= n; i++) pos[i].clear();
    }

    return 0;
}