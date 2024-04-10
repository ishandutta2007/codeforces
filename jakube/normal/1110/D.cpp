#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (auto& x : a)
        cin >> x;
    sort(a.begin(), a.end());

    vector<int> cnt(m+2, 0);
    for (int x : a)
        cnt[x]++;
    int next_start = 1;
    int ans = 0;
    int M = 6;
    for (int i = 0; i <= m; i++) {
        if (cnt[i] >= M) {
            int c = (cnt[i] - M + 1) / 3;
            ans += c;
            cnt[i] -= 3 * c;
        }
    }
    
    vector<vector<int>> dp(M, vector<int>(M, -1'000'000));
    vector<vector<int>> dp2(M, vector<int>(M, -1'000'000));
    dp[0][0] = 0;

    for (int i = 1; i <= m; i++) {
        for (int j = 0; j < M; j++) {
            fill(dp2[j].begin(), dp2[j].end(), -1'000'000);
        }

        for (int j = 0; j < M; j++) {
            for (int k = 0; k < M; k++) {
                if (dp[j][k] < 0)
                    continue;

                int l = cnt[i];
                int mi = min(min(j, k), l);
                for (int c = 0; mi + c * 3 <= l; c++) {
                    auto& x = dp2[k - mi][l - mi - c*3];
                    x = max(x, dp[j][k] + mi + c);
                }
            }
        }
        dp.swap(dp2);
    }

    int ma = 0;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < M; j++) {
            ma = max(ma, dp[i][j]);
        }
    }
    cout << ans + ma << '\n';
}