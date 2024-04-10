#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n, k;  cin >> n >> k;
    string s;  cin >> s;
    int dp[n+1][3][3];
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            dp[0][i][j] = 0;
        }
    }
    for (int c = 0; c < n; c++){
        for (int i = 0; i < 3; i++){
            for (int j = 0; j < 3; j++){
                dp[c+1][i][j] = dp[c][i][j];
            }
        }
        if (s[c] == 'R') dp[c+1][0][c%3] ++;
        if (s[c] == 'G') dp[c+1][1][c%3] ++;
        if (s[c] == 'B') dp[c+1][2][c%3] ++;
    }
    int ans = INT_MAX;
    for (int i = k; i <= n; i++){
        int c = 0;
        for (int j = 0; j < 3; j ++){
            int x = dp[i][0][j%3]+dp[i][1][(j+1)%3]+dp[i][2][(j+2)%3];
            int y = dp[i-k][0][j%3]+dp[i-k][1][(j+1)%3]+dp[i-k][2][(j+2)%3];
            c = max(c, x-y);
        }
        ans = min(ans, k-c);
    }
    cout << ans << endl;
}

int main(){
    int q;
    cin >> q;
    while(q--) solve();
    return 0;
}