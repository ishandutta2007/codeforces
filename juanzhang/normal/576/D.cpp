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
int n,m;
struct edge{
  int u,v,w;
}E[150];

struct lsj{
  bitset<150>arr[150];
  void clear(){rep(i,0,n-1)arr[i].reset();}
  bitset<150>&operator[](const int&pos){return arr[pos];}
}I,gr,M;

lsj operator*(lsj A,lsj B){
  static lsj res;res.clear();
  static lsj ttt;
  rep(i,0,n-1)rep(j,0,n-1)ttt[j][i]=B[i][j];
  rep(i,0,n-1)rep(j,0,n-1)res[i][j]=(A[i]&ttt[j]).count();
//  rep(k,0,n-1)rep(i,0,n-1)rep(j,0,n-1)if(!res[i][j]&&A[i][k]&&B[k][j])res[i][j]=1;
  return res;
}

lsj getnxt(lsj M,lsj gr){
  static lsj res;res.clear();
  rep(k,0,n-1)rep(j,0,n-1)if(!res[0][j]&&M[0][k]&&gr[k][j])res[0][j]=1;
  return res;
}

lsj qp(lsj A,int k){
  lsj res=I;
  for(;k;k>>=1,A=A*A)if(k&1)res=res*A;
  return res;
}

int cur,ans=-1;

void pd(){
  lsj mp=M;int res=-1;
  rep(T,0,n-1){
    if(mp[0][n-1]){
      res=cur+T;break;
    }
    mp=getnxt(mp,gr);
  }
  if(res!=-1&&(ans==-1||ans>res))ans=res;
}

void solve() {
  cin>>n>>m;
  rep(i,0,n-1)I[i][i]=1;
  rep(i,0,m-1){
    E[i].u=read()-1,E[i].v=read()-1,E[i].w=read();
  }
  sort(E,E+m,[](edge P,edge Q){
    return P.w<Q.w;
  });
  M[0][0]=1;
  rep(i,0,m-1){
    int u=E[i].u,v=E[i].v,w=E[i].w;
    M=getnxt(M,qp(gr,w-cur)),cur=w;
    gr[u][v]=1;
    pd();
  }
  if(ans==-1){
    puts("Impossible");
  }else{
    printf("%d\n",ans);
  }
}

signed main() {
//  int T=read();
//  while(T--)solve();
  solve();
  return 0;
}