#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define ld long double
#define pii pair<int, int>
#define f first
#define s second
#define boost() cin.tie(0), cin.sync_with_stdio(0)

const int MN = 100005;

int t, n, m, x, a[MN], ans[MN], h[MN];

int32_t main() {
    boost();

    cin >> t;
    while (t--) {
        cin >> n >> m >> x;
        int sum = 0;
        vector<pii> v;
        for (int i = 1; i <= n; i++) {
            cin >> a[i], sum += a[i];
            v.push_back({a[i], i});
        }
        sort(v.begin(), v.end(), greater<>());
        priority_queue<pii, vector<pii>, greater<>> q;
        for (int i = 1; i <= m; i++) q.push({0, i});
        for (pii p : v) {
            pii cur = q.top(); q.pop();
            h[cur.s] += p.f;
            ans[p.s] = cur.s;
            q.push({h[cur.s], cur.s});
        }
        sort(h + 1, h + m + 1);
        assert(h[m] - h[1] <= x);
        printf("YES\n");
        for (int i = 1; i <= n; i++) {
            printf("%lld ", ans[i]);
            ans[i] = h[i] = 0;
        }
        printf("\n");
    }

    return 0;
}