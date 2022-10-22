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
typedef vector<int>vi;
typedef pair<int,int>pii;
const int maxn=2e5+10;
int n,k,A[maxn],B[maxn],su[maxn],pmn[maxn];bool vis[maxn];

bool check(int mid){
  rep(i,1,n){
    B[i]=A[i]<mid?-1:1;
    su[i]=su[i-1]+B[i],pmn[i]=min(pmn[i-1],su[i]);
    if(i>=k&&su[i]>pmn[i-k])return 1;
  }
  return 0;
}

void solve(){
  cin>>n>>k;
  rep(i,1,n)A[i]=read(),vis[A[i]]=1;
  int l=1,r=n;
  while(l<r){
    int mid=(l+r+1)/2;
    check(mid)?l=mid:r=mid-1;
  }
  while(!vis[r])r--;
  cout<<r<<endl;
}

signed main(){
//  int T=read();
//  while(T--)solve();
  solve();
  return 0;
}