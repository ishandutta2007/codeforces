#include<bits/stdc++.h>
using namespace std;
const int MOD=1000000007;
const int MAX_N=2000000+10;
int n,m;
vector<int> g[MAX_N][10];
int tot;
int dis[MAX_N];
int d[MAX_N];
int vis[MAX_N];
void insertEdge(int u,int v,int x){
    vector<int> stk;
    while(x>0){
        stk.push_back(x%10);
        x/=10;
    }
    reverse(stk.begin(),stk.end());
    for(int i=0;i<stk.size()-1;++i){
        g[u][stk[i]].push_back(++tot);
        u=tot;
    }
    g[u][stk.back()].push_back(v);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>m;
    tot=n;
    for(int i=1;i<=m;++i){
        int u,v;
        cin>>u>>v;
        insertEdge(u,v,i);
        insertEdge(v,u,i);
    }
    vector<vector<int>> que(2);
    dis[1]=0;
    que[0].push_back(1);
    vis[1]=2;
    int cur=0;
    for(int step=1;step<=tot;++step){
        cur^=1;
        que[cur].clear();
        for(int u:que[cur^1]){
            for(int x=0;x<=9;++x){
                for(int v:g[u][x]){
                    if(!vis[v]){
                        vis[v]=1;
                        d[v]=10*d[u]+x;
                        dis[v]=(10ll*dis[u]+x)%MOD;
                        que[cur].push_back(v);
                    }else if(vis[v]==1&&d[v]>10*d[u]+x){
                        d[v]=10*d[u]+x;
                        dis[v]=(10ll*dis[u]+x)%MOD;
                    }
                }
            }
        }
        sort(que[cur].begin(),que[cur].end(),[&](int i,int j){
            return d[i]<d[j];
        });
        vector<int> x(que[cur].size());
        for(int i=0;i<que[cur].size();++i){
            x[i]=d[que[cur][i]];
        }
        for(int i=0;i<que[cur].size();++i){
            d[que[cur][i]]=lower_bound(x.begin(),x.end(),d[que[cur][i]])-x.begin();
            vis[que[cur][i]]=2;
        }
    }
    for(int i=2;i<=n;++i){
        cout<<dis[i]<<endl;
    }
    return 0;
}