#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

int n,a,b,k;
int mod = 1e9 + 7;

int dp[5005][5005];
int sum[5005][5005];

int main(){
    scanf("%d %d %d %d",&n,&a,&b,&k);
    for (int i=1; i<=n; i++) {
        dp[k][i] = 1;
        sum[k][i] = i;
    }
    for (int i=k-1; i>=0; i--) {
        for (int j=1; j<=n; j++) {
            int dist = abs(j-b);
            dp[i][j] = (sum[i+1][min(n+1,j+dist)-1] - sum[i+1][max(j-dist,0)] - dp[i+1][j]) % mod;
            if(dp[i][j] < 0) dp[i][j] += mod;
        }
        for (int j=1; j<=n; j++) {
            sum[i][j] = sum[i][j-1] + dp[i][j];
            sum[i][j] %= mod;
        }
    }
    printf("%d",dp[0][a]);
}