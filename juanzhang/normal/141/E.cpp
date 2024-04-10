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
const int maxn=1e5+10;
int n,m,tot,in[maxn];
struct edge{
  int u,v,col,tid;
}E[maxn];
struct US{
  int par[maxn];
  void init(){rep(i,1,n)par[i]=i;}
  void copy(US&ano){memcpy(par,ano.par,sizeof par);}
  int find(int x){return par[x]==x?x:par[x]=find(par[x]);}
  void unite(int x,int y){par[find(x)]=find(y);}
}zzh,yyh,lsj;

void solve() {
  cin>>n>>m;
  rep(i,1,m){
    char ch;
    scanf("%d %d %s",&E[i].u,&E[i].v,&ch),E[i].col=ch=='M',E[i].tid=i;
  }
  if(n%2==0||m<n-1)return puts("-1"),void();
  zzh.init();
  int tot=n;
  rep(i,1,m){
    int u=E[i].u,v=E[i].v;
    if(E[i].col==1&&zzh.find(u)!=zzh.find(v)){
      zzh.unite(u,v),tot--;
    }
  }
  if(tot-1>n/2)return puts("-1"),void();
  yyh.copy(zzh);
  int ned=n/2-tot+1;
  static vi wkr[maxn];
  rep(i,1,m){
    int u=E[i].u,v=E[i].v;
    if(E[i].col==0&&yyh.find(u)!=yyh.find(v)){
      in[E[i].tid]=1,yyh.unite(u,v),tot--;
    }
    if(zzh.find(u)==zzh.find(v))wkr[zzh.find(u)].push_back(i);
  }
  if(tot>1)return puts("-1"),void();
  static vi vec[maxn];
  rep(i,1,n)vec[zzh.find(i)].push_back(i);
  lsj.init();
  rep(S,1,n)if(zzh.find(S)==S){
    for(int i:wkr[S]){
      if(!ned)break;
      if(E[i].col==0){
        int u=E[i].u,v=E[i].v;
        if(lsj.find(u)!=lsj.find(v)){
          lsj.unite(u,v),ned--,in[E[i].tid]=1;
        }
      }
    }
    for(int i:wkr[S]){
      if(E[i].col==1){
        int u=E[i].u,v=E[i].v;
        if(lsj.find(u)!=lsj.find(v)){
          lsj.unite(u,v),in[E[i].tid]=1;
        }
      }
    }
  }
  if(ned)return puts("-1"),void();
  printf("%d\n",n-1);
  rep(i,1,m)if(in[i])printf("%d ",i);
}

signed main() {
//  int T=read();
//  while(T--)solve();
  solve();
  return 0;
}