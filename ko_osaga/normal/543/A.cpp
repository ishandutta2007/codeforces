#include <cstdio>

int n,m,b,mod;
int a[505];

int dp[2][505][505];


int main(){
    scanf("%d %d %d %d",&n,&m,&b,&mod);
    for (int i=1; i<=n; i++) {
        scanf("%d",&a[i]);
    }
    for (int i=0; i<=b; i++) {
        dp[0][0][i] = 1;
    }
    for (int i=1; i<=n; i++) {
        for (int j=0; j<=m; j++) {
            for (int k=0; k<=b; k++) {
                dp[i%2][j][k] = dp[(i-1)%2][j][k];
                if(j && k >= a[i]) dp[i%2][j][k] += dp[i%2][j-1][k - a[i]];
                dp[i%2][j][k] %= mod;
            }
        }
    }
    printf("%d",dp[n%2][m][b]);
}