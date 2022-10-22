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
typedef pair<ll,int>qnod;
const int maxn=8e5+10;
int n,m;

int ecnt=1,h[maxn];
struct edges{
  int nxt,to,w;
}E[maxn<<2];
void addline(int u,int v,int w){
  E[++ecnt]={h[u],v,w},h[u]=ecnt;
}
ll dis[maxn],ans[maxn];

priority_queue<qnod,vector<qnod>,greater<qnod>>Q;

void solve(){
  cin>>n>>m;
  rep(i,1,m){
    int u=read(),v=read(),w=read();
    rep(j,0,3)addline(j*n+u,j*n+v,w),addline(j*n+v,j*n+u,w);
    rep(S,0,3){
      if(~S&1)addline(S*n+u,(S|1)*n+v,0),addline(S*n+v,(S|1)*n+u,0);
      if(~S>>1&1)addline(S*n+u,(S+2)*n+v,2*w),addline(S*n+v,(S+2)*n+u,2*w);
    }
  }
  memset(dis,0x3f,sizeof dis);
  memset(ans,0x3f,sizeof ans);
  dis[1]=0,Q.push({0,1});
  while(!Q.empty()){
    qnod p=Q.top();Q.pop();int u=p.second;
    if(dis[u]<p.first)continue;
    for(int i=h[u];i;i=E[i].nxt){
      int v=E[i].to;
      if(u==1)chkmin(ans[v],(ll)E[i].w);
      if(dis[v]>dis[u]+E[i].w){
        dis[v]=dis[u]+E[i].w,Q.push({dis[v],v});
      }
    }
  }
  rep(i,2,n)printf("%I64d ",min(ans[i],dis[3*n+i]));
}

signed main(){
//  int T=read();
//  while(T--)solve();
  solve();
  return 0;
}