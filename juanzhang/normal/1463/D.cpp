#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=(a),i##end=(b);i<=i##end;++i)
#define per(i,a,b) for(int i=(a),i##end=(b);i>=i##end;--i)
//mt19937 Rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
template<typename T>void chkmax(T&x,T y){if(x<y)x=y;}
template<typename T>void chkmin(T&x,T y){if(x>y)x=y;}
inline int read(){
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
const int maxn=4e5+10;
int n,B[maxn],lef[maxn],rig[maxn],pr[maxn],sf[maxn];

void solve(){
  cin>>n;
  pr[0]=sf[n+1]=1e9;
  rep(i,1,n)B[i]=read(),lef[i]=B[i]-i-i,rig[i]=(n+n-B[i])-(n-i)+i;
  int res=0;
  rep(i,1,n){
    pr[i]=min(pr[i-1],rig[i]);
  }
  per(i,n,1){
    sf[i]=min(sf[i+1],lef[i]);
  }
  rep(i,0,n){
    res+=pr[i]>=i+1&&sf[i+1]>=-i;
  }
  cout<<res<<endl;
}

signed main(){
  int T=read();
  while(T--)solve();
//  solve();
  return 0;
}