#pragma GCC_OPTIMIZE("ofast")
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

#define data NE_data
#define rank NE_rank
#define endl '\n'

#define int long long

int MOD = 998244353;
int dp[500][500];

int pow(int n, int k) {
    if (k == 0) {
        return 1;
    }
    if (k % 2 == 0) {
        return pow((n * n) % MOD, k / 2); 
    } else {
        return (n * pow(n, k - 1)) % MOD;
    }
}

int fact[501];
int obr[501];

int cc[501][501];
int c(int n, int k) {
    return (((fact[n] * obr[k]) % MOD) * obr[n - k]) % MOD;
}

void solve() {
    int n, x;
    cin >> n >> x;
    fact[0] = 1;
    for (int i = 1; i <= n; i++) {
        fact[i] = fact[i - 1] * i;
        fact[i] %= MOD;
    }
    for (int i = 0; i <= n; i++) {
        obr[i] = pow(fact[i], MOD - 2);
    }
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= i; j++) {
            cc[i][j] = c(i, j);
        }
    }
    for (int i = 0; i <= n; i++) {
        for (int j = 1; j <= x; j++) {
            if (i == 0) {
                dp[i][j] = 1;
                continue;
            }
            if (i == 1) {
                dp[i][j] = 0;
                continue;
            }

            if (j <= i - 1) {
                dp[i][j] = pow(j, i);
                continue;
            }

            for (int k = 0; k <= i; k++) {
                dp[i][j] += dp[i - k][j - i + 1] * ((pow(i - 1, k) * cc[i][k]) % MOD);
                dp[i][j] %= MOD;
            }
        }
    }
    cout << dp[n][x] << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    for (int i = 0; i < 1; i++) {
        solve();
    }
}