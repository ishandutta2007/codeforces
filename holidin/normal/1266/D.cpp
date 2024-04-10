#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second
using namespace std;
const int N = 6e5 + 1;
int bal[N];
void solve() {
    int i, j, k, n, t, a, b, c;
    cin >> n >> k;
    for (i = 0; i < k; ++i) {
        cin >> a >> b >> c;
        bal[a] -= c;
        bal[b] += c;
    }
    j = 1;
    vector <pair<pair<int, int>, int> > v;
    for (i = 1; i <= n; ++i)
    while (bal[i] < 0) {
        while (bal[j] <= 0)
            ++j;
        while (bal[j] > 0 && bal[i] < 0) {
            int c = min(-bal[i], bal[j]);
            v.push_back({{i, j}, c});
            bal[i] += c;
            bal[j] -= c;
        }
    }
    cout << v.size() << "\n";
    for (i = 0; i < v.size(); ++i)
        cout << v[i].fi.fi << ' ' << v[i].fi.se << ' ' << v[i].se << "\n";
}

signed main() {
    #ifdef local
        freopen("input.txt", "r", stdin);
    #endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    solve();
}