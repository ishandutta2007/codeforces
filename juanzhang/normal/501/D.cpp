#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=(a),i##end=(b);i<=i##end;++i)
#define per(i,a,b) for(int i=(a),i##end=(b);i>=i##end;--i)
mt19937 Rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
template<typename T>void chkmax(T&x,T y){if(x<y)x=y;}
template<typename T>void chkmin(T&x,T y){if(x>y)x=y;}
inline int read() {
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
int n,P[maxn],Q[maxn],VP[maxn],VQ[maxn],V[maxn],ans[maxn];

int c[maxn];
void add(int pos){
  for(pos++;pos<=n;pos+=pos&-pos)c[pos]++;
}
int query(int pos){
  int res=0;
  for(pos++;pos;pos&=pos-1)res+=c[pos];
  return res;
}

void run(int*A,int*val){
  memset(c,0,sizeof c);
  per(i,n-1,0)val[i]=query(A[i]),add(A[i]);
}

#define mid ((l+r)>>1)
#define lson k<<1,l,mid
#define rson k<<1|1,mid+1,r

pii tv[maxn<<2];int tag[maxn<<2];

void pushtag(int k,int x){
  tag[k]+=x,tv[k].first+=x;
}

void pushdown(int k){
  int&x=tag[k];
  if(x)pushtag(k<<1,x),pushtag(k<<1|1,x),x=0;
}

void upd(int k,int l,int r,int x,int v){
  if(l==r)return tv[k]={v,l},void();pushdown(k);
  x<=mid?upd(lson,x,v):upd(rson,x,v);tv[k]=min(tv[k<<1],tv[k<<1|1]);
}

void add(int k,int l,int r,int ql,int qr,int v){
  if(ql<=l&&r<=qr)return pushtag(k,v),void();
  pushdown(k);
  if(ql<=mid)add(lson,ql,qr,v);
  if(qr>mid)add(rson,ql,qr,v);
  tv[k]=min(tv[k<<1],tv[k<<1|1]);
}

#undef mid
#undef lson
#undef rson

void solve() {
  cin>>n;
  rep(i,0,n-1)P[i]=read();
  rep(i,0,n-1)Q[i]=read();
  run(P,VP),run(Q,VQ);
  int zzh=0;
  per(i,n-2,0){
    V[i]=VP[i]+VQ[i]+zzh;
    if(V[i]>=n-i)zzh=1,V[i]-=n-i;
    else zzh=0;
  }
//  rep(i,0,n-1)printf("%d%c",V[i],"\n "[i<n-1]);
  rep(i,0,n-1)upd(1,0,n-1,i,n-i-1-V[i]);
  rep(T,0,n-1){
    pii p=tv[1];
    ans[p.second]=n-T-1;
    upd(1,0,n-1,p.second,1e9);
    add(1,0,n-1,0,p.second,-1);
  }
  rep(i,0,n-1)printf("%d ",ans[i]);
}

signed main() {
//  int T=read();
//  while(T--)solve();
  solve();
  return 0;
}