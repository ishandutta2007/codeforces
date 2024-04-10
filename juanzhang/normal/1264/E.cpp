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

namespace EK{
  static const int inf=INT_MAX;
  static const int maxN=30510;
  static const int maxM=1e5+10;
  int ecnt,h[maxN];
  struct edges{
    int nxt,to,w,c;
  }E[maxM];
  void addline(int u,int v,int w,int c){
    E[++ecnt]={h[u],v,w,c},h[u]=ecnt;
    E[++ecnt]={h[v],u,0,-c},h[v]=ecnt;
  }
  bool inq[maxN];
  int S,T,fl[maxN],dis[maxN],pre[maxN];
  void gnxt(int&x){if(++x==maxN)x=0;}
  bool spfa(){
    static int Q[maxN];
    memset(dis,0x3f,sizeof dis);
    int l=0,r=1;Q[0]=S,dis[S]=0,fl[S]=inf;
    while(l!=r){
      int u=Q[l];gnxt(l),inq[u]=0;
      for(int i=h[u];i;i=E[i].nxt){
        int v=E[i].to;
        if(E[i].w&&dis[v]>dis[u]+E[i].c){
          pre[v]=i,fl[v]=min(fl[u],E[i].w),dis[v]=dis[u]+E[i].c;
          if(!inq[v]){
            Q[r]=v,inq[v]=1;if(l!=r&&dis[Q[l]]>dis[Q[r]])swap(Q[l],Q[r]);gnxt(r);
          }
        }
      }
    }
    return dis[T]<1e9;
  }
  int EK(){
    int res=0;
    while(spfa()){
      res+=fl[T]*dis[T];
      for(int u=T;u!=S;u=E[pre[u]^1].to){
        E[pre[u]].w-=fl[T],E[pre[u]^1].w+=fl[T];
      }
    }
    return res;
  }
}

int N,M,A[105][105],emp[105][105],ans[105][105];

void solve(){
  cin>>N>>M;
  rep(i,1,N)rep(j,1,N)A[i][j]=i==j?0:2;
  rep(i,1,M){
    int u=read(),v=read();A[u][v]=1,A[v][u]=0;
  }
  EK::ecnt=1,EK::S=3*N*N+N+1,EK::T=EK::S+1;
  rep(i,1,N)rep(j,1,N)ans[i][j]=A[i][j];
  rep(i,1,N)rep(j,1,N)if(i<j){
    if(A[i][j]==0)EK::addline(EK::S,(i-1)*N+j,1,0);
    if(A[i][j]==1)EK::addline(EK::S,(N+i-1)*N+j,1,0);
    if(A[i][j]==2)EK::addline(EK::S,(N+N+i-1)*N+j,1,0),EK::addline((N+N+i-1)*N+j,(i-1)*N+j,1,0),EK::addline((N+N+i-1)*N+j,(N+i-1)*N+j,1,0),emp[i][j]=EK::ecnt;
  }
  rep(i,1,N){
    rep(j,i+1,N)EK::addline((i-1)*N+j,3*N*N+i,1,0);
    rep(j,1,i-1)EK::addline((N+j-1)*N+i,3*N*N+i,1,0);
    rep(j,1,N)EK::addline(3*N*N+i,EK::T,1,j*(j-1)/2-(j-1)*(j-2)/2);
  }
  EK::EK();
//  cout<<N*(N-1)*(N-2)/6-EK::EK()<<endl;
  rep(i,1,N)rep(j,1,N)if(i<j){
    if(A[i][j]==2)ans[j][i]=(ans[i][j]=EK::E[emp[i][j]].w)^1;
  }
  rep(i,1,N){
    rep(j,1,N)printf("%d",ans[i][j]);puts("");
  }
}

signed main(){
//  int T=read();
//  while(T--)solve();
  solve();
  return 0;
}