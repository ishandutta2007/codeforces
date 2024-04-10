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
const int maxn=2e5+10;
ll K,X,A[maxn];
int n;

void solve(){
  cin>>n>>K>>X;
  rep(i,1,n)scanf("%lld",A+i);
  sort(A+1,A+n+1);
  vector<ll>vec;
  int ans=1;
  rep(i,2,n){
    if(A[i]-A[i-1]>X){
      vec.push_back((A[i]-A[i-1]-1)/X);
      ans++;
    }
  }
  sort(vec.begin(),vec.end());
  for(ll x:vec)if(K>=x)K-=x,ans--;
  cout<<ans<<endl;
}

signed main(){
//  int T=read();
//  while(T--)solve();
  solve();
  return 0;
}