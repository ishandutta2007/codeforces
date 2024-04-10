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
int n,m,k,c[maxn];bool zzh[maxn];
struct edge{
  int u,v;
}E[maxn];

vi zjk[maxn];
set<pii>S;map<pii,vi>G;
int top,st[maxn*2],par[maxn],sz[maxn],ds[maxn];

int find(int x,int&c){
  c=0;
  while(x!=par[x])c^=ds[x],x=par[x];
  return x;
}

bool unite(int x,int y){
  int cx,cy;
  if((x=find(x,cx))!=(y=find(y,cy))){
    if(sz[x]<sz[y])swap(x,y);
    sz[x]+=sz[y],st[++top]=y,ds[y]=cx^cy^1,par[y]=x;
  }else if(cx==cy)return 0;
  return 1;
}

void revert(int k){
  while(top>k){
    int u=st[top--];
    sz[par[u]]-=sz[u],par[u]=u,ds[u]=0;
  }
}

void solve() {
  cin>>n>>m>>k;
  rep(i,1,n)c[i]=read(),par[i]=i,sz[i]=1;
  ll ans=0;
  rep(i,1,m){
    E[i].u=read(),E[i].v=read();
    int cu=c[E[i].u],cv=c[E[i].v];
    if(cu>cv)swap(E[i].u,E[i].v),swap(cu,cv);
    if(cu!=cv)G[{cu,cv}].push_back(i);
    else zjk[cu].push_back(i);
  }
  rep(i,1,k){
    int ti=top;
    for(int id:zjk[i]){
      if(!unite(E[id].u,E[id].v)){
        zzh[i]=1;break;
      }
    }
    if(zzh[i])revert(ti),ans+=k-1;
  }
  for(auto p:G){
    pii ce=p.first;
    vi&vec=p.second;
    if(zzh[ce.first]||zzh[ce.second]){
      if(zzh[ce.first]&&zzh[ce.second])ans-=S.insert({ce.first,ce.second}).second;
      continue;
    }
    int ti=top;
    bool flg=0;
    for(int id:vec){
      if(!unite(E[id].u,E[id].v)){
        flg=1;break;
      }
    }
    if(flg)ans++;
    revert(ti);
  }
  ans=1ll*k*(k-1)/2-ans;
  cout<<ans<<endl;
}

signed main() {
//  int T=read();
//  while(T--)solve();
  solve();
  return 0;
}