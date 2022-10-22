#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=(a),i##end=(b);i<=i##end;++i)
#define per(i,a,b) for(int i=(a),i##end=(b);i>=i##end;--i)
mt19937 Rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
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
int n,k,A[maxn],D[maxn],pmn[maxn];ll prs[maxn],sfs[maxn];

void solve(){
  cin>>n>>k;
  rep(i,1,n)A[i]=read(),prs[i]=prs[i-1]+A[i];
  rep(i,1,n)D[i]=read(),pmn[i]=min(i>1?pmn[i-1]:1000000,D[i]);
  per(i,n,1)sfs[i]=sfs[i+1]+A[i];
  ll ans=0;
  rep(i,2,n)chkmax(ans,sfs[i]-D[i]);
  if(k!=1)chkmax(ans,sfs[1]-D[1]);
  if(!k)return cout<<ans<<endl,void();
  ll tp=0;
  per(i,n-1,1){
    chkmax(tp,sfs[i+1]-D[i+1]);
    chkmax(ans,tp+max(0ll,prs[i]-pmn[i]));
  }
  ll pr=0;
  rep(i,2,n-1){
    chkmax(pr,sfs[i-1]-D[i-1]);
    chkmax(ans,pr-A[i]);
  }
  if(k>1)chkmax(ans,prs[n]-pmn[n-1]);
  cout<<ans<<endl;
}

signed main(){
//  int T=read();
//  while(T--)solve();
  solve();
  return 0;
}