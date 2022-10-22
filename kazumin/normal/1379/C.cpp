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

const int MN = 100005;

int n, m, val[MN], psa[MN];
pii a[MN];

int bsearch(int key) {
    int lo = 1, hi = m + 1, mid;
    while (lo < hi) {
        mid = (lo + hi) >> 1;
        if (val[mid] > key) hi = mid;
        else lo = mid + 1;
    }
    return lo;
}

int bsearch2(int key) {
    int lo = 1, hi = m + 1, mid;
    while (lo < hi) {
        mid = (lo + hi) >> 1;
        if (val[mid] >= key) hi = mid;
        else lo = mid + 1;
    }
    return lo;
}

int32_t main() {
    boost();

    int t;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        for (int i = 1; i <= m; i++) {
            cin >> a[i].f >> a[i].s;
            val[i] = a[i].f;
        }
        sort(val + 1, val + m + 1);
        for (int i = 1; i <= m; i++) psa[i] = val[i] + psa[i - 1];
        int ans = 0;
        for (int i = 1; i <= m; i++) {
            int cnt = a[i].f + (n - 1) * a[i].s;
            int idx = bsearch(a[i].s); //up to here, optimal;
            idx = max(idx, 2ll);
            idx = max(idx, m - (n - 1) + 1);
            int num = m - idx + 1;
            cnt -= num * a[i].s;
            cnt += psa[m] - psa[idx - 1];
            int pos = bsearch2(a[i].f);
            if (pos >= idx) cnt -= val[pos], cnt += max(a[i].s, val[idx - 1]);
            ans = max(ans, cnt);
        }
        printf("%lld\n", ans);
    }

    return 0;
}