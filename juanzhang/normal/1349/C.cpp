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
const int maxn=1010;
const int dx[]={1,0,-1,0};const int dy[]={0,1,0,-1};
int n,m,q,A[maxn][maxn],zzh[maxn][maxn];
char str[maxn];

void solve() {
  cin>>n>>m>>q;
  rep(i,1,n){
    scanf("%s",str+1);
    rep(j,1,m){
      A[i][j]=str[j]-'0';
    }
  }
  rep(i,1,n)rep(j,1,m){
    rep(k,0,3){
      int x=i+dx[k],y=j+dy[k];
      if(x>0&&y>0&&x<=n&&y<=m&&A[i][j]==A[x][y]){
        zzh[i][j]=1;
      }
    }
  }
  static pii Q[maxn*maxn];
  static int dis[maxn][maxn];
  memset(dis,-1,sizeof dis);
  int l=1,r=0;
  rep(i,1,n)rep(j,1,m)if(zzh[i][j]){
    dis[i][j]=0,Q[++r]={i,j};
  }
  while(l<=r){
    pii p=Q[l++];int x=p.first,y=p.second;
    rep(i,0,3){
      int tx=x+dx[i],ty=y+dy[i];
      if(tx&&ty&&tx<=n&&ty<=m&&dis[tx][ty]==-1){
        dis[tx][ty]=dis[x][y]+1,Q[++r]={tx,ty};
      }
    }
  }
  while(q--){
    ll p;int x,y;
    scanf("%d%d%I64d",&x,&y,&p);
    printf("%d\n",A[x][y]^((dis[x][y]!=-1)&&((max(p-dis[x][y],0ll))&1)));
  }
}

signed main() {
//  int T=read();
//  while(T--)solve();
  solve();
  return 0;
}