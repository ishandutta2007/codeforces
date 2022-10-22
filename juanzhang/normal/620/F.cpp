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
typedef vector<int> vi;
typedef pair<int,int> pii;
const int maxn=5e4+10;
int n,q,A[maxn],F[1<<20],QL[5050],QR[5050],val[maxn],tmp[maxn],ans[5050];

void solve(){
  rep(i,1,(1<<20)-1)F[i]=F[i-1]^i;
  cin>>n>>q;
  rep(i,1,n)A[i]=read(),tmp[i]=F[A[i]];
  rep(i,1,q)QL[i]=read(),QR[i]=read();
  rep(i,1,n){
    val[i-1]=0;
    rep(j,i,n)val[j]=max(val[j-1],tmp[i]^tmp[j]^min(A[i],A[j]));
    rep(j,1,q)if(QL[j]<=i)chkmax(ans[j],val[QR[j]]);
  }
  rep(i,1,q)printf("%d\n",ans[i]);
}

signed main(){
//  int T=read();
//  while(T--)solve();
  solve();
  return 0;
}