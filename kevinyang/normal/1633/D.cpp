#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    vector<int>dp(1005,(int)1e9);
    dp[0] = 0; dp[1] = 0;
    for(int i = 1; i<=1000; i++){
        for(int j = 1; j<=i; j++){
            int v = i+i/j;
            if(v<=1000){
                dp[v] = min(dp[v],dp[i]+1);
            }
        }
    }
    int t;
    cin >> t;
    while(t--){
        int n,k;
        cin >> n >> k;
        k = min(k,n*13+5);
        vector<int>b(n+1);
        for(int i = 1; i<=n; i++){
            cin >> b[i];
            b[i] = dp[b[i]];
        }
        vector<int>c(n+1);
        for(int i = 1; i<=n; i++){
            cin >> c[i];
        }
        vector<vector<int>>d(n+1,vector<int>(k+1));
        for(int i = 1; i<=n; i++){
            for(int j = b[i]; j<=k; j++){
                d[i][j] = max(d[i][j],d[i-1][j-b[i]]+c[i]);
            }
            for(int j = 0; j<=k; j++){
                d[i][j] = max(d[i][j],d[i-1][j]);
            }
            for(int j = 1; j<=k; j++){
                d[i][j] = max(d[i][j],d[i][j-1]);
            }
        }
        cout << d[n][k] << "\n";
    }
    return 0;
}