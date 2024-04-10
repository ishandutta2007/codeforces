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
const int maxn=1<<17|5;
int n,su[maxn][20];
int now,tim[maxn<<2][20],dp[maxn<<2][20];
char str[maxn];

int calc(int l,int r,int c){
  return su[r][c]-su[l-1][c];
}
int dfs(int k,int l,int r,int c){
  if(l==r)return str[l]!=c+'a';
  if(tim[k][c]==now)return dp[k][c];
  tim[k][c]=now;int mid=(l+r)/2;
  return dp[k][c]=min(calc(l,mid,c)+dfs(k<<1|1,mid+1,r,c+1),dfs(k<<1,l,mid,c+1)+calc(mid+1,r,c));
}

void solve() {
  now++;
  cin>>n;
  scanf("%s",str+1);
  rep(i,1,n){
    rep(j,0,19){
      su[i][j]=su[i-1][j]+(str[i]!='a'+j);
    }
  }
  cout<<dfs(1,1,n,0)<<endl;
}

signed main() {
  int T=read();
  while(T--)solve();
//  solve();
  return 0;
}