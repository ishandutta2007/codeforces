#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=(a),i##end=(b);i<=i##end;++i)
#define per(i,a,b) for(int i=(a),i##end=(b);i>=i##end;--i)
//mt19937 Rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
template<typename T>void chkmax(T&x,T y){if(x<y)x=y;}
template<typename T>void chkmin(T&x,T y){if(x>y)x=y;}
inline int read(){
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
const int maxn=505*505;
int R,C,k,q,A[505][505];
struct node{
  int x,y,t;
}dat[maxn];

int su[505][505];
bool pd(int mid){
  memset(su,0,sizeof su);
  rep(i,1,q)if(dat[i].t<=mid){
    su[dat[i].x][dat[i].y]=1;
  }
  rep(i,1,R)rep(j,1,C){
    su[i][j]^=1;
    su[i][j]+=su[i][j-1]+su[i-1][j]-su[i-1][j-1];
    if(i>=k&&j>=k){
      if(su[i][j]-su[i-k][j]-su[i][j-k]+su[i-k][j-k]==0)return 1;
    }
  }
  return 0;
}

void solve(){
  cin>>R>>C>>k>>q;
  rep(i,1,q){
    dat[i].x=read(),dat[i].y=read(),dat[i].t=read();
  }
  sort(dat+1,dat+q+1,[](node P,node Q){
    return P.t<Q.t;
  });
  int l=0,r=1e9;
  while(l<r){
    int mid=(l+r)/2;
    pd(mid)?r=mid:l=mid+1;
  }
  if(!pd(l))puts("-1");
  else cout<<l<<endl;
}

signed main(){
//  int T=read();
//  while(T--)solve();
  solve();
  return 0;
}