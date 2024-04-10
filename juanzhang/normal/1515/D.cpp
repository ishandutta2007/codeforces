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
int n,L,R,c1[maxn],c2[maxn];

void solve(){
  cin>>n>>L>>R;
  rep(i,1,n)c1[i]=c2[i]=0;
  rep(i,1,L){
    c1[read()]++;
  }
  rep(i,1,R){
    c2[read()]++;
  }
  int ans=0;
  L=R=0;
  rep(i,1,n){
    int t=min(c1[i],c2[i]);
    c1[i]-=t,c2[i]-=t;
//    if(c1[i]){
//      t=c1[i]/2;
//      ans+=t,c1[i]-=t*2;
//    }
//    if(c2[i]){
//      t=c2[i]/2;
//      ans+=t,c2[i]-=t*2;
//    }
    L+=c1[i],R+=c2[i];
  }
  if(L<R)swap(L,R),swap(c1,c2);
  ans+=R,L-=R;
  rep(i,1,n){
    if(c1[i]%2==1&&R)c1[i]--,R--;
  }
  rep(i,1,n){
    while(c1[i]&&R)c1[i]--,R--;
  }
  rep(i,1,n){
    ans+=c1[i]/2,L-=c1[i]/2*2;
  }
  ans+=L;
////  if(L<R)swap(L,R);
////  assert(!L);
////  assert(L%2==0);
//  ans+=L+R;
  cout<<ans<<endl;
}

signed main(){
  int T=read();
  while(T--)solve();
//  solve();
  return 0;
}