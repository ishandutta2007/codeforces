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
int n,k,ans[1010];bool vis[1010];

void solve(){
  memset(vis,0,sizeof vis);
  cin>>n>>k;
  if(k>n/2){
    puts("-1");
    return;
  }
  int tpk=k;
  int cur=0,l=1,r=n;
  while(k--){
    if(l>=r){
      puts("-1");
      return;
    }
    vis[l]=vis[r]=1;
    ans[++cur]=l++,ans[++cur]=r--;
  }
  rep(i,cur+1,n){
    rep(j,1,n)if(!vis[j]){
      vis[j]=1,ans[i]=j;break;
    }
  }
  int ct=0;
  rep(i,2,n-1)ct+=ans[i]>ans[i-1]&&ans[i]>ans[i+1];
  if(ct!=tpk){
    puts("-1");return;
  }
  rep(i,1,n)printf("%d%c",ans[i],"\n "[i<n]);
}

signed main(){
  int T=read();
  while(T--)solve();
//  solve();
  return 0;
}