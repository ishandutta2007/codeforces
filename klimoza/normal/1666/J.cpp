#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <stack>
#include <queue>
#include <string>
#include <cmath>
#include <map>
#include <random>
#include <chrono>
#include <fstream>
#include <array>
#include <iomanip>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <sstream> 
#include <utility>
#include <functional>
#include <bitset>
#include <cassert>

using namespace std;
using ll = long long;
using ld = long double;

// #define int long long

#define pii pair<int, int>
#define vi vector<int>
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define mp make_pair

const ld eps = 1e-8;
// const ll mod = 998244353;
const ll mod = 1e9 + 7;
const int MAXN = 3e5;
const int inf0 = 1e9 + 10;
const ll inf = 2e18 + 10;

void solve();

signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    cout << fixed;
    cout.precision(15);
    solve();
    return 0;
}

const int N = 207;
int n;

ll dp[N][N];
ll f[N];
ll a[N][N];
ll pref[N][N];
ll seg_fun[N][N];
int p[N][N];

ll sum(int x1, int y1, int x2, int y2) {
    return pref[x2 + 1][y2 + 1] - pref[x1][y2 + 1] - pref[x2 + 1][y1] + pref[x1][y1];
}

ll sum(int l, int r) {
    return sum(l, 0, r, n - 1);
}

ll out_sum(int l, int r) {
    return sum(l, r) - sum(l, l, r, r);
}

int par[N];

void rec(int l, int r, int pr = -1) {
    if(r < l) return;
    if(l == r)
        par[l] = pr;
    else {
        int m = p[l][r];
        par[m] = pr;
        rec(l, m - 1, m);
        rec(m + 1, r, m);
    }
}

void solve() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        f[i] = 0;
        for(int j = 0; j < n; j++) {
            cin >> a[i][j];
            f[i] += a[i][j];
        }
    }

    for(int i = 0; i <= n; i++)
        pref[0][i] = pref[i][0] = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) 
            pref[i][j] = pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1] + a[i - 1][j - 1];
    }

    for(int ln = 1; ln <= n; ln++) {
        for(int l = 0; l + ln - 1 < n; l++) {
            int r = l + ln - 1;
            if(ln == 1) 
                dp[l][r] = 0;
            else {
                dp[l][r] = inf;
                for(int v = l; v <= r; v++) {
                    if(v == l) {
                        ll t = dp[l + 1][r] + out_sum(l + 1, r);
                        if(t < dp[l][r]) {
                            dp[l][r] = t;
                            p[l][r] = v;
                        }
                    }
                    else if(v == r) {
                        ll t = dp[l][r - 1] + out_sum(l, r - 1);
                        if(t < dp[l][r]) {
                            dp[l][r] = t;
                            p[l][r] = v;
                        }
                    }
                    else {
                        ll t = dp[l][v - 1] + dp[v + 1][r] + out_sum(l, v - 1) + out_sum(v + 1, r);
                        if(t < dp[l][r]) {
                            dp[l][r] = t;
                            p[l][r] = v;
                        }
                    }
                }
            }
        }
    }
    rec(0, n - 1);
    for(int i = 0; i < n; i++)
        cout << par[i] + 1 << " ";
}