#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;

#define forn(i, a, n) for (int i = a; i < n; ++i)
#define ford(i, a, n) for (int i = n - 1; i >= a; --i)
#define fore(i, a, n) for (int i = a; i <= n; ++i)
#define all(a) (a).begin(), (a).end()
#define fs first
#define sn second
#define trace(a)\
    for (auto i : a) cerr << i << ' ';\
    cerr << '\n'
#define eb emplace_back

#ifndef M_PI
const ld M_PI = acos(-1.0);
#endif

const ld eps = 1e-9;
const int INF = 2000000000;
const ll LINF = 1ll * INF * INF;
const ll MOD = 1000000007;

vector<pair<int, int>> costs = {{20, 1}, {50, 90}, {120, 1440}};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> t(n, INF);
    vector<int> dp(n, INF);
    forn(i, 0, n) {
        cin >> t[i];
        for (auto p : costs) {
            int j = lower_bound(all(t), t[i] - p.sn + 1) - t.begin();
            int val = (j == 0 ? 0 : dp[j - 1]) + p.fs;
            dp[i] = min(dp[i], val);
        }
        cout << dp[i] - (i == 0 ? 0 : dp[i - 1]) << '\n';
    }
}