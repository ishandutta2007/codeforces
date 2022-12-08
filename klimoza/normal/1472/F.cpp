//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,popcnt,abm,mmx,tune=native")
//#pragma GCC target("avx2")
//#pragma GCC optimize("no-stack-protector")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC optimize("fast-math")
#define _CRT_SECURE_NO_WARNINGS
#include <math.h>
#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <complex>
#include <ctime>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

//#define int long long

#define mp(a, b) make_pair(a, b)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()

#define endl '\n'

using namespace std;
typedef long long ll;
typedef long double ld;

mt19937 mrand(random_device{}());

const double PI = acos((double)-1);
const ld eps = 1e-8;
const int inf0 = 1023 * 1024 * 1024;
const ll inf = inf0 * 1ll * inf0;
const ll mod = 1e9 + 7;
// const ll mod = 998244353;

void solve();
void scan();

signed main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    cout << fixed;
    cout.precision(15);
    solve();
    return 0;
}

void solve() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<pair<int, int>> ans;
        vector<pair<int, int>> a(m);
        for (int i = 0; i < m; i++) {
            cin >> a[i].second >> a[i].first;
            a[i].second--;
        }
        sort(all(a));
        ans.push_back(mp(0, 3));
        for (auto u : a) {
            if (u.first == ans.back().first)
                ans.back().second = 3;
            else
                ans.push_back(mp(u.first, (1 << u.second)));
        }
        ans.push_back(mp(n + 1, 3));
        n = ans.size();
        vector<vector<bool>> dp(n, vector<bool>(4, false));
        dp[0][3] = true;
        for (int i = 1; i < n; i++) {
            for (int mask1 = 0; mask1 < 4; mask1++) {
                for (int mask2 = 0; mask2 < 4; mask2++) {
                    if (!dp[i - 1][mask1])
                        continue;
                    int x = ans[i].second;
                    if (mask2 & x)
                        continue;
                    if (dp[i][mask2 ^ x])
                        continue;
                    if (mask2 == 0 || mask2 == 3) {
                        dp[i][mask2 ^ x] = (mask1 == 0 || mask1 == 3);
                    } else {
                        if (mask1 == 0 || mask1 == 3)
                            continue;
                        dp[i][mask2 ^ x] =
                            ((mask1 == mask2 &&
                              (ans[i].first - ans[i - 1].first) % 2 == 0) ||
                             (mask1 != mask2 &&
                              (ans[i].first - ans[i - 1].first) % 2 == 1));
                    }
                }
            }
        }
        bool fl = false;
        for (int i = 0; i < 4; i++) {
            if (dp[n - 1][i])
                fl = true;
        }
        if (fl)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return;
}