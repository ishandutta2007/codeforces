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
const int maxn=3e5+10;
int n,m,dep[maxn];vi E[maxn];

bool af;ll ans;set<pii>S[maxn];int tag[maxn];

int dfs(int u,int f){
  dep[u]=dep[f]+1;int res=n+1;
  for(int v:E[u])if(v!=f){
    chkmin(res,dfs(v,u));
    if(S[u].size()<S[v].size())swap(S[u],S[v]),swap(tag[u],tag[v]);
    for(pii p:S[v])S[u].insert({p.first+tag[v]-tag[u],p.second});
    S[v].clear(),tag[v]=0;
  }
  if(res<dep[u])return res;
  while(!S[u].empty()){
    pii p=*S[u].begin();
    S[u].erase(S[u].begin());
    int d=dep[p.second];
    if(d<res){
      ans+=p.first+tag[u],tag[u]=-p.first,res=d;break;
    }
  }
  if(u>1&&res>=dep[u])af=1;
  return res;
}

void solve() {
  cin>>n>>m;
  rep(i,2,n){
    int u=read(),v=read();E[u].push_back(v),E[v].push_back(u);
  }
  rep(i,1,m){
    int u=read(),v=read(),w=read();if(u!=v)S[u].insert({w,v});
  }
  dfs(1,0);
  if(af)puts("-1");
  else cout<<ans<<endl;
}

signed main() {
//  int T=read();
//  while(T--)solve();
  solve();
  return 0;
}