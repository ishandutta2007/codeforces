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
const int M=1e5+9;
int n,m;
int sx,sy,fx,fy;
int dis[M],id[M];
struct P{int x,y;}p[M];
int t[M<<1];
vector<pii>g[M];
void push(int x,int y){
    for(t[x+=m-1]=y;x;x>>=1)t[x>>1]=dis[t[x]]<dis[t[x^1]]?t[x]:t[x^1];
}
void add(int x,int y){
    int mi=min(abs(p[x].x-p[y].x),abs(p[x].y-p[y].y));
    g[x].eb(y,mi);
    g[y].eb(x,mi);
}
int main(){
    cin>>n>>m;
    cin>>sx>>sy>>fx>>fy;
    dis[0]=2e9;
    for(int i=1;i<=m;++i){
        id[i]=i;
        cin>>p[i].x>>p[i].y;
        dis[i]=min(abs(sx-p[i].x),abs(sy-p[i].y));
        push(i,i);
    }
    sort(id+1,id+m+1,[&](const int&l,const int&r){return p[l].x==p[r].x?p[l].y<p[r].y:p[l].x<p[r].x;});
    for(int i=2;i<=m;++i)add(id[i-1],id[i]);
    sort(id+1,id+m+1,[&](const int&l,const int&r){return p[l].y==p[r].y?p[l].x<p[r].x:p[l].y<p[r].y;});
    for(int i=2;i<=m;++i)add(id[i-1],id[i]);
    for(int i=1;i<=m;++i){
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
    int ans=abs(fx-sx)+abs(fy-sy);
    for(int i=1;i<=m;++i){
        ans=min(1ll*ans,1ll*dis[i]+abs(fx-p[i].x)+abs(fy-p[i].y));
    }
    cout<<ans<<endl;
    return 0;
}