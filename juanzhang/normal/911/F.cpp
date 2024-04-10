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
const int maxn=2e5+10;
struct node{
  int x,y,z;
};
int n,deg[maxn];
int S,T,pre[maxn];
vi E[maxn];

int bfs(int S){
  static int Q[maxn],dis[maxn];
  memset(dis,-1,sizeof dis);
  int l=1,r=1;Q[1]=S,dis[S]=0;
  while(l<=r){
    int u=Q[l++];
    for(int v:E[u])if(dis[v]==-1)dis[v]=dis[u]+1,Q[++r]=v,pre[v]=u;
  }
  int res=1;
  rep(i,1,n)if(dis[res]<dis[i])res=i;
  return res;
}

int dS[maxn],dT[maxn];
void dfs(int u,int f,int*dis){
  for(int v:E[u])if(v!=f)dis[v]=dis[u]+1,dfs(v,u,dis);
}

void solve(){
  cin>>n;
  rep(i,2,n){
    int u=read(),v=read();E[u].push_back(v),E[v].push_back(u),deg[u]++,deg[v]++;
  }
  S=bfs(1),T=bfs(S);
  int len=0;
  static int pat[maxn];
  static bool onp[maxn];
  for(int u=T;u!=S;u=pre[u]){
    pat[++len]=u,onp[u]=1;
  }
  pat[++len]=S,onp[S]=1;
  dfs(S,0,dS),dfs(T,0,dT);
//  printf("#(%d) : ",S);
//  rep(i,1,n)printf("%d%c",dS[i],"\n "[i<n]);
  static int Q[maxn];
  int l=1,r=0;
  rep(i,1,n)if(deg[i]==1&&!onp[i])Q[++r]=i;
  ll su=0;
  vector<node>ans;
  while(l<=r){
    int u=Q[l++],t;
    if(dS[u]>dT[u]){
      su+=dS[u],t=S;
    }else{
      su+=dT[u],t=T;
    }
    ans.push_back({u,t,u});
    for(int v:E[u])if(--deg[v]==1&&!onp[v]){
      Q[++r]=v;
    }
  }
  rep(i,1,len-1){
    su+=dS[pat[i]];
    ans.push_back({pat[i],S,pat[i]});
  }
  cout<<su<<endl;
  for(node p:ans)printf("%d %d %d\n",p.x,p.y,p.z);
}

signed main(){
//  int T=read();
//  while(T--)solve();
  solve();
  return 0;
}