// Hydro submission #61dc12a2f30c29ef2e812f03@1641812643381
#include<bits/stdc++.h>
#define mp make_pair
#define int long long
using namespace std;
typedef pair<int,int> Int;
const int N=2e5+5;
int dis[N],vis[N],p[N],tot,n,m,dep[N],siz[N],s,rd[N],f[N][30];
vector<int> e1[N],e2[N],tr[N];
vector<Int> e[N];
void dij(){
    priority_queue<Int,vector<Int>,greater<Int> > q;
    memset(dis,10,sizeof(dis));
    dis[s]=0;
    q.push(mp(0,s));
    while(!q.empty()){
        int x=q.top().second;
        q.pop();
        if(vis[x])continue;
        vis[x]=1;
        for(auto i:e[x]){
            int y=i.first,z=i.second;
            if(dis[x]+z<dis[y]){
                dis[y]=dis[x]+z;
                q.push(mp(dis[y],y));
            }
        }
    }
}
void topsort(){
    queue<int> q;
    q.push(s);
    while(!q.empty()){
        int x=q.front();
        p[++tot]=x;
        q.pop();
        for(int y:e1[x]){
            rd[y]--;
            if(!rd[y])q.push(y);
        }       
    }
}
void dfs(int x,int fa){
    siz[x]=1;
    for(int y:tr[x]){
        if(y==fa)continue;
        dfs(y,x);
        siz[x]+=siz[y];
    }
}
int lca(int x,int y){
    if(dep[x]>dep[y])swap(x,y);
    for(int i=20;i>=0;i--)if(dep[f[y][i]]>=dep[x])y=f[y][i];
    if(x==y)return x;
    for(int i=20;i>=0;i--)if(f[x][i]!=f[y][i])x=f[x][i],y=f[y][i];
    return f[x][0];
}
signed main(){
    scanf("%lld%lld%lld",&n,&m,&s);
    for(int i=1,x,y,z;i<=m;i++){
        scanf("%lld%lld%lld",&x,&y,&z);
        e[x].push_back(mp(y,z));
        e[y].push_back(mp(x,z));
    }
    dij();
    for(int x=1;x<=n;x++)
        for(auto i:e[x]){
            int y=i.first,z=i.second;
            if(dis[y]+z==dis[x])e1[y].push_back(x),e2[x].push_back(y),rd[x]++;
        }
    topsort();
    dep[s]=1;
    for(int i=2;i<=tot;i++){
        int x=p[i];
        int Fa=e2[x][0];
        for(int y:e2[x])Fa=lca(Fa,y);
        tr[Fa].push_back(x);
        dep[x]=dep[Fa]+1;
        f[x][0]=Fa;
        for(int j=1;j<=20;j++)f[x][j]=f[f[x][j-1]][j-1];
    }
    dfs(s,0);
    int ans=0;
    for(int i=1;i<=n;i++)if(i!=s)ans=max(ans,siz[i]);
    printf("%lld",ans);
}