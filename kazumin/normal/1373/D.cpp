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

int t, n, a[MN];

int kad(vector<int> &v) {
    int n = v.size();
    int loc = 0, glo = -(1LL << 60);
    for (int i = 0; i < n; i++) {
        loc = max(v[i], v[i] + loc);
        if (loc > glo) glo = loc;
    }
    return glo;
}

int32_t main() {
    boost();

    cin >> t;
    while (t--) {
        int sum = 0;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            if (i % 2) sum += a[i];
        }
        vector<int> v, s;
        for (int i = 1; i < n; i += 2) v.push_back(a[i + 1] - a[i]);
        for (int i = 2; i < n; i += 2) s.push_back(a[i] - a[i + 1]);
        /*printf("%d\n", sum);
        for (int p : v) printf("%d ", p);
        printf("\n");
        for (int p : s) printf("%d ", p);
        printf("\n");*/
        int mx = max({0LL, kad(v), kad(s)});
        printf("%lld\n", sum + mx);
    }

    return 0;
}