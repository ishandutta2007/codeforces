#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=(a),i##end=(b);i<=i##end;++i)
#define per(i,a,b) for(int i=(a),i##end=(b);i>=i##end;--i)
//mt19937 Rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
template<typename T>void chkmax(T&x,T y){if(x<y)x=y;}
template<typename T>void chkmin(T&x,T y){if(x>y)x=y;}

typedef double db;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
inline ll read(){
  #define nc getchar()
  bool f=0;ll x=0;char c=nc;
  while(c<48)f|=c=='-',c=nc;
  while(c>47)x=x*10+(c^48),c=nc;
  return f?-x:x;
  #undef nc
}
const int maxn=5e5+10;
const int P=1e9+7;
int n,ct[60],pw2[60];
ll A[maxn];

void solve(){
  cin>>n;
  memset(ct,0,sizeof ct);
  rep(i,1,n)A[i]=read();
  rep(i,1,n)rep(j,0,59)ct[j]+=A[i]>>j&1;
  int ans=0;
  rep(i,1,n){
    int s1=0,s2=0;
    rep(j,0,59){
      if(A[i]>>j&1)s1=(s1+1ll*ct[j]*pw2[j])%P,s2=(s2+1ll*n*pw2[j])%P;
      else s2=(s2+1ll*ct[j]*pw2[j])%P;
    }
//    rep(j,1,n)s1=(s1+(A[i]&A[j]))%P,s2=(s2+(A[i]|A[j]))%P;
    ans=(ans+1ll*s1*s2)%P;
  }
  cout<<ans<<endl;
}

signed main(){
  pw2[0]=1;
  rep(i,1,59)pw2[i]=2ll*pw2[i-1]%P;
  int T=read();
  while(T--)solve();
//  solve();
  return 0;
}