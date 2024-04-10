#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,k;
int mxn = 100005;
vector<vector<int>>adj(mxn);
vector<int>arr(mxn);
vector<int>dp(mxn);
vector<bool>has(mxn);
int xorsum = 0;
bool ans = false;
void dfs(int u, int p){
    dp[u] = arr[u];
    for(int nxt: adj[u]){
        if(nxt==p)continue;
        dfs(nxt,u);
        dp[u]^=dp[nxt];
    }
}
void dfs1(int u, int p){
    if(dp[u]==xorsum)has[u] = true;
    int cnt = 0;
    for(int nxt: adj[u]){
        if(nxt==p)continue;
        dfs1(nxt,u);
        if(has[nxt])cnt++;
    }
    if(cnt>0)has[u] = true;
    if(dp[u]==0&&has[u]){
        //cout << "nae\n";
        ans = true;
    }
    if(cnt>=2)ans = true;
}
void reset(int n){
    ans = false;
    xorsum = 0;
    for(int i = 1; i<=n; i++){
        adj[i].clear();
        dp[i] = 0; arr[i] = 0;
        has[i] = false;
    }
}
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--){
        cin >> n >> k;
        xorsum = 0;
        for(int i = 1; i<=n; i++){
            cin >> arr[i];
            xorsum^=arr[i];
        }
        for(int i = 0; i<n-1; i++){
            int x,y;
            cin >> x >> y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        dfs(1,0);
        if(k==2&&xorsum>0){
            cout << "NO\n";
        }
        else if(xorsum==0){
            cout << "YES\n";
        }
        else if(xorsum>0){
            dfs1(1,0);
            if(ans)cout << "YES\n";
            else cout << "NO\n";
        }
        reset(n);
    }
    return 0;
}