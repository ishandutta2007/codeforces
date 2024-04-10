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
vector<int>g[M];
int dis[2][M],cnt[2][M];
void bfs(int *d,int *c,int s){
    for(int i=1;i<=n;++i)d[i]=1e9,c[i]=0;
    d[s]=0;
    c[s]=1;
    queue<int>q;
    q.push(s);
    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(auto v:g[u]){
            if(d[v]>d[u]+1){
                d[v]=d[u]+1;
                c[v]=c[u];
                q.push(v);
            }
            else if(d[v]==d[u]+1)c[v]=(c[v]+c[u])%mod;
        }
    }
}
void work(){
    int s,t;
    cin>>n>>m>>s>>t;
    for(int i=1;i<=n;++i)g[i].clear();
    for(int i=1;i<=m;++i){
        int u,v;
        cin>>u>>v;
        g[u].eb(v);
        g[v].eb(u);
    }
    bfs(dis[0],cnt[0],s);
    bfs(dis[1],cnt[1],t);
    int ans=0;
    for(int i=1;i<=n;++i){
        for(auto j:g[i]){
            if(dis[0][i]+dis[1][j]==dis[0][t]&&dis[0][i]+dis[1][i]==dis[0][t]){
                ans=(ans+1ll*cnt[0][i]*cnt[1][j]%mod)%mod;
            }
        }
    }
    ans=(ans+cnt[0][t])%mod;
    cout<<ans<<endl;
}
int main(){
    int T;
    cin>>T;
    while(T--)work();
    return 0;
}
/*
1

4 4
1 4
1 2
3 4
2 3
2 4
*/