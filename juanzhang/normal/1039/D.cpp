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
const int maxn=1e5+10;
int n,bsz,ans[maxn];
vi E[maxn],ou[maxn];

int arr[maxn],val[maxn],mp[maxn];
void dfs(int u,int f){
  static int now;
  for(int v:E[u])if(v!=f){
    ou[u].push_back(v),dfs(v,u);
  }
  arr[++now]=u;
}
int run(int k){
  if(mp[k]!=-1)return mp[k];
  int res=0;
  rep(t,1,n){
    int u=arr[t];
    int mx1=0,mx2=0;
    for(int v:ou[u]){
      int p=val[v];
      if(mx1<p)mx2=mx1,mx1=p;
      else if(mx2<p)mx2=p;
    }
    if(mx1+mx2+1>=k)res++,val[u]=0;
    else val[u]=mx1+1;
  }
  return mp[k]=res;
}

void solve() {
  memset(mp,-1,sizeof mp);
  cin>>n;
  rep(i,2,n){
    int u=read(),v=read();E[u].push_back(v),E[v].push_back(u);
  }
  dfs(1,0);
  bsz=sqrt((db)n*log((db)n));
  ans[1]=n;
  rep(i,2,bsz)ans[i]=run(i);
  int cur=n;
  rep(i,0,n/(bsz+1)){
    int l=bsz+1,r=cur;
    while(l<r){
      int mid=(l+r)/2;
      run(mid)>i?l=mid+1:r=mid;
    }
    if(run(l)>i)l++;
    rep(j,l,cur)ans[j]=i;
    cur=l-1;
  }
  rep(i,1,n)printf("%d\n",ans[i]);
}

signed main() {
//  int T=read();
//  while(T--)solve();
  solve();
  return 0;
}