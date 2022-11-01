#include <cstdio>
#include <numeric>
#include <algorithm>
using namespace std;

int p[5000];
long long s[5001];
long long dp[5001][5001];

int main(){
    int n, m, k;
    scanf("%d %d %d", &n, &k, &m);
    for(int i = 0; i < n; i++)
        scanf("%d", p + i),
        s[i + 1] = s[i] + p[i];
    fill_n(dp[0], n + 1, 0);
    for(int i = 1; i <= m; i++) {
        for(int j = i * k; j <= n; j++) {
            dp[i][j] = max(dp[i][j - 1], dp[i - 1][j - k] + s[j] - s[j - k]);
//            printf("%I64d ", dp[i][j]);
        }
//        puts("");
    }
    printf("%I64d\n", dp[m][n]);
}