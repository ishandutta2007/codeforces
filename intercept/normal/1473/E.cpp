#include<bits/stdc++.h>
#define ll long long 
#define eb emplace_back
#define fi first
#define se second
#define pii pair<int,int>
using namespace std;
const int mod=1e9+7;
int kpow(int x,int y,int rex=1){
    for(;y;y>>=1,x=1ll*x*x%mod)if(y&1)rex=1ll*x*rex%mod;
    return rex;
}
int exgcd(int a,int b,int &x,int &y){
    int t=b?exgcd(b,a%b,y,x):a;
    if(!b)x=1,y=0;
    else y-=a/b*x;
    return t;
}
const int M=2e5+9;
int n,m;
vector<pii>g[M<<2];
ll dis[M<<2];
int t[M<<3];
void push(int x,int y){
    for(t[x+=n*4-1]=y;x;x>>=1)t[x>>1]=dis[t[x]]<dis[t[x^1]]?t[x]:t[x^1];
}
void dij(){
    for(int i=0;i<=n*4;++i)dis[i]=1ll<<60;
    dis[1]=0;
    push(1,1);
    for(int i=1;i<=n*4;++i){
        int u=t[1];
        push(u,0);
        for(auto o:g[u]){
            int v=o.fi,w=o.se;
            if(dis[v]>dis[u]+w){
                dis[v]=dis[u]+w;
                push(v,v);
            }
        }
    }
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=m;++i){
        int u,v,w;
        cin>>u>>v>>w;
        g[u].eb(v,w);
        g[u].eb(v+n,w*2);
        g[u].eb(v+n*2,0);
        g[u].eb(v+n*3,w);
        g[u+n].eb(v+n,w);
        g[u+n].eb(v+n*3,0);
        g[u+n*2].eb(v+n*2,w);
        g[u+n*2].eb(v+n*3,w*2);
        g[u+n*3].eb(v+n*3,w);

        g[v].eb(u,w);
        g[v].eb(u+n,w*2);
        g[v].eb(u+n*2,0);
        g[v].eb(u+n*3,w);
        g[v+n].eb(u+n,w);
        g[v+n].eb(u+n*3,0);
        g[v+n*2].eb(u+n*2,w);
        g[v+n*2].eb(u+n*3,w*2);
        g[v+n*3].eb(u+n*3,w);
    }
    dij();
    for(int i=2;i<=n;++i)printf("%lld%c",dis[n*3+i]," \n"[i==n]);
    return 0;
}