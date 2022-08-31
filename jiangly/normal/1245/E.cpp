#include <bits/stdc++.h>
using namespace std;
constexpr int N = 10;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int a[N][N], id[N][N];
    int to[N * N];
    double dp[N * N] = {};
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            cin >> a[i][j];
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            id[i][j] = 99 - 10 * i - (i % 2 == 0 ? j : 9 - j);
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            to[id[i][j]] = id[i - a[i][j]][j];
    for (int i = N * N - 2; i >= 0; --i) {
        int cnt = 6;
        dp[i] = 6;
        for (int j = 1; j <= 6; ++j) {
            if (i + j >= N * N) {
                --cnt;
            } else {
                dp[i] += min(dp[i + j], dp[to[i + j]]);
            }
        }
        dp[i] /= cnt;
    }
    cout << setprecision(10) << fixed << dp[0] << "\n";
    return 0;
}