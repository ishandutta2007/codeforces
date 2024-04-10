#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define ld long double
#define pii pair<int, int>
#define f first
#define s second
#define boost() cin.tie(0), cin.sync_with_stdio(0)

const int MN = 200005;

int t, n, m, a[MN];

int32_t main() {
    boost();

    cin >> t;
    while (t--) {
        cin >> n >> m;
        for (int i = 1; i <= m; i++) cin >> a[i];
        sort(a + 1, a + m + 1);
        vector<int> v;
        for (int i = 1; i < m; i++) v.push_back(a[i + 1] - a[i] - 1);
        v.push_back(a[1] + n - a[m] - 1);
        sort(v.begin(), v.end(), greater<>());
        int ans = 0;
        for (int i = 0; i < v.size(); i++) {
            int sz = v[i] - i * 4;
            //printf("%lld %lld\n", v[i], i * 2);
            if (sz <= 0) break;
            if (sz == 1) ans += sz;
            else ans += sz - 1;
        }
        printf("%lld\n", n - ans);
    }

    return 0;
}