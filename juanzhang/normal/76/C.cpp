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
const int maxn=2e5+10;
int n,k,L;
int c[22],d[22][22];ll dp[1<<22];
char str[maxn];

void solve() {
  scanf("%d %d %d %s",&n,&k,&L,str+1);
  rep(i,0,k-1)scanf("%d",c+i);
  rep(i,0,k-1)rep(j,0,k-1)scanf("%d",&d[i][j]);
  static int lst[26],ct[maxn][26];int vvv=0;
  rep(i,1,n){
    int x=str[i]-'A';vvv|=1<<x;
    rep(ch,0,k-1){
      ct[i][ch]=ct[i-1][ch]+(ch==x);
      int j=lst[ch];
      if(j){
        int S=0,v=d[ch][x];
        rep(p,0,k-1)if(ct[i-1][p]>ct[j][p])S|=1<<p;
        if((~S>>x&1)&&(~S>>ch&1)){
          dp[S]+=v,dp[S|1<<x]-=v,dp[S|1<<ch]-=v,dp[S|1<<x|1<<ch]+=v;
        }
      }
    }
    lst[x]=i;
  }
  rep(i,0,k-1)rep(S,0,(1<<k)-1)if(S>>i&1)dp[S]+=dp[S^(1<<i)];
  int res=0;
  rep(S,0,(1<<k)-1)if((S&vvv)!=vvv&&(vvv&S)==S){
    ll sum=dp[S];
//    printf("#%lld\n",sum);
    rep(i,0,k-1)if(S>>i&1)sum+=c[i];
    res+=sum<=L;
  }
  cout<<res<<endl;
}

signed main() {
//  int T=read();
//  while(T--)solve();
  solve();
  return 0;
}