//#pragma GCC optimize("Ofast")
//#pragma GCC optimization("funroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
const int N = 2e5+7;
int P[N],sz[N];
int F(int x){
    return x==P[x]?x:P[x] = F(P[x]);
}
int unite(int a,int b){
    a = F(a);
    b = F(b);
    if (a==b)
        return 0;
    P[a] = b;
    sz[b]+=sz[a];
    return 1;
}
vector<int> G[N];
int vis[N],cnt[2],flag = 0;
void dfs(int v){
    cnt[vis[v]-1]+=sz[v];
    for(int to:G[v]){
        if (!vis[to]){
            vis[to] = 3-vis[v];
            dfs(to);
        }
        if(vis[to]!=3-vis[v]){
            flag = 1;
        }
    }
}
void solve(){
    int n,m;
    cin>>n>>m;
    for(int i = 1;i<=n;++i){
        P[i] = i;
        sz[i] = 1;
    }
    vector<pair<int,int> > edges;
    for(int i = 1;i<=m;++i){
        int a,b;
        string s;
        cin>>a>>b>>s;
        if (s=="crewmate"){
            unite(a,b);
        }
        else{
            edges.push_back({a,b});
        }
    }
    for(auto [a,b]:edges){
        a = F(a);
        b = F(b);
        G[a].push_back(b);
        G[b].push_back(a);
    }
    int res = 0;
    for(int i = 1;i<=n;++i){
        if (i!=F(i))
            continue;
        if (!vis[i]){
            cnt[0] = cnt[1] = 0;
            vis[i] = 1;
            dfs(i);
            res+=max(cnt[0],cnt[1]);
        }
    }
    if (flag){
        cout<<"-1\n";
    }
    else{
        cout<<res<<endl;
    }
    flag = 0;
    for(int i = 1;i<=n;++i){
        G[i].clear();
        vis[i] = 0;
    }
}
signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t;
    cin>>t;
    while(t--)
        solve();
    return 0;
}