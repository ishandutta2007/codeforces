#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=200010;
struct edge{
    int next,to;
}e[maxn*2];
int head[maxn],len;
void add(int x,int y){
    e[++len]={head[x],y};
    head[x]=len;
}
int i,j,k,n,m,d[maxn],dis[maxn],vis[maxn];
map<pair<int,int>,int>M;
void dij(){
    priority_queue<pair<int,int>>Q;
    memset(dis,0x3f,sizeof(dis));
    dis[n]=0;Q.push(make_pair(0,n));
    while(!Q.empty()){
        int now=Q.top().second;Q.pop();
        // cerr<<"now="<<now<<' '<<dis[now]<<endl;
        if(vis[now])continue;vis[now]=1;
        for(int i=head[now];i;i=e[i].next){
            int u=e[i].to;
            // cerr<<now<<" -> "<<u<<endl;
            if(dis[u]>dis[now]+d[u]){
                dis[u]=dis[now]+d[u];
                Q.push(make_pair(-dis[u],u));
            }
            d[u]--;
        }
    }
}
signed main(){
    cin>>n>>m;
    for(i=1;i<=m;i++){
        int x,y;
        scanf("%lld%lld",&x,&y);
        M[make_pair(y,x)]++;
        add(y,x);
        d[x]++;
    }
    dij();
    cout<<dis[1]<<endl;
    return 0;
}