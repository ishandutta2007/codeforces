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

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<int> c(n);
    for (int i = 0; i < n; i++) {
        cin >> c[i];
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
    int q;
    cin >> q;
    for (int _ = 0; _ < q; _++) {
        int x;
        cin >> x;
        vector<int> need(n);
        for (int i = 0; i < n; i++) {
            need[i] = bp[i] + x * (i + 1);
        }
        for (int i = 0; i < 100; i++) {
            for (int j = 0; j <= 10000; j++) {
                dp[i][j] = 0;
            }
        }
        for (int i = max(0LL, need[0]); i <= c[0]; i++) {
            dp[0][i] = 1;
        }
        for (int i = 1; i < n; i++) {
            for (int j = need[i]; j <= 10000; j++) {
                for (int k = 0; k <= c[i]; k++) {
                    if (j < k) {
                        break;
                    }
                    dp[i][j] += dp[i - 1][j - k];
                    if (dp[i][j] >= MOD) {
                        dp[i][j] -= MOD;
                    }
                }
            }
        }
        int ans = 0;
        for (int j = 0; j <= 10000; j++) {
            ans += dp[n - 1][j];
        }
        cout << ans % MOD;
    }
}