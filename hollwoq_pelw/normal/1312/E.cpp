#include <bits/stdc++.h>
using namespace std;
#define int long long

int a[505], dp[505], join[505][505];

signed main(){
    int n; cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        dp[i] = 1e18;
    }
    for (int d = 0; d < n; d++){
        for (int i = 1; i + d <= n; i++){
            int j = i + d;
            if (d == 0){
                join[i][j] = a[i];
            }else{
                for (int k = i; k < j; k++){
                    if (join[i][k] && join[k+1][j] && join[i][k] == join[k+1][j]){
                        join[i][j] = join[i][k] + 1;
                        break;
                    }
                }
            }
        }
    }
    for (int i = 1; i <= n; i++){
        for (int j = 0; j < i; j++){
            if (join[j+1][i])
                dp[i] = min(dp[i], dp[j] + 1);
        }
    }
    cout << dp[n];
}