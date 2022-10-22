#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = (a), i##end = (b); i <= i##end; ++i)
#define per(i, a, b) for (int i = (a), i##end = (b); i >= i##end; --i)

mt19937 Rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

template <typename T>
inline void chkmax(T &x, T y) { if (x < y) x = y; }

template <typename T>
inline void chkmin(T &x, T y) { if (x > y) x = y; }

inline int read() {
  #define nc getchar()
  int x = 0;
  char c = nc;
  while (c < 48) c = nc;
  while (c > 47) x = x * 10 + (c ^ 48), c = nc;
  return x;
  #undef nc
}

typedef long long ll;
typedef pair <int, int> pii;
const int maxn = 1010;
int n, k, A[maxn];
char str[maxn];

bool ise[20010];
int tot,fail[20010],ch[20010][9];

int dp[2][20010];

bool isd[25];
int P[25], sum[25];

void ins(int len){
  int cur=0;
  rep(i,1,len){
    int &x=ch[cur][P[i]-1];
    cur=x?x:x=++tot;
  }
  ise[cur]=1;
}

void build(){
  static int Q[20010];
  int l=1,r=0;
  rep(i,0,9)if(ch[0][i]){
    Q[++r]=ch[0][i];
  }
  while(l<=r){
    int u=Q[l++];
    rep(i,0,9){
      int &v=ch[u][i],k=fail[u];
      v?fail[v]=ch[k][i],Q[++r]=v:v=ch[k][i];
    }
  }
}

void dfs(int now){
  if(now>1)rep(i,1,now-1){
    if(isd[sum[now-1]-sum[i-1]])return;
  }
  if(sum[now-1]==k){
    ins(now-1);
    return;
  }
  rep(i,1,9)if(sum[now-1]+i<=k){
    P[now]=i,sum[now]=sum[now-1]+i,dfs(now+1);
  }
}

void solve() {
  scanf("%s %d", str + 1, &k);
  n = strlen(str + 1);
  rep(i,1,n)A[i]=str[i]-'1';
  rep(i, 1, k-1)if(k%i==0){
    isd[i]=1;
  }
  dfs(1);
  build();
  int sel=1;
  memset(dp,0x3f,sizeof dp);
  dp[0][0]=0;
  rep(i,1,n){
    memset(dp[sel],0x3f,sizeof dp[sel]);
    rep(j,0,tot){
      int x=ch[j][A[i]];
      chkmin(dp[sel][j],dp[sel^1][j]+1);
      if(!ise[x])chkmin(dp[sel][x],dp[sel^1][j]);
    }
    sel^=1;
  }
  int res=2e9;
  rep(i,0,tot)chkmin(res,dp[sel^1][i]);
  cout<<res<<endl;
}

signed main() {
//  int T = read();
//  while (T--) solve();
  solve();
  return 0;
}