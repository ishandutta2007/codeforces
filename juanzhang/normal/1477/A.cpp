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

void solve(){
  int n;ll k;cin>>n>>k;
  static ll A[200010];
  rep(i,1,n)cin>>A[i];
  if(n==1)return puts(A[1]==k?"YES":"NO"),void();
  sort(A+1,A+n+1);
  ll tp=-1;
  rep(i,1,n-1){
    ll x=A[i+1]-A[i];
    if(tp==-1)tp=x;
    else tp=__gcd(tp,x);
  }
  rep(i,1,n){
    ll x=k-A[i];
    if(x<0)x=-x;
    if(x%tp==0)return puts("YES"),void();
  }
  puts("NO");
//  int n;
//  cin>>n;
//  static bool vis[1010];
//  while(n--){
//    int x=read();vis[100+x]=1;
//  }
//  rep(T,1,100){
//    rep(i,0,200)if(vis[i])rep(j,0,200)if(vis[j]){
//      int x=i-100,y=j-100;
//      int tp=2*x-y;
//      if(abs(tp)<=100){
//        vis[100+tp]=1;
//      }
//    }
//  }
//  rep(i,0,200)if(vis[i])printf("%d ",i-100);
}

signed main(){
  int T=read();
  while(T--)solve();
//  solve();
  return 0;
}