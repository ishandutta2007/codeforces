#include <bits/stdc++.h>
using namespace std;

const int M = 20;
const long long INF = 1E18 + 7;

int n, m, cnt[M][M];
long long dp[1 << M];
string s;

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> m >> s;
    for (int i = 1; i < n; i++) {
        cnt[s[i - 1] - 'a'][s[i] - 'a']++;
        cnt[s[i] - 'a'][s[i - 1] - 'a']++;
    }
    for (int msk = 1; msk < (1 << m); msk++) {
        dp[msk] = INF;
        int cur = __builtin_popcount(msk);
        for (int i = 0; i < m; i++) {
            if (msk >> i & 1) {
                long long tmp = dp[msk ^ (1 << i)];
                for (int j = 0; j < m; j++) {
                    if (i == j) {
                        continue;
                    } else if (msk >> j & 1) {
                        tmp += 1LL * cur * cnt[i][j];
                    } else {
                        tmp -= 1LL * cur * cnt[i][j];
                    }
                }
                dp[msk] = min(dp[msk], tmp);
            }
        }
    }
    cout <<  dp[(1 << m) - 1];
}