#include <cstdio>
#include <algorithm>
using namespace std;

int dp[2][1005][20010];
const int BOJ = 10001, mod = 1000000007;
int n, a;
int ans;

bool c(int x){ return !(x >= 0 && x < 20005); }

int main(){
    scanf("%d", &n);
    dp[0][0][BOJ] = 1;
    for(int i = 1; i <= n; i++){
        scanf("%d", &a);
        for(int j = -10000; j <= 10000; j++){
            dp[1][i][j + BOJ] += (c(j + a + BOJ) ? 0 : dp[1][i - 1][j + a + BOJ]) + (c(j - a + BOJ) ? 0 : dp[1][i - 1][j - a + BOJ]);
            dp[1][i][j + BOJ] %= mod;
            dp[1][i][j + BOJ] += (c(j + a + BOJ) ? 0 : dp[0][i - 1][j + a + BOJ]) + (c(j - a + BOJ) ? 0 : dp[0][i - 1][j - a + BOJ]);
            dp[1][i][j + BOJ] %= mod;
        }
        ans += dp[1][i][BOJ];
        ans %= mod;
        dp[0][i][BOJ] = 1;
    }
    printf("%d", ans);
}