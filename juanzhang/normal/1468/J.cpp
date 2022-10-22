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
const int maxn=2e5+10;
int n,m,k,par[maxn];
int find(int x){return par[x]==x?x:par[x]=find(par[x]);}

struct edge{
  int u,v,w;
}E[maxn];
bool ont[maxn];

void solve(){
  n=read(),m=read(),k=read();
  rep(i,1,n)par[i]=i;
  rep(i,1,m){
    int u=read(),v=read(),w=read();
    E[i]={u,v,w-k};
    ont[i]=0;
  }
  sort(E+1,E+m+1,[](edge P,edge Q){
    return P.w<Q.w;
  });
  int mx=0;
  rep(i,1,m){
    int u=E[i].u,v=E[i].v;
    if(find(u)!=find(v)){
      par[find(u)]=find(v);
      ont[i]=1,chkmax(mx,E[i].w);
    }
  }
  ll as=1e18;
  if(mx>0){
    as=0;
    rep(i,1,m)if(ont[i]){
      if(E[i].w>0){
        as+=E[i].w;
      }
    }
  }else{
    rep(i,1,m){
      chkmin(as,(ll)abs(E[i].w));
    }
  }
  cout<<as<<endl;
}

signed main(){
  int T=read();
  while(T--)solve();
//  solve();
  return 0;
}