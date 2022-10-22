#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=(a),i##end=(b);i<=i##end;++i)
#define per(i,a,b) for(int i=(a),i##end=(b);i>=i##end;--i)
mt19937 Rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
template<typename T>void chkmax(T&x,T y){if(x<y)x=y;}
template<typename T>void chkmin(T&x,T y){if(x>y)x=y;}
inline int read() {
  #define nc getchar()
  int x=0;char c=nc;
  while(c<48)c=nc;
  while(c>47)x=x*10+(c^48),c=nc;
  return x;
  #undef nc
}

typedef double db;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
const int maxn=5e5+10;
int n;
vi E[maxn];

int sz[maxn];
ll as,chk[maxn][2],dp1[maxn][2],dp2[maxn];

ll sqr(ll x){return x*x;}

void dfs1(int u,int f){
  sz[u]=1;
  for(int v:E[u])if(v!=f){
    dfs1(v,u),sz[u]+=sz[v];
  }
  dp1[u][0]=dp1[u][1]=1e18;
  if((int)E[u].size()==1)return dp1[u][0]=1,void();
  for(int v:E[u])if(v!=f){
    ll tp=dp1[v][0]+sqr(sz[u]-sz[v]);
    if(dp1[u][0]>tp)dp1[u][1]=dp1[u][0],dp1[u][0]=tp,chk[u][1]=chk[u][0],chk[u][0]=v;
    else if(dp1[u][1]>tp)dp1[u][1]=tp,chk[u][1]=v;
  }
  int v0=chk[u][0],v1=chk[u][1];
  if(v1)chkmin(as,dp1[v0][0]+dp1[v1][0]+sqr(n-sz[v0]-sz[v1]));
//  printf("#%d %lld (%d %d) (%lld %lld)\n",u,as,v0,v1,dp1[u][0],dp1[u][1]);
}

void dfs2(int u,int f,ll val){
//  printf("(%d) %lld %lld\n",u,val,dp1[u][0]);
  chkmin(as,dp1[u][0]+val);
  for(int v:E[u])if(v!=f){
    ll tp=1e18;
    rep(t,0,1){
      int v0=chk[u][t];
      if(v0==v||!v0)continue;
      tp=min(val+sqr(sz[u]-sz[v]),dp1[v0][0]+sqr(n-sz[v0]-sz[v]));
      break;
    }
    if(tp>1e17)tp=sqr(n-sz[v]);
    dfs2(v,u,tp);
  }
}

void solve() {
  cin>>n;
  rep(i,2,n){
    int u=read(),v=read();E[u].push_back(v),E[v].push_back(u);
  }
  as=1e18;
  dfs1(1,0),dfs2(1,0,1e18);
//  rep(i,1,n)printf("#%lld\n",dp1[i][0]);
  cout<<1ll*n*(n-1)-(as-n)/2<<endl;
}

signed main() {
//  int T=read();
//  while(T--)solve();
  solve();
  return 0;
}