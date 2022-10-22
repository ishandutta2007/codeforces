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
const int maxn=1e6+10;
int n,k,deg[maxn],dep[maxn],ltt;pii dat[maxn];
set<int>E[maxn];

int c[maxn],dfn[maxn],sz[maxn];
void add(int pos,int x){for(;pos<=n;pos+=pos&-pos)c[pos]+=x;}
int query(int pos){int res=0;for(;pos;pos&=pos-1)res+=c[pos];return res;}
int query_sub(int u){return query(dfn[u]+sz[u]-1)-query(dfn[u]-1);}

void dfs(int u,int f){
  static int now;
  dep[u]=dep[f]+1,dfn[u]=++now,sz[u]=1;
  if(deg[u]==1)dat[++ltt]={dep[u],u};
  for(int v:E[u])if(v!=f)dfs(v,u),sz[u]+=sz[v];
}

void solve(){
  cin>>n>>k;
  rep(i,2,n){
    int u=read(),v=read();E[u].insert(v),E[v].insert(u),deg[u]++,deg[v]++;
  }
  int rt=-1;
  rep(i,1,n)if(deg[i]!=1){
    rt=i;break;
  }
  dfs(rt,0);
  rep(i,1,n)if(deg[i]==1)add(dfn[i],1);
  sort(dat+1,dat+ltt+1);
  int ans=0;
  per(T,ltt,1){
    static int Q[maxn],vis[maxn],dis[maxn];
    int S=dat[T].second;
    if(query_sub(S)==0)continue;
    int l=1,r=1;Q[1]=S,dis[S]=0,vis[S]=T,ans++;
    while(l<=r){
      int u=Q[l++];
      if(dis[u]==k)continue;
      for(int v:E[u])if(vis[v]!=T){
        vis[v]=T,dis[v]=dis[u]+1,Q[++r]=v;
        if(deg[v]==1)add(dfn[v],-1);
      }
    }
    rep(i,1,r){
      int u=Q[i];
      if(!query_sub(u)){
        for(int v:E[u])E[v].erase(u);
        E[u].clear();
      }
    }
  }
  cout<<ans<<endl;
}

signed main(){
//  int T=read();
//  while(T--)solve();
  solve();
  return 0;
}