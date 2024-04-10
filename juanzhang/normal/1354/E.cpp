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
const int maxn=5010;
int n,m,k1,k2,k3,bl[maxn],col[maxn],cnt[maxn][2],ans[maxn],E[maxn][maxn];

bool dfs(int u,int c,int r){
  col[u]=c,bl[u]=r,cnt[r][c]++;
  rep(v,1,n)if(E[u][v]){
    if(c==col[v]||(col[v]==-1&&!dfs(v,c^1,r)))return 0;
  }
  return 1;
}

int dp[maxn][maxn];

void print(int pos,int k){
  if(!pos)return;
  if(bl[pos]!=pos)return print(pos-1,k),void();
  if(dp[pos][k]==1){
    ans[pos]=1,print(pos-1,k-cnt[pos][0]);
  }else if(dp[pos][k]==2){
    ans[pos]=2,print(pos-1,k-cnt[pos][1]);
  }else assert(0);
}

void solve() {
  cin>>n>>m>>k1>>k2>>k3;rep(i,1,m){
    int u=read(),v=read();E[u][v]=E[v][u]=1;
  }memset(col,-1,sizeof col);
  rep(i,1,n)if(col[i]==-1&&!dfs(i,0,i))return puts("NO"),void();
  dp[0][0]=-1;
  rep(i,1,n){
    if(bl[i]==i){
      rep(j,0,n){
        int c0=cnt[i][0],c1=cnt[i][1];
        if(j>=c0&&dp[i-1][j-c0])dp[i][j]=1;
        else if(j>=c1&&dp[i-1][j-c1])dp[i][j]=2;
      }
    }else{
      memcpy(dp[i],dp[i-1],sizeof dp[i]);
    }
  }
  if(!dp[n][k2])return puts("NO"),void();puts("YES");
  print(n,k2);
  rep(i,1,n){
    if(col[i]^(ans[bl[i]]==1)){
      putchar('2');
    }else{
      if(k1)putchar('1'),k1--;
      else putchar('3'),k3--;
    }
  }
}

signed main() {
//  int T=read();
//  while(T--)solve();
  solve();
  return 0;
}