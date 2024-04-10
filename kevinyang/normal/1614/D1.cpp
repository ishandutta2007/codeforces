#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int n;
    cin >> n;
    int mxn = (int)5e6;
    vector<int>freq(mxn+5);
    for(int i = 0; i<n; i++){
        int x;
        cin >> x;
        freq[x]++;
    }
    for(int i = 1; i<=mxn; i++){
        for(int j = i*2; j<=mxn; j+=i){
            freq[i]+=freq[j];
        }
    }
    vector<int>dp(mxn+5);
    dp[1] = n;
    int ans = n;
    for(int i = 1; i<=mxn; i++){
        for(int j = 2*i; j<=mxn; j+=i){
            dp[j] = max(dp[j],dp[i]+freq[j]*(j-i));
            ans = max(ans,dp[j]);
        }
    }
    cout << ans << "\n";
    return 0;
}