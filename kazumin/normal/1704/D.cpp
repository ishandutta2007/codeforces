#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define ld long double
#define pii pair<int, int>
#define f first
#define s second
#define boost() cin.tie(0), cin.sync_with_stdio(0)

const int MN = 300005;

int t, n, m, a[MN], sum[MN];

int32_t main() {
    boost();

    cin >> t;
    while (t--) {
        cin >> n >> m;
        vector<pii> v;
        for (int i = 1; i <= n; i++) {
            sum[i] = 0;
            for (int j = 1; j <= m; j++) {
                cin >> a[j];
                sum[i] += a[j] * j;
            }
            v.push_back({sum[i], i});
        }
        sort(v.begin(), v.end(), greater<>());
        printf("%lld %lld\n", v[0].s, v[0].f - v[1].f);
    }

    return 0;
}