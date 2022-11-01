//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;
#define endl '\n'
typedef long long ll;
typedef long double ld;
const int N = 2E5+7;
const int MX_BIT = 20;
const int SZ = 1<<MX_BIT;
vector<int> G[N];
ll ans[N];
int tin[SZ],cnt[SZ],timer = 0,vis[N],sz[N],A[N];
void calcsz(int v,int par){
    sz[v] = 1;
    for(int to:G[v]){
        if (to==par || vis[to])
            continue;
        calcsz(to,v);
        sz[v]+=sz[to];
    }
}
void add(int mask,int val){
    if (tin[mask]!=timer){
        tin[mask] = timer;
        cnt[mask] = 0;
    }
    cnt[mask]+=val;
}
int get(int mask){
    if (tin[mask]!=timer){
        tin[mask] = timer;
        cnt[mask] = 0;
    }
    return cnt[mask];
}
ll dfs1(int v,int par,int mask){
    mask^=A[v];
    ll res = get(mask);
    for(int bit = 0;bit<MX_BIT;++bit){
        res += get(mask^(1<<bit));
    }
    for(int to:G[v]){
        if (vis[to] || to==par)
            continue;
        res+=dfs1(to,v,mask);
    }
    ans[v]+=res;
    return res;

}
void dfs2(int v,int par,int mask){
    mask^=A[v];
    add(mask,1);
    for(int to:G[v]){
        if (vis[to] || to==par)
            continue;
        dfs2(to,v,mask);
    }
}
void solve(int v){
    calcsz(v,v);
    int total = sz[v];
    int nxt = v,prev = v;
    while(nxt!=-1){
        prev = v;
        v = nxt;
        nxt = -1;
        for(int to:G[v]){
            if (!vis[to] && to!=prev && sz[to]*2>total){
                nxt = to;
                break;
            }
        }
    }
    ++timer;
    add(0,1);
    for(int to:G[v]){
        if (vis[to])
            continue;
        ans[v]+=dfs1(to,v,A[v]);
        dfs2(to,v,0);
    }
    ++timer;
    reverse(G[v].begin(),G[v].end());
    for(int to:G[v]){
        if (vis[to])
            continue;
        dfs1(to,v,A[v]);
        dfs2(to,v,0);
    }
    vis[v] = 1;
    for(int to:G[v]){
        if (vis[to]==0)
            solve(to);
    }
}
void solve(){
    int n;
    cin>>n;
    for(int i = 1;i<n;++i){
        int u,v;
        cin>>u>>v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    for(int i = 1;i<=n;++i){
        char ch;
        cin>>ch;
        A[i] = 1<<int(ch-'a');
    }
    solve(1);
    for(int i = 1;i<=n;++i)
        cout<<ans[i]+1<<' ';
    cout<<endl;

}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);

    int t;
    t = 1;
    //cin>>t;
    while(t--)
        solve();
    return 0;
}