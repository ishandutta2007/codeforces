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
typedef vector<int> vi;
typedef pair<int,int> pii;
const int maxn=1e5+10;
int n,A[maxn];
vi E[maxn];
ll ans[maxn];
priority_queue<int>Q;

void solve(){
  cin>>n;
  rep(i,1,n)A[i]=read();
  static int deg[maxn];
  rep(i,2,n){
    int u=read(),v=read();E[u].push_back(v),E[v].push_back(u);
    deg[u]++,deg[v]++;
    ans[n-1]+=A[u]+A[v];
  }
  rep(i,1,n)rep(j,1,deg[i]-1)Q.push(-A[i]);
  per(i,n-2,1){
    int x=-Q.top();Q.pop();
    ans[i]=ans[i+1]-x;
  }
  rep(i,1,n-1)printf("%I64d%c",ans[i],"\n "[i<n-1]);
  while(!Q.empty())Q.pop();
  rep(i,1,n)E[i].clear(),deg[i]=0;
  rep(i,1,n-1)ans[i]=0;
}

signed main(){
  int T=read();
  while(T--)solve();
//  solve();
  return 0;
}