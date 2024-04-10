#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 6000;
char s[maxn], t[maxn];
int dp[maxn][maxn];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m, ans = 0;
    cin >> n >> m >> (s + 1) >> (t + 1);
    for(int i = 1; i <= n; i += 1)
        for(int j = 1; j <= m; j += 1){
            dp[i][j] = max({dp[i - 1][j] - 1, dp[i][j - 1] - 1, 0});
            if(s[i] == t[j]) dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 2);
            //cout << i << " " << j << " " << dp[i][j] << "\n";
            ans = max(ans, dp[i][j]);
        }
    cout << ans;
    return 0;
}