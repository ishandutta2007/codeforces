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
ll N;int q;

ll find(ll n,ll x){
//  printf("(%lld %lld)\n",n,x);
  if(x&1)return (x+1)/2;
  ll p=x/2;
  if(n&1){
    return n/2+1+find(n/2,p==1?n/2:p-1);
  }else{
    return n/2+find(n/2,p);
  }
}

void solve() {
  cin.tie(0),cout.tie(0);
  ios::sync_with_stdio(0);
  cin>>N>>q;
  while(q--){
    ll x;cin>>x;
    cout<<find(N,x)<<endl;
  }
}

signed main() {
//  int T=read();
//  while(T--)solve();
  solve();
  return 0;
}