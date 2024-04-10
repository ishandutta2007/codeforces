#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    int dp[6] = {0, 0, 0, 0, 0, 0};// 4s 8s 15s 16s 23s 42s
    int ans = 0, t;
    for (int i = 0; i < n; i++){
        cin >> t;
        if (t == 4) dp[0] ++;
        if (t == 8){
            if (dp[0] > dp[1]) dp[1] ++;
            else ans ++;
        }if (t == 15){
            if (dp[1] > dp[2]) dp[2] ++;
            else ans ++;
        }if (t == 16){
            if (dp[2] > dp[3]) dp[3] ++;
            else ans ++;
        }if (t == 23){
            if (dp[3] > dp[4]) dp[4] ++;
            else ans ++;
        }if (t == 42){
            if (dp[4] > dp[5]){ 
                dp[4] --;
                dp[3] --;
                dp[2] --;
                dp[1] --;
                dp[0] --;
            }
            else ans ++;
        }
    }
    for (int i = 0; i < 6; i++) ans += dp[i];
    cout << ans;
}