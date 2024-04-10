#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=(a),i##end=(b);i<=i##end;++i)
#define per(i,a,b) for(int i=(a),i##end=(b);i>=i##end;--i)
mt19937 Rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
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
const int maxn=1010;
int n,A[maxn],su[maxn][8],dp[maxn][1<<8];

bool check(int mid){
  rep(i,1,n){
    memcpy(dp[i],dp[i-1],1<<10);
    rep(num,0,7){
      int p1=-1,p2=-1;
      rep(j,1,i)if(su[i][num]-su[j-1][num]>=mid)p1=j;
      rep(j,1,i)if(su[i][num]-su[j-1][num]>=mid+1)p2=j;
      if(p1==-1&&p2==-1)continue;
      rep(S,0,255)if(~S>>num&1){
        chkmax(dp[i][S|1<<num],dp[p1-1][S]+mid);
        if(p2!=-1)chkmax(dp[i][S|1<<num],dp[p2-1][S]+mid+1);
      }
    }
    if(!mid)rep(S,0,255)chkmax(dp[i][S],0);
  }
  if(!mid)rep(S,0,255)chkmax(dp[n][255],dp[n][S]);
  return dp[n][255]>0;
}

void solve(){
  cin>>n;
  rep(i,1,n)A[i]=read()-1,memcpy(su[i],su[i-1],32),su[i][A[i]]++;
  memset(dp,-0x3f,sizeof dp),dp[0][0]=0;
  int l=0,r=n/8;
  while(l<r){
    int mid=(l+r+1)/2;
    check(mid)?l=mid:r=mid-1;
  }
  check(r);
  printf("%d\n",dp[n][(1<<8)-1]);
}

signed main(){
//  int T=read();
//  while(T--)solve();
  solve();
  return 0;
}