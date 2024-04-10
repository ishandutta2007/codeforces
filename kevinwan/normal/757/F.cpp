#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>pii;
typedef long long ll;
typedef pair<ll,ll>pll;
typedef __int128 lll;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const ll mod=1e9+7;
const ll mn=3e5+10;
vector<int>g[mn],w[mn];
vector<int>gg[mn];
ll dis[mn];
int bes[mn],num[mn];
bool vis[mn];
int s;
void dfs(int x){
    vis[x]=1;
    for(int y:gg[x]){
        if(!vis[y])dfs(y);
        if(y==s)bes[x]=x;
        else if(!bes[x]||bes[x]==bes[y])bes[x]=bes[y];
        else bes[x]=x;
    }
    num[bes[x]]++;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin>>n>>m>>s;
    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        g[a].push_back(b);
        g[b].push_back(a);
        w[a].push_back(c);
        w[b].push_back(c);
    }
    priority_queue<pll,vector<pll>,greater<>>pq;
    memset(dis,0x3f,sizeof(dis));
    pq.push({0,s});
    while(pq.size()){
        ll x=pq.top().second,d=pq.top().first;
        pq.pop();
        if(dis[x]!=0x3f3f3f3f3f3f3f3f)continue;
        dis[x]=d;
        for(int i=0;i<g[x].size();i++){
            pq.push({w[x][i]+d,g[x][i]});
        }
    }
    for(int x=1;x<=n;x++)for(int i=0;i<g[x].size();i++){
        int y=g[x][i];
        if(dis[x]+w[x][i]==dis[y])gg[y].push_back(x);
    }
    for(int x=1;x<=n;x++)if(dis[x]!=0x3f3f3f3f3f3f3f3f&&!vis[x])dfs(x);
    int ans=0;
    for(int i=1;i<=n;i++)ans=max(ans,num[i]);
    printf("%d",ans);
}