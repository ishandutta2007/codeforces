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
int n,dp[maxn][2];
char str[maxn];

void solve(){
  scanf("%s",str+1);
  n=strlen(str+1);
  int ans=0;
  static bool vis[maxn];
  rep(i,1,n){
    if((str[i]==str[i-1]&&!vis[i-1])||(i>1&&str[i]==str[i-2]&&!vis[i-2])){
      vis[i]=1,ans++;
    }
  }
  rep(i,1,n)vis[i]=0;
//  rep(i,1,n){
//    bool f1=str[i]==str[i-1];
//    bool f2=i>1&&str[i]==str[i-2];
//    if(!f1&&!f2){
//      dp[i][0]=dp[i-1][0],dp[i][1]=dp[i-1][1]+1;continue;
//    }
//    if(f1&&f2){
//      dp[i][0]=dp[i-2][1],dp[i][1]=dp[i-1][str]+1;
//      continue;
//    }
//  }
//  ans=min(dp[n][0],dp[n][1]);
//  rep(i,0,n+1)rep(j,0,3)dp[i][j]=1e9;
//  dp[0][0]=0;
//  rep(i,1,n){
//    if(str[i]==str[i-1]){
//      
//    }
//  }
//  int ans=1e9;
//  rep(i,0,3)chkmin(ans,dp[n][i]);
  cout<<ans<<endl;
}

signed main(){
  int T=read();
  while(T--)solve();
//  solve();
  return 0;
}