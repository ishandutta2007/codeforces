#include<iostream>
#include<cstring>
#include<cstdio>
#define ll long long
using namespace std;
const int P = 1e9+7;
const int N = 2005;
ll dp[N][N][2][2];
ll fac[N], inv[N];
ll ans[N];
int n, m;

inline ll C(int n,int m) {
    return fac[n] * inv[m] % P * inv[n-m] % P;
}

int main() {
    cin >> n >> m; fac[0] = inv[0] = inv[1] = 1;
    dp[1][1][0][1] = dp[1][0][0][0] = 1;
    for (int i = 2;i <= n; i++) inv[i] = (P - P/i) * inv[P%i] % P;
    for (int i = 1;i <= n; i++) {
        fac[i] = fac[i-1] * i % P;
        inv[i] = inv[i-1] * inv[i] % P;
    }
    for (int i = 2;i < n; i++) {
        dp[i][0][0][0] = 1;
        for (int j = 1;j <= i; j++) {
            dp[i][j][0][0] = (dp[i-1][j-1][0][0] + dp[i-1][j][0][0] + dp[i-1][j][1][0]) % P;
            dp[i][j][1][0] = (dp[i-1][j-1][0][1] + dp[i-1][j][0][1] + dp[i-1][j][1][1]) % P;
            dp[i][j][0][1] = (dp[i-1][j-1][0][0] + dp[i-1][j-1][1][0]) % P;
            dp[i][j][1][1] = (dp[i-1][j-1][0][1] + dp[i-1][j-1][1][1]) % P;
        }
    }
    dp[n][0][0][0] = 1;
    for (int j = 1;j <= n; j++){
        dp[n][j][0][0] = (dp[n-1][j-1][0][0] + dp[n-1][j][0][0] + dp[n-1][j][1][0]) % P;
        dp[n][j][1][0] = (dp[n-1][j-1][0][1] + dp[n-1][j][0][1] + dp[n-1][j][1][1]) % P;
    }
    for (int i = 0;i <= n; i++) {
        ans[i] = (dp[n][i][0][0] + dp[n][i][1][0]) % P;
        ans[i] = ans[i] * fac[n-i] % P;
    }
    for (int i = m + 1;i <= n; i++) {
    	ans[i] = ans[i] * C(i, m) % P; 
        if ((i - m) & 1) ans[m] = (ans[m] + P - ans[i]) % P;
        else ans[m] = (ans[m] + ans[i]) % P;
    }
    cout << ans[m] << endl;
    return 0;
}