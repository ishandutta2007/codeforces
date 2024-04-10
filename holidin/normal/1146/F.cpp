#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
const int N = 1e6;
const int mod = 998244353;

long long dp[N][3];
vector <int> e[N];

int main() {
    int i, j, k, n;
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for (i = 2; i <= n; ++i) {
        cin >> j;
        e[j].push_back(i);
    }
    for (i = n; i >= 1; --i)
    if (e[i].size() == 0) {
        dp[i][0] = 0;
        dp[i][1] = 0;
        dp[i][2] = 1;
    } else {
        dp[i][0] = 1;
        dp[i][1] = e[i].size();
        long long cdp[2][3];
        for (j = 0; j < 3; ++j)
            cdp[0][j] = cdp[1][j] = 0;
        cdp[0][0] = 1;
        for (j = 0; j < e[i].size(); ++j) {
            for (int l = 0; l < 3; ++l) {
                cdp[1][l] += cdp[0][l] * (dp[e[i][j]][0] + dp[e[i][j]][2]);
                cdp[1][min(2, l + 1)] += cdp[0][l] * (dp[e[i][j]][1] + dp[e[i][j]][2]);
                cdp[0][l] = cdp[1][l] % mod;
                cdp[1][l] = 0;
            }
        }
        dp[i][0] = cdp[0][0];
        dp[i][1] = cdp[0][1];
        dp[i][2] = cdp[0][2];
    }
    cout << (dp[1][0] + dp[1][2]) % mod;
}