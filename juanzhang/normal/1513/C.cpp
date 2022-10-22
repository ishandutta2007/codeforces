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
const int P=1e9+7,maxn=4e5+10;
int dp[10][maxn];

void solve(){
  int n,m;
  scanf("%d%d",&n,&m);
  int dat[20],len=0;
  while(n)dat[++len]=n%10,n/=10;
  ll res=0;
  rep(i,1,len){
    res+=dp[dat[i]][m];
  }
  printf("%lld\n",res%P);
}

signed main(){
  rep(k,0,200000)rep(i,0,9){
    if(!k){
      dp[i][k]=1;
    }else{
      if(i<9){
        dp[i][k]=dp[i+1][k-1];
      }else{
        dp[i][k]=(dp[1][k-1]+dp[0][k-1])%P;
      }
    }
  }
  int T=read();
  while(T--)solve();
//  solve();
  return 0;
}