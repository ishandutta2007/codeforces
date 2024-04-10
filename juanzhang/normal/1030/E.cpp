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
int n,A[maxn],sum[maxn];

void solve() {
  cin>>n;
  rep(i,1,n){
    ll x;scanf("%I64d",&x),A[i]=__builtin_popcountll(x),sum[i]=sum[i-1]+A[i];
  }
  ll as=0;
  int ct[2]={0};
  per(i,n,1){
    int su=0,mx=0;
    rep(j,i,min(n,i+64)){
      chkmax(mx,A[j]),su+=A[j];
      as+=su%2==0&&mx*2<=su;
    }
    as+=ct[sum[i-1]%2];
    if(i+64<=n)ct[sum[i+64]%2]++;
  }
  cout<<as<<endl;
}

signed main() {
//  int T=read();
//  while(T--)solve();
  solve();
  return 0;
}