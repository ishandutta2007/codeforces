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
const int maxn=5e5+10;
int n,m;
int h[maxn],dis[maxn],Q[maxn],col[maxn];
struct edges{int nxt,to,w;}E[maxn];
void addline(int u,int v,int w){
  static int ecnt;E[++ecnt]={h[u],v,w},h[u]=ecnt;
}

void solve() {
  cin>>n>>m;
  rep(i,1,m){
    int u=read(),v=read();addline(v,u,read());
  }
  memset(col,-1,sizeof col),memset(dis,-1,sizeof dis);
  int l=1,r=1;Q[1]=n,col[n]=0,dis[n]=0;
  while(l<=r){
    int u=Q[l++];
    for(int i=h[u];i;i=E[i].nxt){
      int v=E[i].to;
      if(col[v]==-1){
        col[v]=E[i].w^1;
      }else if(dis[v]==-1&&col[v]==E[i].w){
        dis[v]=dis[u]+1,Q[++r]=v;
      }
    }
  }
  printf("%d\n",dis[1]);
  rep(i,1,n)putchar(max(0,col[i])|48);puts("");
}

signed main() {
//  int T=read();
//  while(T--)solve();
  solve();
  return 0;
}