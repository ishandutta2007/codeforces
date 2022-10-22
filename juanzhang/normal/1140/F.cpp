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
const int maxn=6e5+10;
int n=3e5,q;
map<pii,int>mp;

int par[maxn],sz1[maxn],sz2[maxn];int top,st[maxn];ll as;
int find(int x){
  while(x!=par[x])x=par[x];return x;
}
void unite(int x,int y){
  if((x=find(x))!=(y=find(y))){
    if(sz1[x]+sz2[x]<sz1[y]+sz2[y])swap(x,y);
    par[y]=x,as-=1ll*sz1[x]*sz2[x],as-=1ll*sz1[y]*sz2[y],sz1[x]+=sz1[y],sz2[x]+=sz2[y],as+=1ll*sz1[x]*sz2[x],st[++top]=y;
  }
}
void revert(int k){
  while(top>k){
    int u=st[top--];sz1[par[u]]-=sz1[u],sz2[par[u]]-=sz2[u],par[u]=u;
  }
}

#define mid ((l+r)>>1)
#define lson k<<1,l,mid
#define rson k<<1|1,mid+1,r

vector<pii>vec[maxn<<2];
void add(int k,int l,int r,int ql,int qr,pii e){
  if(ql<=l&&r<=qr)return vec[k].push_back(e),void();
  if(ql<=mid)add(lson,ql,qr,e);
  if(qr>mid)add(rson,ql,qr,e);
}
void divide(int k,int l,int r){
  int tp=top;ll TAS=as;
  for(pii p:vec[k]){
    unite(p.first,p.second);
  }
  if(l==r)printf("%I64d ",as);
  else divide(lson),divide(rson);
  revert(tp),as=TAS;
}

#undef mid
#undef lson
#undef rson

void solve(){
  cin>>q;
  rep(i,1,n)par[i]=i,sz1[i]=1,par[n+i]=n+i,sz2[n+i]=1;
  rep(i,1,q){
    int u=read(),v=n+read(),x=mp[{u,v}];
    if(x){
      add(1,1,q,x,i-1,{u,v}),mp.erase({u,v});
    }else{
      mp[{u,v}]=i;
    }
  }
  for(auto p:mp){
    add(1,1,q,p.second,q,p.first);
  }
  divide(1,1,q);
}

signed main(){
//  int T=read();
//  while(T--)solve();
  solve();
  return 0;
}