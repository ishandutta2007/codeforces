#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=(a),i##end=(b);i<=i##end;++i)
#define per(i,a,b) for(int i=(a),i##end=(b);i>=i##end;--i)

const int maxn=2e5+10;
int n,S,deg[maxn],par[maxn],sz[maxn];vector<int>E[maxn];

namespace Dij{
  typedef long long ll;
  typedef pair<ll,int> pii;
  int m,ecnt=1,h[maxn];ll dis[maxn];
  struct edges{
    int nxt,to,w;
  }G[maxn*3];
  void addline(int u,int v,int w){
    G[++ecnt]={h[u],v,w},h[u]=ecnt;
  }
  void solve(){
    cin>>n>>m>>S;rep(i,1,m){
      int u,v,w;scanf("%d%d%d",&u,&v,&w),addline(u,v,w),addline(v,u,w);
    }
    priority_queue<pii,vector<pii>,greater<pii>>Q;
    memset(dis,0x3f,sizeof dis),dis[S]=0,Q.push({0,S});
    while(!Q.empty()){
      pii p=Q.top();Q.pop();int u=p.second;
      if(p.first>dis[u])continue;
      for(int i=h[u];i;i=G[i].nxt){
        int v=G[i].to;if(dis[v]>dis[u]+G[i].w)dis[v]=dis[u]+G[i].w,Q.push({dis[v],v});
      }
    }
    rep(i,2,ecnt){
      int u=G[i^1].to,v=G[i].to;
      if(dis[v]==dis[u]+G[i].w)E[u].push_back(v),deg[v]++;
    }
  }
}

int main(){
  Dij::solve();rep(i,1,n)par[i]=i;
  static int Q[maxn];int l=1,r=1;Q[1]=S;
  while(l<=r){
    int u=Q[l++];if(par[u]==-1||par[u]==S)par[u]=u;sz[par[u]]++;
    for(int v:E[u]){
      if(par[v]==v)par[v]=par[u];
      else if(par[v]!=par[u])par[v]=-1;
      if(!--deg[v])Q[++r]=v;
    }
  }
  int ans=0;rep(i,1,n)if(par[i]==i&&i!=S)ans=max(ans,sz[i]);cout<<ans<<endl;
  return 0;
}