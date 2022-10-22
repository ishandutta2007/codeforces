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
int n,m,P,Q;
struct edge{
  int u,v,x,y;
}E[50010];
int par[205];
int find(int x){
  return par[x]==x?x:par[x]=find(par[x]);
}
int ecnt=1,h[205];
struct edges{
  int nxt,to,w;
}G[110010];
void addline(int u,int v,int w){
  G[++ecnt]={h[u],v,w},h[u]=ecnt;
}

int len,path[205];
void get(int S,int T){
  static int Q[205],pre[205];
  memset(pre,-1,sizeof pre);
  int l=1,r=1;Q[1]=S,pre[S]=0;
  while(l<=r){
    int u=Q[l++];
    for(int i=h[u];i;i=G[i].nxt){
      int v=G[i].to;
      if(pre[v]==-1)pre[v]=i,Q[++r]=v;
      if(v==T){
        for(int k=T;k!=S;k=G[pre[k]^1].to)path[++len]=pre[k];
        return;
      }
    }
  }
}
void erase(int u,int v){
  if(G[h[u]].to==v)h[u]=G[h[u]].nxt;
  else{
    for(int i=h[u];i;i=G[i].nxt)if(G[G[i].nxt].to==v){
      G[i].nxt=G[G[i].nxt].nxt;break;
    }
  }
}

void solve() {
  cin>>n>>m>>P>>Q;
  rep(i,1,m){
    E[i].u=read(),E[i].v=read(),E[i].x=read(),E[i].y=read();
  }
  sort(E+1,E+m+1,[](edge P,edge Q){
    return P.x<Q.x;
  });
  ll ans=3e18;int now=n;
  rep(i,1,n)par[i]=i;
  multiset<int>S;
  rep(i,1,m){
    int u=E[i].u,v=E[i].v;
    if(find(u)!=find(v)){
      par[find(u)]=find(v),addline(u,v,E[i].y),addline(v,u,E[i].y),S.insert(E[i].y),now--;
    }else if(u!=v){
      len=0,get(u,v);
      int pos=0;
      rep(j,1,len)if(G[path[j]].w>G[path[pos]].w)pos=j;
      int p=path[pos];
      if(G[p].w>E[i].y){
        erase(G[p].to,G[p^1].to),erase(G[p^1].to,G[p].to);
        S.erase(S.find(G[p].w));
        addline(u,v,E[i].y),addline(v,u,E[i].y);
        S.insert(E[i].y);
      }
    }
    if(now==1)chkmin(ans,1ll*P*E[i].x+1ll*Q*(*S.rbegin()));
  }
  printf("%lld\n",ans>2e18?-1:ans);
}

signed main() {
//  int T=read();
//  while(T--)solve();
  solve();
  return 0;
}