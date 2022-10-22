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
int n,k;ll ans;
ll sqr(ll x){return x*x;}
struct node{
  int x,y;
  ll get()const{
    ll v1=(x%y*sqr(x/y+1))+(y-(x%y))*sqr(x/y);
    ll v2=(x%(y+1)*sqr(x/(y+1)+1))+((y+1)-(x%(y+1)))*sqr(x/(y+1));
    return v1-v2;
  }
  bool operator<(const node&o)const{return get()<o.get();}
};
priority_queue<node>Q;

void solve() {
  cin>>n>>k;rep(i,1,n){
    int x=read();ans+=sqr(x),Q.push({x,1});
  }k-=n;
  while(k--){
    node p=Q.top();Q.pop();
    ans-=p.get(),p.y++,Q.push(p);
  }
  cout<<ans<<endl;
}

signed main() {
//  int T=read();
//  while(T--)solve();
  solve();
  return 0;
}