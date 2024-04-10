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
const int maxn=1e6+10;
int n,A[maxn],ans[maxn];

void divide(int l,int r,int d=0){
  if(l>r)return;
  if(l==r)return ans[l]=d,void();
  int mid=l;
  rep(i,l+1,r)if(A[i]>A[mid])mid=i;
  ans[mid]=d;
  divide(l,mid-1,d+1),divide(mid+1,r,d+1);
}

void solve(){
  cin>>n;
  rep(i,1,n)A[i]=read(),ans[i]=0;
  divide(1,n);
  rep(i,1,n)printf("%d%c",ans[i],"\n "[i<n]);
}

signed main(){
  int T=read();
  while(T--)solve();
//  solve();
  return 0;
}