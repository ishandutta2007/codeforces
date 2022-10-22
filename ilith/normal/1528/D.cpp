#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
#define mp make_pair
using namespace std;
const int maxn=610,maxm=0,maxz=0,mod=998244353;
int n,m;
long long dis[maxn];
long long g[maxn][maxn];
bool vis[maxn];
inline int read(){
    int res=0;
    char ch=getchar(),ch1=ch;
    while(!isdigit(ch))ch1=ch,ch=getchar();
    while(isdigit(ch))res=(res<<3)+(res<<1)+ch-'0',ch=getchar();
    return ch1=='-'?-res:res;
}
void dijkstra(int s){
    for(int i=0;i<n;++i)
        dis[i]=1ll<<55,vis[i]=false;
    priority_queue <pair<long long,int> > q;
    dis[s]=0;
    q.push(mp(0,s));
    while(q.size()){
        int p=q.top().second;
        q.pop();
        if(vis[p])continue;
        vis[p]=true;
        for(int i=0,to;i<n;++i){
            to=(i+dis[p])%n;
            if(dis[to]>dis[p]+g[p][i]){
                dis[to]=dis[p]+g[p][i];
                q.push(mp(-dis[to],to));
            }
        }
    }
    printf("%lld",dis[0]);
    for(int i=1;i<n;++i)
        printf(" %lld",dis[i]);
    puts("");
}
int main(){
    n=read();m=read();
    for(int i=0;i<n;++i)
        for(int j=0;j<n;++j)
            g[i][j]=1ll<<55;
    for(int i=1,x,y;i<=m;++i){
        x=read();y=read();
        long long z=read();
        for(int j=0;j<n;++j)
            g[x][(j+y)%n]=min(g[x][(j+y)%n],z+j);
    }
    for(int i=0;i<n;++i)
        dijkstra(i);
    return 0;
}