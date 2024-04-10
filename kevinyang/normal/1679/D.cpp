#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int n,m,k;
    cin >> n >> m >> k;
    vector<int>a(n+1);
    for(int i = 1; i<=n; i++){
        cin >> a[i];
    }
    vector<vector<int>>adj(n+1);
    for(int i = 0; i<m; i++){
        int x,y;
        cin >> x >> y;
        adj[x].push_back(y);
    }
    int low = 0; int high = (int)1e18; high+=5; int mid = (low+high)/2;
    while(low+1<high){
        vector<bool>good(n+1);
        bool f = false;
        for(int i = 1; i<=n; i++){
            if(a[i]<=mid){
                good[i] = true;
                f = true;
            }
        }
        vector<int>deg(n+1);
        vector<vector<int>>g(n+1);
        for(int i = 1; i<=n; i++){
            for(int nxt: adj[i]){
                if(good[i]&&good[nxt]){
                    g[i].push_back(nxt);
                    deg[nxt]++;
                }
            }
        }
        queue<int>q;
        vector<bool>vis(n+1);
        vector<int>dp(n+1);
        for(int i = 1; i<=n; i++){
            if(deg[i]==0){
                q.push(i);
                vis[i] = true;
            }
        }
        while(q.size()){
            int cur = q.front(); q.pop();
            for(int nxt: g[cur]){
                deg[nxt]--;
                dp[nxt] = max(dp[cur]+1,dp[nxt]);
                if(deg[nxt]==0){
                    vis[nxt] = true;
                    q.push(nxt);
                }
            }
        }
        int ans = 0;
        for(int i = 1; i<=n; i++){
            if(!vis[i])ans = (int)2e18;
            ans = max(ans,dp[i]+1);
        }
        if(ans>=k&&f){
            high = mid;
        }
        else{
            low = mid;
        }
        mid = (low+high)/2;
    }
    if(high>(int)2e9){
        cout << "-1\n";
    }
    else{
        cout << high << "\n";
    }
    return 0;
}