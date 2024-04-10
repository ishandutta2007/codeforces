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
int n,k;ll A[1010];

bool check(ll mid){
  ll su=A[1]+mid;
//  printf("#%lld\n",mid);
  rep(i,2,n){
//    printf("(%lf) %lld %lld\n",(db)A[i]/su,A[i],su*k);
    if(100ll*A[i]>su*k){
      return 0;
    }
    su+=A[i];
  }
  return 1;
}

void solve(){
  cin>>n>>k;
  rep(i,1,n)A[i]=read();
  ll l=0,r=1e11,ans=0;
  while(l<=r){
    ll mid=(l+r)/2;
    check(mid)?r=(ans=mid)-1:l=mid+1;
  }
  cout<<ans<<endl;
}

signed main(){
  int T=read();
  while(T--)solve();
//  solve();
  return 0;
}