#include<bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=(a),i##end=(b);i<=i##end;++i)
#define per(i,a,b) for(int i=(a),i##end=(b);i>=i##end;--i)
//mt19937 Rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
template<typename T>void chkmax(T&x,T y){if(x<y)x=y;}
template<typename T>void chkmin(T&x,T y){if(x>y)x=y;}

//inline char nc(){
//  static char buf[1000000],*p1=buf,*p2=buf;
//  return p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++;
//}

//char out_buf[1<<23|5],*ouf=out_buf; // size
//inline void pc(const char&c){*ouf=c,++ouf;}

#define nc() getchar()
#define pc(x) putchar(x)

inline int read(){
  bool f=0;int x=0;char c=nc();
  while(c<48)f|=c=='-',c=nc();
  while(c>47)x=x*10+(c^48),c=nc();
  return f?-x:x;
}

void write$(long long x){
  if(x>9)write$(x/10);
  pc(x%10|48);
}
void write(long long x){
  if(x<0)x=-x,pc('-');
  write$(x);
}

typedef double db;
typedef long long ll;
typedef vector<int>vi;
typedef pair<int,int>pii;

const int maxn=2e5+10;
int n,q;

#define mid ((l+r)>>1)
#define lson k<<1,l,mid
#define rson k<<1|1,mid+1,r

struct BIT{
  ll c[maxn];
  void add(int pos,ll x){
    for(;pos<=n;pos+=pos&-pos)c[pos]+=x;
  }
  ll query(int pos){
    ll res=0;for(;pos;pos&=pos-1)res+=c[pos];return res;
  }
}B1,B2;
void _add(int pos,int x){
  B1.add(pos,x);
  B2.add(pos,1ll*pos*x);
}
ll _query(int pos){
  return B1.query(pos)*(pos+1)-B2.query(pos);
}
void add(int l,int r,int x){
  _add(l,x),_add(r+1,-x);
}
ll query(int l,int r){
  return _query(r)-_query(l-1);
}

namespace RR{

int mx[maxn<<2],sc[maxn<<2],ct[maxn<<2];
void pushcov(int k,int x){
  if(mx[k]>x)mx[k]=x;
}
void pushdown(int k){
  pushcov(k<<1,mx[k]),pushcov(k<<1|1,mx[k]);
}
void maintain(int k){
  if(mx[k<<1]<mx[k<<1|1]){
    mx[k]=mx[k<<1|1];
    ct[k]=ct[k<<1|1];
  }else if(mx[k<<1]>mx[k<<1|1]){
    mx[k]=mx[k<<1];
    ct[k]=ct[k<<1];
  }else{
    mx[k]=mx[k<<1];
    ct[k]=ct[k<<1]+ct[k<<1|1];
  }
  sc[k]=-1e9;
  if(mx[k<<1]!=mx[k])chkmax(sc[k],mx[k<<1]);
  else chkmax(sc[k],sc[k<<1]);
  if(mx[k<<1|1]!=mx[k])chkmax(sc[k],mx[k<<1|1]);
  else chkmax(sc[k],sc[k<<1|1]);
}
void build(int k,int l,int r){
  if(l==r){
    add(l,r,1);
    mx[k]=l,ct[k]=1,sc[k]=-1e9;
  }else{
    build(lson),build(rson),maintain(k);
  }
}
void upd(int k,int l,int r,int pos,int v){
  if(mx[k]<=v)return;
  if(r<=pos){
    if(l==r){
      add(l,mx[k],-1);
      add(l,v,1);
      mx[k]=v,sc[k]=-1e9,ct[k]=1;
      return;
    }
    if(sc[k]<v){
      add(v+1,mx[k],-ct[k]);
      pushcov(k,v);return;
    }
  }
  pushdown(k);
  upd(lson,pos,v);
  if(pos>mid)upd(rson,pos,v);
  maintain(k);
}
void ins(int k,int l,int r,int pos,int v){
  if(l==r){
    add(l,mx[k],-1);
    add(l,v,1);
    mx[k]=v,ct[k]=1,sc[k]=-1e9;
  }else{
    pushdown(k);
    pos<=mid?ins(lson,pos,v):ins(rson,pos,v),maintain(k);
  }
}

}

#undef mid
#undef lson
#undef rson

void solve(){
  n=read(),q=read();
  RR::build(1,1,n);
  while(q--){
    int op=read(),x=read(),y=read();
    if(op==1){
      if(x>1)RR::upd(1,1,n,x-1,x-1);
      RR::ins(1,1,n,x,y);
    }else{
      write(query(x,y)),pc(10);
    }
  }
}

signed main(){
//  int T=read();
//  while(T--)solve();
  solve();
//  fwrite(out_buf,1,ouf-out_buf,stdout);
  return 0;
}