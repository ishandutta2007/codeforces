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
#define rep(i,a,b)  for(int i=a;i<b;i++)
using namespace std;
vi ad[200005],v[200005];
vi revad[200005];
stack<int>stk;
int comp[200005],vis[200005],x[200005];
void dfs(int u){
    if(vis[u])return;
    vis[u]=1;
    for(auto i:ad[u]){
        dfs(i);
    }
    stk.push(u);
}
void revdfs(int u,int curcomp){
    if(vis[u])return;
    vis[u]=1;
    comp[u]=curcomp;
    for(auto i:revad[u]){
        revdfs(i,curcomp);
    }
}
void solve(){
    int n,m;
    cin>>n>>m;
    rep(i,1,n+1){
        cin>>x[i];
    }
    rep(i,0,m){
        int h;
        cin>>h;
        rep(_,0,h){
            int g;
            cin>>g;
            v[g].pb(i);
        }
    }
    rep(g,1,n+1){
        if(x[g]){
            ad[v[g][0]].pb(v[g][1]);
            ad[v[g][1]].pb(v[g][0]);
            ad[v[g][0]+m].pb(v[g][1]+m);
            ad[v[g][1]+m].pb(v[g][0]+m);
            revad[v[g][1]].pb(v[g][0]);
            revad[v[g][0]].pb(v[g][1]);
            revad[v[g][0]+m].pb(v[g][1]+m);
            revad[v[g][1]+m].pb(v[g][0]+m);
        }
        else{
            ad[v[g][0]].pb(v[g][1]+m);
            ad[v[g][1]].pb(v[g][0]+m);
            ad[v[g][0]+m].pb(v[g][1]);
            ad[v[g][1]+m].pb(v[g][0]);
            revad[v[g][1]+m].pb(v[g][0]);
            revad[v[g][0]+m].pb(v[g][1]);
            revad[v[g][0]].pb(v[g][1]+m);
            revad[v[g][1]].pb(v[g][0]+m);
        }
    }
    rep(i,0,2*m){
        if(!vis[i]){
            dfs(i);
        }
    }
    memset(vis,0,sizeof vis);
    int curcomp=1;
    while(!stk.empty()){
        int cur=stk.top();
        stk.pop();
        if(!vis[cur]){
            revdfs(cur,curcomp);
            curcomp++;
        }
    }
    rep(i,0,m){
        if(comp[i]==comp[i+m]){
            cout<<"NO";
            return;
        }
    }
    cout<<"YES";
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}