#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=(a),i##end=(b);i<=i##end;++i)
#define per(i,a,b) for(int i=(a),i##end=(b);i>=i##end;--i)
//mt19937 Rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
template<typename T>void chkmax(T&x,T y){if(x<y)x=y;}
template<typename T>void chkmin(T&x,T y){if(x>y)x=y;}
inline int read(){
  #define nc getchar()
  bool f=0;int x=0;char c=nc;
  while(c<48)f|=c=='-',c=nc;
  while(c>47)x=x*10+(c^48),c=nc;
  return f?-x:x;
  #undef nc
}

typedef double db;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
const int maxn=5e5+10,P=1e9+7;
int n,m,pw2[maxn];
int par[maxn],su[maxn];
int find(int x){
  return par[x]==x?x:par[x]=find(par[x]);
}
bool inq[maxn];
bool vis[maxn];

void solve(){
  cin>>n>>m;
  rep(i,1,m)par[i]=i;
  int ct=0;
  rep(i,1,n){
    int k=read();
    if(k==1){
      int x=read();
      if(!su[find(x)])su[find(x)]=1,inq[i]=1,ct++;
    }else{
      int u=read(),v=read();
      if(find(u)==find(v)){
        
      }else if(!su[find(u)]||!su[find(v)]){
        su[find(u)]|=su[find(v)],par[find(v)]=find(u),inq[i]=1,ct++;
      }
    }
  }
  printf("%d %d\n",pw2[ct],ct);
  rep(i,1,n)if(inq[i])printf("%d ",i);
}

signed main(){
  pw2[0]=1;
  rep(i,1,maxn-1)pw2[i]=2ll*pw2[i-1]%P;
//  int T=read();
//  while(T--)solve();
  solve();
  return 0;
}