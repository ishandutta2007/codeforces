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
const int maxn=2e5+10;
int n;
int ecnt,h[maxn];
struct edges{int nxt,to,w;}E[maxn<<1];
void addline(int u,int v,int w){
  E[++ecnt]={h[u],v,w},h[u]=ecnt;
}
ll G,B;int sz[maxn];
void dfs(int u,int f){
  sz[u]=1;
  for(int i=h[u];i;i=E[i].nxt){
    int v=E[i].to;
    if(v!=f)dfs(v,u),sz[u]+=sz[v];
  }
  for(int i=h[u];i;i=E[i].nxt){
    int v=E[i].to;
    if(v!=f){
      int w=E[i].w;
      G+=(sz[v]&1)*w,B+=1ll*min(sz[v],n-sz[v])*w;
    }
  }
}

void solve() {
  cin>>n;n*=2,ecnt=1,memset(h,0,(n+1)<<2);
  rep(i,2,n){
    int u=read(),v=read(),w=read();addline(u,v,w),addline(v,u,w);
  }
  G=B=0,dfs(1,0);
  cout<<G<<' '<<B<<endl;
}

signed main() {
  int T=read();
  while(T--)solve();
//  solve();
  return 0;
}