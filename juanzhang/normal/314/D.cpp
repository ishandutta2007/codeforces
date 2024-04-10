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
int n;
struct point{
  ll x,y;
}A[maxn];

bool check(ll mid){
  static ll pmn[maxn],pmx[maxn],smn[maxn],smx[maxn];
  rep(i,1,n){
    pmn[i]=smn[i]=smx[i]=pmx[i]=A[i].y;
  }
  rep(i,2,n)chkmin(pmn[i],pmn[i-1]),chkmax(pmx[i],pmx[i-1]);
  per(i,n-1,1)chkmin(smn[i],smn[i+1]),chkmax(smx[i],smx[i+1]);
  for(int i=1,j=1;i<=n;i++){
    while(A[i].x-A[j].x>2*mid)j++;
    ll mx=-1e10,mn=1e10;
    if(j>1)chkmax(mx,pmx[j-1]),chkmin(mn,pmn[j-1]);
    if(i<n)chkmax(mx,smx[i+1]),chkmin(mn,smn[i+1]);
    if(mx-mn<=2*mid)return 1;
  }
  return 0;
}

void solve(){
  cin>>n;
  rep(i,1,n){
    ll x=read(),y=read();
    A[i].x=(x+y)*2,A[i].y=(x-y)*2;
  }
  sort(A+1,A+n+1,[](point X,point Y){
    return X.x<Y.x;
  });
  ll l=0,r=2e9;
  while(l<r){
    ll mid=(l+r)/2;
    check(mid)?r=mid:l=mid+1;
  }
  printf("%.10lf\n",l/2.0);
}

signed main(){
//  int T=read();
//  while(T--)solve();
  solve();
  return 0;
}