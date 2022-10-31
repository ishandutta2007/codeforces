#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define endl '\n'
const int DIM = 4E5+7;
vector<int> G[DIM],R[DIM],NG[DIM];
vector<int> V;
int vis[DIM],need[DIM];
void topsort(int v){
    vis[v] = 1;
    for(int to:G[v]){
        if (vis[to])
            continue;
        topsort(to);
    }
    V.push_back(v);
}
int cmp_cnt,cmp[DIM],sz[DIM],head[DIM],flaged[DIM];
void cond(int v){
    cmp[v] = cmp_cnt;
    ++sz[cmp_cnt];
    head[cmp_cnt] = v;
    for(int to:R[v]){
        if (cmp[to]!=cmp[v])
            NG[cmp[to]].push_back(cmp[v]);
        if(!cmp[to])
            cond(to);
    }
}
queue<int> Q;
void dfs(int v){
    vis[v] = 1;
    if (sz[v]>1 || flaged[head[v]])
        Q.push(v);
    for(int to:NG[v]){
        if (vis[to])
            continue;
        dfs(to);
    }
}
int mark[DIM],way[DIM];
void solve(){
    int n,m;
    cin>>n>>m;
    for(int i = 1;i<=m;++i){
        int u,v;
        cin>>u>>v;
        if (u==v)
            flaged[u] = 1;
        G[u].push_back(v);
        R[v].push_back(u);
    }
    for(int i = 1;i<=n;++i){
        if (!vis[i]){
            topsort(i);
        }
    }

    reverse(V.begin(),V.end());
    for(int v:V){
        if (!cmp[v]){
            ++cmp_cnt;
            cond(v);
        }
    }
    for(int i = 1;i<=n;++i)
        vis[i] = 0;
    dfs(cmp[1]);
    for(int i = 1;i<=cmp_cnt;++i) {
        if ((sz[i]>1 || flaged[head[i]]) && vis[i])
            mark[i] = 1;
    }
    while(!Q.empty()){
        int v = Q.front();
        Q.pop();
        for(int to:NG[v]){
            if (mark[to])
                continue;
            mark[to] = 1;
            Q.push(to);
        }
    }
    for(int i = 1;i<=cmp_cnt;++i){
        if (vis[i] && !mark[i]){
            for(int to:NG[i])
                ++need[to];
        }
    }
    if (!mark[cmp[1]]){
        Q.push(cmp[1]);
        way[cmp[1]] = 1;
        while(!Q.empty()){
            int v = Q.front();
            Q.pop();
            for(int to:NG[v]){
                way[to] = min(2,way[to]+way[v]);
                --need[to];
                if (need[to]==0)
                    Q.push(to);
            }
        }
    }
    for(int i = 1;i<=n;++i){
        if (mark[cmp[i]])
            cout<<"-1 ";
        else if (vis[cmp[i]]==0)
            cout<<"0 ";
        else cout<<way[cmp[i]]<<' ';
    }
    for(int i = 1;i<=n;++i){
        way[i] = mark[i] = head[i] = sz[i] = vis[i] = cmp[i] = flaged[i] = need[i] = 0;
        G[i].clear();
        NG[i].clear();
        R[i].clear();

    }
    V.clear();
    cmp_cnt = 0;
    cout<<endl;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin>>t;
    while(t--)
        solve();
    return 0;
}