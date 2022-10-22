#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = (a), i##end = (b); i <= i##end; ++i)
#define per(i, a, b) for (int i = (a), i##end = (b); i >= i##end; --i)
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
typedef pair<ll,int> pii;
const int maxn=2e5+10;
int n,m,q;

int h[maxn];
struct edges{int nxt,to,w;}E[maxn<<1];
void addline(int u,int v,int w){
  static int ecnt=1;
  E[++ecnt]={h[u],v,w},h[u]=ecnt;
}
ll dis[maxn],sid[maxn];int pre[maxn],erp[maxn],len,path[maxn],pp[maxn];bool eop[maxn<<1];
void dijkstra(int S,ll*dis,int*pre,int opt){
  priority_queue<pii,vector<pii>,greater<pii> >Q;
  memset(dis,0x3f,(n+1)<<3),dis[S]=0,Q.push({0,S});
  while(!Q.empty()){
    pii p=Q.top();int u=p.second;Q.pop();
    if(dis[u]!=p.first)continue;
    if(opt&&pp[u])pre[u]=u;
    for(int i=h[u];i;i=E[i].nxt){
      int v=E[i].to;
      if(dis[v]>dis[u]+E[i].w)dis[v]=dis[u]+E[i].w,pre[v]=!opt?i:pre[u],Q.push({dis[v],v});
    }
  }
}

ll st[maxn][18];int lg[maxn];
void upd(int l,int r,ll v){
  int k=lg[r-l+1];chkmin(st[l][k],v),chkmin(st[r-(1<<k)+1][k],v);
}
void build(){
  per(j,17,1)rep(i,1,n-(1<<j)+1)chkmin(st[i][j-1],st[i][j]),chkmin(st[i+(1<<(j-1))][j-1],st[i][j]);
}

void solve() {
  cin>>n>>m>>q;
  rep(i,1,m){
    int u=read(),v=read(),w=read();addline(u,v,w),addline(v,u,w);
  }
  dijkstra(1,dis,pre,0);
  for(int u=n;u;u=E[pre[u]^1].to){
    path[++len]=u,eop[pre[u]^1]=eop[pre[u]]=1;
  }
  reverse(path+1,path+len+1);
  rep(i,1,len)pp[path[i]]=i;
  dijkstra(1,dis,pre,1),dijkstra(n,sid,erp,1);
  rep(i,2,n)lg[i]=lg[i>>1]+1;memset(st,0x3f,sizeof st);
  rep(i,2,m*2)if(i%2==0&&!eop[i]){
    int u=E[i].to,v=E[i^1].to;
    if(dis[u]+sid[v]>dis[v]+sid[u])swap(u,v);
    int l=pp[pre[u]],r=pp[erp[v]];
    if(l>r)swap(l,r);
    if(l!=r)upd(l,r-1,dis[u]+sid[v]+E[i].w);
  }
  build();
  while(q--){
    int t=read()*2,x=read();
    int u=E[t].to,v=E[t^1].to;
    if(dis[u]+sid[v]>dis[v]+sid[u])swap(u,v);
    ll ans=min(eop[t]?st[pp[u]][0]:dis[n],dis[u]+sid[v]+x);
    printf("%I64d\n",ans);
  }
}

signed main() {
//  int T=read();
//  while(T--)solve();
  solve();
  return 0;
}