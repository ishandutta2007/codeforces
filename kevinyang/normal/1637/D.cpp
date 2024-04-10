#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int>a(n+1);
        vector<int>b(n+1);
        for(int i = 1; i<=n; i++){
            cin >> a[i];
        }
        for(int i = 1; i<=n; i++){
            cin >> b[i];
        }
        vector<vector<bool>>dp(n+1,vector<bool>(10005));
        dp[0][0] = true;
        for(int i = 1; i<=n; i++){
            for(int j = a[i]; j<=10000; j++){
                if(dp[i-1][j-a[i]]){
                    dp[i][j] = true;
                }
            }
            for(int j = b[i]; j<=10000; j++){
                if(dp[i-1][j-b[i]]){
                    dp[i][j] = true;
                }
            }
        }
        int sum = 0;
        for(int i = 1; i<=n; i++){
            sum+=a[i]+b[i];
        }
        int mx = 0;
        for(int j = 0; j<=10000; j++){
            if(j*2<=sum&&dp[n][j]){
                mx = j;
            }
        }
        int ans = mx*mx+(sum-mx)*(sum-mx);
        for(int i = 1; i<=n; i++){
            ans+=(n-2)*a[i]*a[i];
            ans+=(n-2)*b[i]*b[i];
        }
        cout << ans << "\n";
    }
    return 0;
}