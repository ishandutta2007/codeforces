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
int n;

int abso(int x){
  return x<0?-x:x;
}

struct frac{
  int P,Q;
  void zzh(){
    int g=__gcd(abso(P),abso(Q));
    P/=g,Q/=g;
//    int s=(P<0)^(Q<0);
//    P=abso(P),Q=abso(Q);
//    if(s){
//      if(P)P=-P;
//      else Q=-Q;
//    }
  }
  frac get(){
    return {-P,-Q};
//    if(!P)return {0,-Q};
//    return {-P,Q};
  }
  ll gvz(){
    return 1000000007ll*P+Q;
  }
  void print(){
    printf("(%d %d)\n",P,Q);
  }
};

void solve(){
  cin>>n;ll ans=0;
  map<ll,int>ct;
  rep(i,1,n){
    int x=read(),y=read(),u=read(),v=read();
    frac tmp={u-x,v-y};
    tmp.zzh();
//    tmp.print();
    frac nx=tmp.get();
    ans+=ct[nx.gvz()];
    ++ct[tmp.gvz()];
  }
  cout<<ans<<endl;
}

signed main(){
  int T=read();
  while(T--)solve();
//  solve();
  return 0;
}