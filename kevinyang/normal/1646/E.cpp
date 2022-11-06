#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int n,m;
    cin >> n >> m;
    vector<int>dp(21);
    dp[1] = m;
    int cur = m;
    for(int i = 2; i<=20; i++){
        for(int j = 1; j<=m; j++){
            bool f = false;
            for(int k = 1; k<i; k++){
                if(i*j%k==0&&i*j/k<=m)f = true;
                if(f)break;
            }
            if(!f)cur++;
        }
        dp[i] = cur;
    }
    int ans = 1;
    vector<bool>vis(n+1);
    for(int i = 2; i<=n; i++){
        if(vis[i])continue;
        int cnt = 0;
        for(int j = i; j<=n; j*=i){
            cnt++;
            vis[j] = true;
        }
        ans+=dp[cnt];
    }
    cout << ans << "\n";
    return 0;
}