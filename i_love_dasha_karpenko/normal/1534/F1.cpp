#include <bits/stdc++.h>

using namespace std;
typedef long long big;
const int DIM = 4E5+7;
vector<int> G[DIM],R[DIM],NG[DIM];
int n,m,A[DIM];
int tr(int i,int j){
    return (i-1)*m+j;
}
vector<pair<int,int> > edg;
void add(int a,int b){
    G[a].push_back(b);
    R[b].push_back(a);
    edg.push_back({a,b});
}
vector<int> V;
int vis[DIM],in_cmp[DIM],cnt[DIM];
void dfs(int v){
    vis[v] = 1;
    for(int to:G[v]){
        if (!vis[to])
            dfs(to);
    }
    V.push_back(v);
}

void cond(int v,int cmp){
    vis[v] = 1;
    in_cmp[v] = cmp;
    cnt[cmp]+=A[v];
    for(int to:R[v]){
        if (!vis[to]){
            cond(to,cmp);
        }
    }
}
int mark[DIM];
void paint(int v){
    vis[v] = 1;
    for(int to:NG[v]){
        mark[to] = 1;
        if (vis[to]==0){
            paint(to);
        }
    }
}
void solve(){

    cin>>n>>m;
    for(int i = 1;i<=n;++i){
        for(int j = 1;j<=m;++j){
            char ch;
            cin>>ch;
            int cur = (ch=='#');
            if (cur && i>1)
                add(tr(i,j),tr(i-1,j));
            if (cur){
                if (j<m)
                    add(tr(i,j),tr(i,j+1));
                if (j>1)
                    add(tr(i,j),tr(i,j-1));
            }
            if (i<n)
                add(tr(i,j),tr(i+1,j));

            A[tr(i,j)] = cur;
        }
    }
    for(int i = 1;i<=n*m;++i){
        if (!vis[i])
            dfs(i);
    }
    memset(vis,0,sizeof(vis));
    reverse(V.begin(),V.end());
    int ptr = 0;
    for(int to:V){
        if (!vis[to])
            cond(to,++ptr);
    }
    for(auto to:edg){
        if (in_cmp[to.first]!=in_cmp[to.second])
            NG[in_cmp[to.first]].push_back(in_cmp[to.second]);
    }
    memset(vis,0,sizeof(vis));
    for(int i = 1;i<=ptr;++i){
        if (vis[i]==0 && cnt[i]>0)
            paint(i);
    }
    int res = 0;
    for(int i = 1;i<=ptr;++i)
        if (cnt[i])
        res+=1-mark[i];
    cout<<res<<endl;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    t = 1;
    while(t--)
        solve();
    return 0;
}