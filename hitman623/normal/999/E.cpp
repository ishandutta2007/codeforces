#include <bits/stdc++.h>

#define int         long long
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
int n,m,s,x[5005],y[5005],cur=1,ans,vis[5005],id[5005],indegree[5005];
vi a[5005],r[5005];
stack<int> stk;
void dfs1(int node){
    vis[node]=1;
    for(auto i:a[node]){
        if(!vis[i]){
            dfs1(i);
        }
    }
    stk.push(node);
}
void dfs2(int node){
    id[node]=cur;
    for(auto i:r[node]){
        if(!id[i]){
            dfs2(i);
        }
    }
}
void solve(){
    cin>>n>>m>>s;
    rep(i,0,m){
        cin>>x[i]>>y[i];
        a[x[i]].pb(y[i]);
        r[y[i]].pb(x[i]);
    }
    rep(i,1,n+1){
        if(!vis[i]){
            dfs1(i);
        }
    }
    while(!stk.empty()){
        int d=stk.top();
        stk.pop();
        if(id[d]) continue;
        dfs2(d);
        cur++;
    }
    rep(i,0,m){
        if(id[x[i]]!=id[y[i]]){
            indegree[id[y[i]]]++;
        }
    }
    rep(i,1,cur){
        if(indegree[i]==0){
            ans++;
        }
    }
    ans-=indegree[id[s]]==0;
    cout<<ans<<endl;
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