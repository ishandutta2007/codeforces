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
int n,cnt[2],col[maxn];
vi E[maxn];
void dfs(int u,int f){
  cnt[col[u]]++;
  for(int v:E[u])if(v!=f)col[v]=col[u]^1,dfs(v,u);
}

void solve() {
  cin>>n;rep(i,2,n){
    int u=read(),v=read();E[u].push_back(v),E[v].push_back(u);
  }
  dfs(1,0);
  printf("%d\n",min(cnt[0],cnt[1])-1);
}

signed main() {
//  int T=read();
//  while(T--)solve();
  solve();
  return 0;
}