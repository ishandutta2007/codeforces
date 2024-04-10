#include <cstdio>
#include <numeric>
#include <algorithm>
#include <cstdlib>
using namespace std;
constexpr int m = 1000000007;
int dp[5001][5001];
auto addmod = [](int a, int b) { return (a + b) % m; };
int main(){
    int n, a, b, k;
    scanf("%d %d %d %d", &n, &a, &b, &k);
    for(int i = 1; i <= n; i++)
        dp[0][i] = 1;
    partial_sum(dp[0], dp[0] + n + 1, dp[0], addmod);
    for(int i = 1; i <= k; i++) {
        for(int j = 1; j <= n; j++) {
            dp[i][j] = ((dp[i - 1][min(n, j + abs(j - b) - 1)] - dp[i - 1][j] + m) % m +
                        (dp[i - 1][j - 1] - dp[i - 1][max(0, j - abs(j - b))] + m) % m) % m;
        }
        partial_sum(dp[i], dp[i] + n + 1, dp[i], addmod);
    }
    printf("%d\n", (dp[k][a] - dp[k][a - 1] + m) % m);
}