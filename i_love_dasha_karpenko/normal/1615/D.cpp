#pragma GCC Optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define endl '\n'
#define all(var) var.begin(),var.end()
#define mp make_pair
#define gi(x) int(x-'0')

const int N = 2e5+7;
vector<pair<int,int> > G[N],R[N];
int col[N],CL[N],ans[N];
pair<int,int> edg[N];
bool vis[N];
bool flag = 0;
void paint(int v){
    for(auto [to,cl]:R[v]){
        if (flag)
            return;
        if (CL[to]==-1) {
            CL[to] = CL[v]^cl;
            paint(to);
        }
        if (CL[to]!=CL[v]^cl)
            flag = 1;

    }
}
void dfs(int v,int par){
    for(auto [to,ind]:G[v]){
        if (to==par)
            continue;
        if (!vis[ind])
            ans[ind] = CL[to]^CL[v];
        dfs(to,v);
    }
}
void solve() {
    int n,m;
    cin>>n>>m;
    flag = 0;
    for(int i = 1;i<=n;++i)
        G[i].clear(),R[i].clear(),CL[i] = -1,vis[i] = 0;

    for(int i = 1;i<n;++i){
        int a,b;
        cin>>a>>b>>col[i];
        edg[i] = mp(a,b);
        if (col[i]!=-1) {
            vis[i] = 1;
            ans[i] = col[i];
            col[i] = __builtin_popcount(col[i]) & 1;
        }
        G[a].push_back({b,i});
        G[b].push_back({a,i});
        if (col[i]!=-1) {
            R[a].push_back({b, col[i]});
            R[b].push_back({a, col[i]});
        }
    }

    for(int i = 1;i<=m;++i){
        int x,y,val;
        cin>>x>>y>>val;
        R[x].push_back({y,val});
        R[y].push_back({x,val});
    }
    for(int i = 1;i<=n;++i){
        if (CL[i]==-1){
            CL[i] = 0;
            paint(i);
        }
    }
    if (flag){
        cout<<"NO\n";
        return;
    }
    cout<<"YES\n";
    dfs(1,1);
    for(int i = 1;i<n;++i)
        cout<<edg[i].first<<' '<<edg[i].second<<' '<<ans[i]<<'\n';
    //cout<<endl;
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1;
    cin>>t;

    while(t--)
        solve();
}