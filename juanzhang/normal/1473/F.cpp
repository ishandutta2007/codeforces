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

namespace Dinic{
  static const int inf=1e9+1;
  static const int maxN=3055;
  static const int maxM=1e6+10;
  int ecnt,h[maxN];
  struct edges{
    int nxt,to,w;
  }E[maxM];
  void addline(int u,int v,int w){
    E[++ecnt]={h[u],v,w},h[u]=ecnt;
    E[++ecnt]={h[v],u,0},h[v]=ecnt;
  }
  // ecnt=1,S,T
  int S,T,cur[maxN],dis[maxN];
  bool bfs(){
    static int Q[maxN];
    memcpy(cur,h,sizeof h);
    memset(dis,-1,sizeof dis);
    int l=1,r=1;Q[1]=S,dis[S]=0;
    while(l<=r){
      int u=Q[l++];
      for(int i=h[u];i;i=E[i].nxt){
        int v=E[i].to;
        if(E[i].w&&dis[v]==-1)dis[v]=dis[u]+1,Q[++r]=v;
      }
    }
    return dis[T]!=-1;
  }
  int dfs(int u,int fl){
    if(u==T||!fl)return fl;
    int res=0,tp=-1;
    for(int&i=cur[u];i&&fl;i=E[i].nxt){
      int v=E[i].to;
      if(E[i].w&&dis[v]==dis[u]+1){
        if(!(tp=dfs(v,min(fl,E[i].w))))dis[v]=-1;
        else E[i].w-=tp,E[i^1].w+=tp,res+=tp,fl-=tp;
      }
    }
    return res;
  }
  int dinic(){
    int res=0,tp=-1;
    while(bfs()){
      while((tp=dfs(S,inf)))res+=tp;
    }
    return res;
  }
}

int n,lst[101],A[3030],B[3030];

void solve(){
  cin>>n;
  Dinic::ecnt=1,Dinic::S=n+1,Dinic::T=n+2;
  rep(i,1,n){
    A[i]=read();
    rep(j,lst[A[i]],i-1)if(j&&A[i]%A[j]==0)Dinic::addline(i,j,Dinic::inf);
    lst[A[i]]=i;
  }
  int sum=0;
  rep(i,1,n){
    B[i]=read();
    if(B[i]>=0){
      sum+=B[i];
      Dinic::addline(Dinic::S,i,B[i]);
    }else{
      Dinic::addline(i,Dinic::T,-B[i]);
    }
  }
  cout<<sum-Dinic::dinic()<<endl;
}

signed main(){
//  int T=read();
//  while(T--)solve();
  solve();
  return 0;
}