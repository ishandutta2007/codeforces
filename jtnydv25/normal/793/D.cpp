#include <bits/stdc++.h>
using namespace std;
#define sd(x) scanf("%d", &(x))
const int N = 85;
int dp[N][N][N];
int w[N][N];
const int inf = 1e9;
int main(){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            w[i][j] = inf;
            for(int k = 0; k < N; k++) dp[i][j][k] = inf;
        }
    }
    int n, m, k;
    sd(n), sd(k); sd(m);
    for(int i = 1; i <= m; i++){
        int u, v, c;
        sd(u), sd(v); sd(c);
        w[u][v] = min(w[u][v], c);
    }
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++) dp[i][j][1] = 0;
    for(int diff = 1; diff <= n; diff++){
        for(int i = 1; i <= n; i++){
            for(int j = 2; j <= k; j++){
                if(i + diff <= n){
                    for(int r = i + 1; r <= i + diff; r++){
                        dp[i][i + diff][j] = min(dp[i][i + diff][j], 
                            w[i][r] + min(dp[r][i + 1][j - 1], dp[r][i + diff][j - 1]));
                    }
                }
                if(i - diff >= 1){
                    for(int r = i - 1; r >= i - diff; r--){
                        dp[i][i - diff][j] = min(dp[i][i - diff][j],
                            w[i][r] + min(dp[r][i - 1][j - 1], dp[r][i - diff][j - 1]));
                    }
                }
            }
        }
    }
    int ans = inf;
    for(int i = 1; i <= n; i++){
        ans = min(ans, dp[i][n][k]);
        ans = min(ans, dp[i][1][k]);
    }
    if(ans == inf) ans = -1;
    printf("%d\n", ans);    
}