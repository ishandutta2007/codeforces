#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;

const ll INF = 1e18 + 1e16;

vector<int> a;
int n, m;

ll solve(int g) {
    vector<vector<int>> b(g);
    for (int i = 0; i < n; ++i) {
        b[i % g].push_back(a[i]);
    }
    ll ans = 0;
    for (int i = 0; i < g; ++i) {
        int howmany = 0;
        ll mn = INF;
        ll sum = 0;
        for (int j = 0; j < b[i].size(); ++j) {
            sum += abs(b[i][j]);
            if (b[i][j] < 0)
                howmany ^= 1;
            mn = min<ll>(mn, abs(b[i][j]));
        }
        if (howmany) {
            ans += sum - 2 * mn;
        } else {
            ans += sum;
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        a.clear();
        a.resize(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        int g = 0;
        for (int i = 0; i < m; ++i) {
            int x;
            cin >> x;
            g = gcd(g, x);
        }
        ll ans = -INF;
        for (int j = 0; j < 2; ++j) {
            for (int i = 0; i < g; ++i) {
                a[i] = -a[i];
            }
            ans = max(ans, solve(g));
        }
        cout << ans << "\n";
    }
// 1 2 -3 4 -5 -6 7 -8 9 -10
}