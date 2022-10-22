#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=(a),i##end=(b);i<=i##end;++i)
#define per(i,a,b) for(int i=(a),i##end=(b);i>=i##end;--i)
//mt19937 Rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
template<typename T>void chkmax(T&x,T y){if(x<y)x=y;}
template<typename T>void chkmin(T&x,T y){if(x>y)x=y;}
inline int read(){
  #define nc getchar()
  int x=0;char c=nc;bool f=0;
  while(c<48)f|=c=='-',c=nc;
  while(c>47)x=x*10+(c^48),c=nc;
  return f?-x:x;
  #undef nc
}

typedef double db;
typedef long long ll;
typedef vector<int>vi;
typedef pair<int,int>pii;
const int maxn=2e5+10;
int n,m,allx,deg[maxn],par[maxn];
struct Edge{
  int u,v,w;
}G[maxn];vi E[maxn];
int vis[maxn],con[maxn];

int find(int x){
  return par[x]==x?x:par[x]=find(par[x]);
}

ll Run(int tpw){
  memset(deg,0,sizeof deg);
  rep(i,1,n)par[i]=i,E[i].clear();
  ll ans=0,ct=1ll*n*(n-1)/2-m-1;
  int k=0;
  rep(i,1,m)if(G[i].w<=tpw){
    par[find(G[i].u)]=find(G[i].v),ans+=G[i].w;
    k=i;
  }
  rep(i,k+1,m){
    int u=G[i].u,v=G[i].v;
    E[u].push_back(v),E[v].push_back(u),deg[u]++,deg[v]++;
  }
  memset(vis,0,sizeof vis);memset(con,0,sizeof con);
//  printf("#%lld\n",allx);
  int pos=-1;
  rep(i,1,n)if((pos==-1||deg[i]<deg[pos]))pos=i;
  for(int v:E[pos])vis[v]=-1;
  vector<pii>tmp;
  rep(v,1,n)if(vis[v]!=-1&&find(pos)!=find(v)){
    con[v]=1;
//    printf("(%d %d)\n",pos,v);
    if(ct)par[find(v)]=find(pos),ct--;
    else tmp.push_back({pos,v});
  }
  rep(i,1,n)if(!con[i]){
    for(int j:E[i])vis[j]=i;
    rep(j,1,n)if(vis[j]!=i&&find(i)!=find(j)){
//      printf("(%d %d)\n",i,j);
      if(ct)par[find(i)]=find(j),ct--;
      else tmp.push_back({i,j});
    }
  }
  int k2=0;
  rep(i,k+1,m)if(G[i].w<=allx){
    int u=G[i].u,v=G[i].v;
    if(find(u)!=find(v)){
      par[find(u)]=find(v),ans+=G[i].w;
    }
    k2=i;
  }
  for(pii p:tmp)if(find(p.first)!=find(p.second)){
    par[find(p.first)]=par[find(p.second)],ans+=allx;break;
  }
  rep(i,k2+1,m){
    int u=G[i].u,v=G[i].v;
    if(find(u)!=find(v)){
      par[find(u)]=find(v),ans+=G[i].w;
    }
  }
  return ans;
}

void solve(){
  cin>>n>>m;
  rep(i,1,m){
    G[i].u=read(),G[i].v=read(),G[i].w=read(),allx^=G[i].w;
  }
  sort(G+1,G+m+1,[](Edge P,Edge Q){
    return P.w<Q.w;
  });
  ll res=Run(0);
//  rep(bit,0,29){
//    int tpw=0;
//    rep(i,0,bit)if(allx>>i&1)tpw|=1<<i;
//    res=min(res,Run(tpw));
//  }
  rep(i,1,m){
    res=min(res,Run(G[i].w));
    if(clock()>2500)break;
  }
  cout<<res<<endl;
}

signed main(){
//  int T=read();
//  while(T--)solve();
  solve();
  return 0;
}