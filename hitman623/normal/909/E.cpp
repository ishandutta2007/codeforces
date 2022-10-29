#include <bits/stdc++.h>

#define ll          long long
#define pb          push_back
#define pii         pair<int,int>
#define vi          vector<int>
#define vii         vector<pii>
#define mi          map<int,int>
#define mii         map<pii,int>
#define all(a)      (a).begin(),(a).end()
#define x           first
#define y           second
#define sz(x)       (int)x.size()
#define endl        '\n'
#define hell        1000000007
#define N           100000
#define rep(i,a,b)  for(int i=a;i<b;i++)
using namespace std;
int n,m,vis[100005],b[100005],cur,ans,s[100005],dp[100005];
vi a[100005];
stack<int> stk;
void dfs(int node){
    vis[node]=1;
    for(auto i:a[node]){
        if(!vis[i]) dfs(i);
    }
    stk.push(node);
}
void solve(){
    cin>>n>>m;
    rep(i,0,n){
        cin>>s[i];
    }
    rep(i,0,m){
        int x,y;
        cin>>x>>y;
        a[x].pb(y);
    }
    rep(i,0,n){
        if(!vis[i]){
            dfs(i);
        }
    }
    while(!stk.empty()){
        b[cur++]=stk.top();
        stk.pop();
    }
    for(int i=n-1;i>=0;--i){
        int d=b[i];
        dp[d]=s[d];
        for(auto j:a[d]){
            dp[d]=max(dp[d],dp[j]+(s[d]==1 and s[j]==0));
        }
    }
    rep(i,0,n){
        ans=max(ans,dp[i]);
    }
    cout<<ans<<endl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t=1;
//    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}