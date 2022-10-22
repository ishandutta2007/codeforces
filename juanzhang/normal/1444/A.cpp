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

void solve() {
  ll p,q;
  cin>>p>>q;
  if(p%q!=0){
    cout<<p<<endl;
  }else{
    int x=q;
    vi fac;
    rep(i,2,sqrt(q)+0.5)if(x%i==0){
      fac.push_back(i);
      while(x%i==0)x/=i;
    }
    if(x>1)fac.push_back(x);
//    for(int t:fac){
//      x=q;ll y=p;
//      int ct=0,ct2=0;
//      while(x%t==0)x/=t,ct++;
//      while(y%t==0)y/=t,ct2++;
//      if(ct>ct2){
//        rep(j,1,ct-ct2){
//          q/=t;
//        }
//      }
//    }
//    printf("#%d\n",(int)q);
    ll ans=-1;
    for(int t:fac){
      int ct=0,x=q,ct2=0;ll y=p;
      while(x%t==0)x/=t,ct++;
      while(y%t==0)y/=t,ct2++;
      ll o=p;
      while(ct2>=ct)ct2--,o/=t;
      chkmax(ans,o);
    }
//    for(int t:fac){
//      ll s=p;
//      while(s%t==0)s/=t;
//      chkmax(ans,q/t*s);
//    }
    cout<<ans<<endl;
  }
}

signed main() {
  int T=read();
  while(T--)solve();
//  solve();
  return 0;
}