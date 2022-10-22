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
const int maxn=2e5+10,P=1e9+7;
int n,A[maxn],fac[maxn];

void solve(){
  cin>>n;
  rep(i,1,n)A[i]=read();
  sort(A+1,A+n+1);
  bool flg=A[1]==A[2];
  rep(i,1,n)flg&=(A[i]&A[1])==A[1];
  if(!flg){
    puts("0");return;
  }
  int ct=0;
  rep(i,1,n)ct+=A[i]==A[1];
  fac[0]=1;
  rep(i,1,n)fac[i]=1ll*i*fac[i-1]%P;
  cout<<1ll*ct*(ct-1)%P*fac[n-2]%P<<endl;
}

signed main(){
  int T=read();
  while(T--)solve();
//  solve();
  return 0;
}