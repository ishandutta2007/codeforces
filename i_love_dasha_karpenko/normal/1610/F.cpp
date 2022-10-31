#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define endl '\n'
#define all(var) var.begin(),var.end()
const int N = 2e5+7;
struct edge{
    int u,v,w;
} E[N];
vector<int> G[N][2];
int n,m;
pair<int,int> par[N];
int vis[N],vis_edg[N],sum[N],dir[N],del[N];
void dfs(int v){
    vis[v] = 1;
    for(int c = 0;c<2;++c)
        for(int ind:G[v][c]){
            if (vis_edg[ind] || del[ind])
                continue;
            vis_edg[ind] = 1;
            int fl = 0;
            int to = E[ind].v^E[ind].u^v;
            if (sum[v]<0)
                fl = 0,sum[v]+=c+1,sum[to]-=c+1;
            else fl = 1,sum[v]-=c+1,sum[to]+=c+1;
            if (E[ind].v==v)
                dir[ind] = fl;
            else dir[ind] = fl^1;
            dfs(to);
        }
}
int F(int pos){
    if (!vis_edg[pos])
        dir[pos] = F(par[pos].first)^par[pos].second;
    vis_edg[pos] = 1;
    return dir[pos];

}
void solve(){

    cin>>n>>m;
    int sm = m;
    for(int i = 1;i<=m;++i){
        cin>>E[i].u>>E[i].v>>E[i].w;
        G[E[i].u][E[i].w-1].push_back(i);
        G[E[i].v][E[i].w-1].push_back(i);
    }
    vector<int> V;
    for(int i = 1;i<=n;++i)
        V.push_back(i);
    while(!V.empty()){
        int v = V.back();
        V.pop_back();
        for(int c = 0;c<2;++c)
            while(G[v][c].size()>=2){
                while(!G[v][c].empty() && del[G[v][c].back()]==1)
                    G[v][c].pop_back();
                if (G[v][c].empty())
                    break;
                int e1 = G[v][c].back();
                G[v][c].pop_back();
                while(!G[v][c].empty() && del[G[v][c].back()]==1)
                    G[v][c].pop_back();
                if (G[v][c].empty()){
                    G[v][c].push_back(e1);
                    break;
                }
                int e2 = G[v][c].back();
                G[v][c].pop_back();
                int ne = ++m;
                int a = E[e1].u^E[e1].v^v,b = E[e2].u^E[e2].v^v;
                E[ne] = {a,b,c+1};
                if (a!=b){
                    G[a][c].push_back(ne);
                    G[b][c].push_back(ne);
                    V.push_back(a);
                    V.push_back(b);
                }
                else{
                    vis_edg[ne] = 1;
                    dir[ne] = 0;
                }
                par[e1].first = par[e2].first = ne;
                del[e1] = del[e2] = 1;
                if (E[e1].u==a)
                    par[e1].second = 0;
                else par[e1].second = 1;
                if (E[e2].v==b)
                    par[e2].second = 0;
                else par[e2].second = 1;

            }
    }
    for(int i = 1;i<=n;++i)
        if (!vis[i])
            dfs(i);
    int res = 0;
    for(int i = 1;i<=n;++i)
        if (abs(sum[i])==1)
            ++res;
    cout<<res<<endl;
    for(int i = 1;i<=sm;++i){
        cout<<1-F(i)+1;
    }
    cout<<endl;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1;
    while(t--)
        solve();
    return 0;
}