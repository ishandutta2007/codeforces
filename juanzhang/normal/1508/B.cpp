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
const int maxn=2e5+10;
int n,ans[maxn];ll k;bool asf;

void dfs(int n,ll k,int*ans,int del){
  if(!n){
    asf=k==0;
    return;
  }
  if(n==1){
    asf=k==1,ans[1]=del+1;return;
  }
  if(n>61){
    ans[1]=del+1,dfs(n-1,k,ans+1,del+1);return;
  }
  ll t=1ll<<(n-2),cur=t,lst=0;int v=1;
  while(t<k){
    lst=t,t+=cur>>=1,v++;
    if(cur==0){
      t++;break;
    }
  }
//  printf("(%d %lld %lld) %d\n",n,k,t,v);
  if(t<k){
    asf=0;return;
  }
  rep(i,1,v)ans[i]=del+v-i+1;
  if(v==n)return;
  dfs(n-v,k-lst,ans+v,del+v);
}

void solve(){
  cin>>n>>k,asf=1;
  dfs(n,k,ans,0);
  if(!asf){
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