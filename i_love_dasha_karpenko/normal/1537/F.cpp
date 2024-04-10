//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
const int N = 2E5+7;
int A[N],flag = 0,vis[N];
vector<int> G[N];
void dfs(int v){
    for(int to:G[v]){
        if (vis[to]==0) {
            vis[to] = 3-vis[v];
            dfs(to);
        }
        else if (vis[to]!=3-vis[v])
            flag = 1;
    }
}
void solve(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i = 1;i<=n;++i)
        cin>>A[i];
    for(int i = 1;i<=n;++i){
        int x = A[i];
        cin>>A[i];
        A[i]-=x;
        vis[i] = 0;
    }
    for(int i = 1;i<=m;++i){
        int u,v;
        cin>>u>>v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    flag = 0;
    vis[1] = 1;
    dfs(1);
    if (flag){
        int cnt = 0;
        for(int i = 1;i<=n;++i)
            cnt^=(abs(A[i])&1);
        if (cnt==0)
            cout<<"YES\n";
        else cout<<"NO\n";
    }
    else{
        ll res = 0;
        for(int i = 1;i<=n;++i){
            if (vis[i]==1)
                res+=A[i];
            else res-=A[i];
        }
        if (res==0)
            cout<<"YES\n";
        else cout<<"NO\n";
    }
    for(int i = 1;i<=n;++i)
        G[i].clear();
}

int main()
{

    ios_base::sync_with_stdio(false); cin.tie(0);
    int t;
    //t = 1;
    cin>>t;
    while(t--)
        solve();
    return 0;
}