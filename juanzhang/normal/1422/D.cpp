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
typedef pair<int,int> pii;
const int maxn=1e5+10;
int m,Sx,Sy,Fx,Fy,cntx,cnty;
struct point{
  int x,y;
}A[maxn];

int h[maxn<<1];
struct edges{
  int nxt,to,w;
}E[maxn*6];
void addline(int u,int v,int w){
  static int ecnt=1;
  E[++ecnt]={h[u],v,w},h[u]=ecnt;
  E[++ecnt]={h[v],u,w},h[v]=ecnt;
}
int dis[maxn<<1];
vector<int>Vx[maxn],Vy[maxn];

void solve() {
  int tmpn;cin>>tmpn>>m>>Sx>>Sy>>Fx>>Fy;
  rep(i,1,m){
    A[i].x=read(),A[i].y=read();
  }
  static int datx[maxn],daty[maxn];
  rep(i,1,m)datx[++cntx]=A[i].x;datx[++cntx]=Sx,datx[++cntx]=Fx;
  sort(datx+1,datx+cntx+1);cntx=unique(datx+1,datx+cntx+1)-datx-1;
  rep(i,1,m)A[i].x=lower_bound(datx+1,datx+cntx+1,A[i].x)-datx;
  rep(i,1,m)daty[++cnty]=A[i].y;daty[++cnty]=Sy,daty[++cnty]=Fy;
  sort(daty+1,daty+cnty+1);cnty=unique(daty+1,daty+cnty+1)-daty-1;
  rep(i,1,m)A[i].y=lower_bound(daty+1,daty+cnty+1,A[i].y)-daty;
  rep(i,1,m)Vx[A[i].x].push_back(A[i].y),Vy[A[i].y].push_back(A[i].x);
  rep(i,1,cntx-1)addline(i,i+1,datx[i+1]-datx[i]);
  rep(i,1,cnty-1)addline(cntx+i,cntx+i+1,daty[i+1]-daty[i]);
  rep(i,1,m)addline(A[i].x,cntx+A[i].y,0);
  int ans=abs(Fx-Sx)+abs(Fy-Sy);
  priority_queue<pii,vector<pii>,greater<pii> >Q;
  rep(i,1,cntx+cnty)dis[i]=2e9;
  int st1=lower_bound(datx+1,datx+cntx+1,Sx)-datx;
  int st2=lower_bound(daty+1,daty+cnty+1,Sy)-daty;
  dis[st1]=0,Q.push({0,st1}),dis[cntx+st2]=0,Q.push({0,cntx+st2});
  while(!Q.empty()){
    pii p=Q.top();int u=p.second;Q.pop();
    if(p.first!=dis[u])continue;
    for(int i=h[u];i;i=E[i].nxt){
      int v=E[i].to;
      if(dis[v]>dis[u]+E[i].w)dis[v]=dis[u]+E[i].w,Q.push({dis[v],v});
    }
  }
//  rep(i,1,cntx)printf("X (%d) %d\n",datx[i],dis[i]);
//  rep(i,1,cnty)printf("Y (%d) %d\n",daty[i],dis[cntx+i]);
  rep(i,1,cntx)for(int j:Vx[i])chkmin(ans,dis[i]+abs(Fx-datx[i])+abs(Fy-daty[j]));
  rep(i,1,cnty)for(int j:Vy[i])chkmin(ans,dis[cntx+i]+abs(Fx-datx[j])+abs(Fy-daty[i]));
  printf("%d\n",ans);
}

signed main() {
//  int T=read();
//  while(T--)solve();
  return solve(),0;
}