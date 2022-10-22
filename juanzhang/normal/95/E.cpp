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
const int maxn=1e5+10;
int n,m,par[maxn],sz[maxn];
int find(int x){return par[x]==x?x:par[x]=find(par[x]);}
void unite(int x,int y){
  if((x=find(x))!=(y=find(y))){
    if(sz[x]<sz[y])swap(x,y);
    par[y]=x,sz[x]+=sz[y];
  }
}
int tot,A[1010],B[1010],ct[maxn],dp[maxn];

void solve(){
  cin>>n>>m;
  rep(i,1,n)par[i]=i,sz[i]=1;rep(i,1,m){
    int u=read(),v=read();unite(u,v);
  }
  rep(i,1,n)if(find(i)==i){
    ct[sz[i]]++;
  }
  memset(dp,0x3f,sizeof dp),dp[0]=0;
  rep(i,1,n)if(ct[i])A[++tot]=i,B[tot]=ct[i];
  rep(i,1,tot){
    int x=A[i],y=B[i];
    for(int p=1;p<=y;p<<=1){
      int xx=p*x;y-=p;
      per(j,n,xx)chkmin(dp[j],dp[j-xx]+p);
    }
    if(!y)continue;
    x*=y;
    per(j,n,x)chkmin(dp[j],dp[j-x]+y);
  }
  int ans=1e9;
  rep(i,1,n)if(dp[i]<=n){
    bool flg=1;
    int x=i;
    while(x)flg&=x%10==4||x%10==7,x/=10;
    if(flg)chkmin(ans,dp[i]-1);
  }
  printf("%d\n",ans<=n?ans:-1);
}

signed main(){
//  int T=read();
//  while(T--)solve();
  solve();
  return 0;
}