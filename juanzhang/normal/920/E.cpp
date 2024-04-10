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
const int maxn=4e5+10;
int n,m,allx,deg[maxn],par[maxn],sz[maxn];
struct Edge{
  int u,v,w;
}G[maxn];vi E[maxn];
int vis[maxn],con[maxn];

int find(int x){
  return par[x]==x?x:par[x]=find(par[x]);
}

void solve(){
  cin>>n>>m;
  rep(i,1,n)par[i]=i;
  rep(i,1,m){
    G[i].u=read(),G[i].v=read();
  }
  rep(i,1,m){
    int u=G[i].u,v=G[i].v;
    E[u].push_back(v),E[v].push_back(u),deg[u]++,deg[v]++;
  }
//  printf("#%lld\n",allx);
  int pos=-1;
  rep(i,1,n)if((pos==-1||deg[i]<deg[pos]))pos=i;
  for(int v:E[pos])vis[v]=-1;
  vector<pii>tmp;
  rep(v,1,n)if(vis[v]!=-1&&find(pos)!=find(v)){
    con[v]=1;
//    printf("(%d %d)\n",pos,v);
    par[find(v)]=find(pos);
  }
  rep(i,1,n)if(!con[i]){
    for(int j:E[i])vis[j]=i;
    rep(j,1,n)if(vis[j]!=i&&find(i)!=find(j)){
//      printf("(%d %d)\n",i,j);
      par[find(i)]=find(j);
    }
  }
  rep(i,1,n)sz[find(i)]++;
  int res=0;multiset<int>S;
  rep(i,1,n)if(find(i)==i)res++,S.insert(sz[i]);
  cout<<res<<endl;
  for(int x:S)printf("%d ",x);
}

signed main(){
//  int T=read();
//  while(T--)solve();
  solve();
  return 0;
}