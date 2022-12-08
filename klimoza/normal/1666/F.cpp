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
const ll mod = 998244353;
//const ll mod = 1e9 + 7;
const int MAXN = 5000 + 10;
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

int t;
int n, a[MAXN];
int cnk[MAXN][MAXN];

int sum(int x, int y) {
    x += y;
    if (x >= mod)
        x -= mod;
    return x;
}

int mul(int x, int y) {
    return x * 1ll * y % mod;
}

void precalc() {
    for (int i = 0; i < MAXN; i++) {
        cnk[i][0] = 1;
        for (int j = 1; j <= i; j++) {
            cnk[i][j] = sum(cnk[i - 1][j], cnk[i - 1][j - 1]);
        }
    }
}

// int smart(int nn, vector<int> aa) {
//     n =
// }

void solve() {
    cin >> t;
    precalc();
    while (t--) {
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        if (a[n - 2] == a[n - 1]) {
            cout << 0 << '\n';
            continue;
        }
        vi dp(n);
        dp[1] = 1;
        int group_sz = 1, processed = 1;
        for (int i = n - 3; i >= 0; i--) {
            if (a[i] != a[i + 1]) {
                vi new_dp(n);
                for (int j = n / 2; j >= 0; j--) {
                    int free_spaces = j * 2 - 1 - processed;
                    if (free_spaces >= (group_sz - 1)) {
                        new_dp[j + 1] = sum(new_dp[j + 1], mul(dp[j], cnk[free_spaces][group_sz - 1]));
                    }
                    if (j == n / 2)
                        free_spaces = n - processed;
                    if (free_spaces >= group_sz)
                        new_dp[j] = sum(new_dp[j], mul(dp[j], cnk[free_spaces][group_sz]));
                }
                for (int j = 0; j <= n / 2; j++) {
                    dp[j] = new_dp[j];
                    // if (dp[j])
                    //     cout << j << ' ' << dp[j] << endl;
                }
                processed += group_sz;
                group_sz = 1;
            } else {
                group_sz++;
            }
        }
        cout << dp[n / 2] << '\n';
    }    
}