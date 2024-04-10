#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mxn = 200005;
vector<int> adj[mxn];
pair<int,int> dp[mxn];//use this node
pair<int,int> dp2[mxn];// don't use this node
//(# of nodes, sum of deg)
vector<vector<int>>vals(mxn);
vector<vector<int>>vals2(mxn);
vector<vector<int>>nodes(mxn);
vector<bool>used(mxn);
int n;
void dfs(int u, int p){
    for(int nxt: adj[u]){
        if(nxt==p)continue;
        dfs(nxt,u);
        nodes[u].push_back(nxt);
    }
    dp[u].first = 1; dp[u].second = -1*(int)adj[u].size();
    for(int nxt: nodes[u]){
        vals[u].push_back(1);
        dp[u].first+=dp2[nxt].first;
        dp[u].second+=dp2[nxt].second;
    }
    for(int nxt: nodes[u]){
        if(dp[nxt]>dp2[nxt]){
            vals2[u].push_back(0);
            dp2[u].first+=dp[nxt].first;
            dp2[u].second+=dp[nxt].second;
        }
        else{
            vals2[u].push_back(1);
            dp2[u].first+=dp2[nxt].first;
            dp2[u].second+=dp2[nxt].second;
        }
    }
}
void dfs(int u, int t, int p){
    if(t==0){
        used[u] = true;
        for(int i = 0; i<nodes[u].size(); i++){
            dfs(nodes[u][i],vals[u][i],u);
        }
    }
    else{
        for(int i = 0; i<nodes[u].size(); i++){
            dfs(nodes[u][i],vals2[u][i],u);
        }
    }
}
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n;
    for(int i = 1; i<n; i++){
        int x,y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    if(n==2){
        cout << "2 2\n";
        cout << "1 1\n";
        return 0;
    }
    dfs(1,0);
    if(dp[1]>dp2[1]){
        dfs(1,0,0);
        cout << dp[1].first << " " << -1*dp[1].second +n-dp[1].first << "\n";
        for(int i = 1; i<=n; i++){
            if(used[i])cout << adj[i].size() << " ";
            else cout << "1 ";
        }
        cout << "\n";
    }
    else{
        dfs(1,1,0);
        cout << dp2[1].first << " " << -1*dp2[1].second+n-dp2[1].first << "\n";
        for(int i = 1; i<=n; i++){
            if(used[i]){
                cout << adj[i].size() << " ";
            }
            else{
                cout << "1 ";
            }
        }
        cout << "\n";
    }
    return 0;
}