#include <unordered_map>
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <random>
#include <iomanip>
#include <clocale>
#include <bitset>
#include <string>
#include <vector>
#include <cmath>
#include <ctime>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>

using namespace std;

#define endl '\n'
#define int long long

const int MOD = 1000000007;
const int INF = 2000000000;
const int MAXN = 100000;

int dp[100][20000];


map<int, int> ans;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    int kek = 1;
    vector<int> c(n);
    for (int i = 0; i < n; i++) {
        cin >> c[i];
        kek *= (c[i] + 1);
        kek %= MOD;
    }
    vector<int> cp(n);
    for (int i = 0; i < n; i++) {
        cp[i] = c[i];
        if (i) {
            cp[i] += cp[i - 1];
        }
    }
    vector<int> b(n);
    for (int i = 1; i < n; i++) {
        cin >> b[i];
    }
    vector<int> bp(n);
    for (int i = 1; i < n; i++) {
        bp[i] = bp[i - 1] + b[i];
    }
    for (int i = 1; i < n; i++) {
        bp[i] += bp[i - 1];
    }
    int cnt = 0;
    for (int x = -100000;  x <= 100000; x++) {
        vector<int> need(n);
        bool was = false;
        bool was1 = false;
        for (int i = 0; i < n; i++) {
            need[i] = bp[i] + x * (i + 1);
            if (need[i] > cp[i]) {
                was = true;
                break;
            }
            if (need[i] > 0) {
                was1 = true;
            }
        }
        if (was) {
            ans[x] = 0;
            continue;
        }
        if (!was1) {
            ans[x] = kek;
            continue;
        }
        for (int i = 0; i < 100; i++) {
            for (int j = 0; j <= 10000; j++) {
                cnt++;
                dp[i][j] = 0;
            }
        }
        for (int i = max(0LL, need[0]); i <= c[0]; i++) {
            cnt++;
            dp[0][i] = 1;
        }
        vector<int> pref_dp(10001);
        for (int i = 1; i < n; i++) {
            for (int j = 0; j <= 10000; j++) {
                pref_dp[j] = dp[i - 1][j];
                if (j) {
                    pref_dp[j] += pref_dp[j - 1];
                }
                if (pref_dp[j] >= MOD) {
                    pref_dp[j] %= MOD;
                }
            }
            for (int j = need[i]; j <= 10000; j++) {
                int lol = min(c[i], j);
                dp[i][j] = pref_dp[j];
                if (lol != j) {
                    dp[i][j] -= pref_dp[j - lol - 1];
                    dp[i][j] += 2 * MOD;
                    if (dp[i][j] >= MOD) {
                        dp[i][j] %= MOD;
                    }
                }
                dp[i][j] %= MOD;
                /*for (int k = 0; k <= c[i]; k++) {
                    if (j < k) {
                        break;
                    }
                    cnt++;
                    dp[i][j] += dp[i - 1][j - k];
                    if (dp[i][j] >= MOD) {
                        dp[i][j] -= MOD;
                    }
                }*/
            }
        }
        int ans1 = 0;
        for (int j = 0; j <= 10000; j++) {
            cnt++;
            ans1 += dp[n - 1][j];
        }
        ans[x] = ans1 % MOD;
    }
    int q;
    cin >> q;
    for (int _ = 0; _ < q; _++) {
        int x;
        cin >> x;
        cout << ans[x] << endl;
    }
}