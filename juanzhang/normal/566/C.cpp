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

typedef long double db;
typedef long long ll;
typedef vector<int>vi;
typedef pair<int,int>pii;
const int maxn=2e5+10;
int n,w[maxn];
int ecnt=1,h[maxn];
struct edges{int nxt,to,w;}E[maxn<<1];
void addline(int u,int v,int w){
  E[++ecnt]={h[u],v,w},h[u]=ecnt;
}

db ans=1e30;int au=-1;
db v1[maxn],v2[maxn];
int sumsz,sss,srt,sz[maxn];
bool used[maxn];
void findc(int u,int f){
  sz[u]=1;int tp=0;
  for(int i=h[u];i;i=E[i].nxt){
    int v=E[i].to;
    if(v!=f&&!used[v])findc(v,u),sz[u]+=sz[v],chkmax(tp,sz[v]);
  }
  chkmax(tp,sumsz-sz[u]);
  if(sss>tp)sss=tp,srt=u;
}
void dfs(int u,int f,int d,int bl){
  v1[bl]+=d*sqrt((db)d)*w[u],v2[bl]+=1.5*sqrt(db(d))*w[u];
  for(int i=h[u];i;i=E[i].nxt){
    int v=E[i].to;
    if(v!=f)dfs(v,u,d+E[i].w,bl);
  }
}
void divide(int rt){
  sss=1e9,findc(rt,0),rt=srt;
  db tsu=0,tas=0;
  for(int i=h[rt];i;i=E[i].nxt){
    int v=E[i].to;
    v1[v]=v2[v]=0,dfs(v,rt,E[i].w,v),tas+=v1[v],tsu+=v2[v];
  }
  if(tas<ans)ans=tas,au=rt;
  used[rt]=1;
  for(int i=h[rt];i;i=E[i].nxt){
    int v=E[i].to;
    if(!used[v]&&tsu-2*v2[v]<0){
      sumsz=sz[v],divide(v);break;
    }
  }
}

void solve(){
  cin>>n;
  rep(i,1,n)w[i]=read();
  rep(i,2,n){
    int u=read(),v=read(),w=read();addline(u,v,w),addline(v,u,w);
  }
  sumsz=n,divide(1);
  printf("%d %.10lf\n",au,(double)ans);
}

signed main(){
//  int T=read();
//  while(T--)solve();
  solve();
  return 0;
}