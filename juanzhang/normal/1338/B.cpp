#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=(a),i##end=(b);i<=i##end;++i)
#define per(i,a,b) for(int i=(a),i##end=(b);i>=i##end;--i)
//mt19937 Rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
template<typename T>void chkmax(T&x,T y){if(x<y)x=y;}
template<typename T>void chkmin(T&x,T y){if(x>y)x=y;}
inline int read(){
  #define nc getchar()
  bool f=0;int x=0;char c=nc;
  while(c<48)f|=c=='-',c=nc;
  while(c>47)x=x*10+(c^48),c=nc;
  return f?-x:x;
  #undef nc
}

typedef double db;
typedef long long ll;
typedef vector<int>vi;
typedef pair<int,int>pii;
const int maxn=1e5+10;
int n;vi E[maxn];

set<int>S;
void dfs(int u,int f=0,int d=0){
  if((int)E[u].size()==1)S.insert(d);
  for(int v:E[u])if(v!=f)dfs(v,u,d^1);
}

void solve(){
  cin>>n;
  rep(i,2,n){
    int u=read(),v=read();E[u].push_back(v),E[v].push_back(u);
  }
  int res=n-1;
  static bool vis[maxn];
  int rt=-1;
  rep(i,1,n)if((int)E[i].size()==1){
    int j=E[i][0];
    if(vis[j])res--;
    else vis[j]=1;
    rt=i;
  }
  dfs(rt);
  bool flg=(int)S.size()==2;
  cout<<(flg?3:1)<<' '<<res<<endl;
}

signed main(){
//  int T=read();
//  while(T--)solve();
  solve();
  return 0;
}