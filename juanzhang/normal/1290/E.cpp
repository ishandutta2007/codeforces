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

typedef double db;
typedef long long ll;
typedef vector<int>vi;
typedef pair<int,int>pii;

#define nc() getchar()
#define pc(x) putchar(x)

inline int read(){
  bool f=0;int x=0;char c=nc();
  while(c<48)f|=c=='-',c=nc();
  while(c>47)x=x*10+(c^48),c=nc();
  return f?-x:x;
}

void write$(ll x){
  if(x>9)write$(x/10);
  pc(x%10|48);
}
void write(ll x){
  if(x<0)x=-x,pc('-');
  write$(x);
}

const int maxn=2e5+10;
int n,A[maxn],mp[maxn];

bool vis[maxn];
int lef[maxn],rig[maxn];

int c[maxn];
void add(int pos){
  for(;pos<=n;pos+=pos&-pos)c[pos]++;
}
int query(int pos){
  int res=0;for(;pos;pos&=pos-1)res+=c[pos];return res;
}

#define mid ((l+r)>>1)
#define lson k<<1,l,mid
#define rson k<<1|1,mid+1,r

namespace LL{

int mn[maxn<<2],sc[maxn<<2],ct[maxn<<2],add[maxn<<2],coef[maxn<<2];
ll sum[maxn<<2];
void pushcov(int k,int x){
  if(mn[k]<x)sum[k]+=(x-mn[k])*1ll*ct[k],mn[k]=x;
}
void pushadd(int k,int x){
  add[k]+=x,mn[k]+=x,sc[k]+=x,sum[k]+=1ll*coef[k]*x;
}
void pushdown(int k){
  int&y=add[k];
  if(y){
    pushadd(k<<1,y),pushadd(k<<1|1,y),y=0;
  }
  pushcov(k<<1,mn[k]),pushcov(k<<1|1,mn[k]);
}
void maintain(int k){
  coef[k]=coef[k<<1]+coef[k<<1|1];
  sum[k]=sum[k<<1]+sum[k<<1|1];
  if(mn[k<<1]>mn[k<<1|1]){
    mn[k]=mn[k<<1|1];
    ct[k]=ct[k<<1|1];
  }else if(mn[k<<1]<mn[k<<1|1]){
    mn[k]=mn[k<<1];
    ct[k]=ct[k<<1];
  }else{
    mn[k]=mn[k<<1];
    ct[k]=ct[k<<1]+ct[k<<1|1];
  }
  sc[k]=1e9;
  if(mn[k<<1]!=mn[k])chkmin(sc[k],mn[k<<1]);
  else chkmin(sc[k],sc[k<<1]);
  if(mn[k<<1|1]!=mn[k])chkmin(sc[k],mn[k<<1|1]);
  else chkmin(sc[k],sc[k<<1|1]);
}
void upd(int k,int l,int r,int pos,int v){
  if(!coef[k])return;
  if(mn[k]>=v)return;
  if(pos<=l){
    if(l==r){
      mn[k]=sum[k]=v,sc[k]=1e9,ct[k]=1;
      return;
    }
    if(sc[k]>v){
      pushcov(k,v);return;
    }
  }
  pushdown(k);
  if(pos<=mid)upd(lson,pos,v);
  upd(rson,pos,v);
  maintain(k);
}
void _add(int k,int l,int r,int pos){
  if(!coef[k])return;
  if(pos<=l)return pushadd(k,1);
  pushdown(k);
  if(pos<=mid)_add(lson,pos);
  _add(rson,pos);
  maintain(k);
}
void ins(int k,int l,int r,int pos){
  if(l==r){
    sum[k]=mn[k]=0,ct[k]=1,sc[k]=1e9,coef[k]=1;
  }else{
    pushdown(k);
    pos<=mid?ins(lson,pos):ins(rson,pos),maintain(k);
  }
}

}

namespace RR{

int mx[maxn<<2],sc[maxn<<2],ct[maxn<<2],add[maxn<<2],coef[maxn<<2];
ll sum[maxn<<2];
void pushcov(int k,int x){
  if(mx[k]>x)sum[k]-=(mx[k]-x)*1ll*ct[k],mx[k]=x;
}
void pushadd(int k,int x){
  add[k]+=x,mx[k]+=x,sc[k]+=x,sum[k]+=1ll*coef[k]*x;
}
void pushdown(int k){
  int&y=add[k];
  if(y){
    pushadd(k<<1,y),pushadd(k<<1|1,y),y=0;
  }
  pushcov(k<<1,mx[k]),pushcov(k<<1|1,mx[k]);
}
void maintain(int k){
  coef[k]=coef[k<<1]+coef[k<<1|1];
  sum[k]=sum[k<<1]+sum[k<<1|1];
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
void upd(int k,int l,int r,int pos,int v){
  if(!coef[k])return;
  if(mx[k]<=v)return;
  if(r<=pos){
    if(l==r){
      mx[k]=sum[k]=v,sc[k]=-1e9,ct[k]=1;
      return;
    }
    if(sc[k]<v){
      pushcov(k,v);return;
    }
  }
  pushdown(k);
  upd(lson,pos,v);
  if(pos>mid)upd(rson,pos,v);
  maintain(k);
}
void _add(int k,int l,int r,int pos){
  if(!coef[k])return;
  if(pos<=l)return pushadd(k,1);
  pushdown(k);
  if(pos<=mid)_add(lson,pos);
  _add(rson,pos);
  maintain(k);
}
void ins(int k,int l,int r,int pos,int v){
  if(l==r){
    sum[k]=mx[k]=v,ct[k]=1,sc[k]=-1e9,coef[k]=1;
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
//  n=150000;
  n=read();
  rep(i,1,n){
//    A[i]=i&1?n/2-i/2:n-i/2+1;
    A[i]=read();
    mp[A[i]]=i;
  }
  memset(RR::mx,-0x3f,sizeof RR::mx);
  memset(RR::sc,-0x3f,sizeof RR::sc);
  memset(LL::sc,0x3f,sizeof LL::sc);
  memset(LL::mn,0x3f,sizeof LL::mn);
//  int tp=0;
  rep(num,1,n){
    int pos=mp[num];
    vis[pos]=1;
    int ct1=query(pos);
//    rep(i,1,pos-1)if(vis[i]){
//      chkmin(rig[i],ct1+1);
//    }
    if(pos>1)RR::upd(1,1,n,pos-1,ct1+1);
//tp-=clock();
    if(pos<n)LL::upd(1,1,n,pos+1,ct1);
//    tp+=clock();
//    rep(i,pos+1,n)if(vis[i]){
//      chkmax(lef[i],ct1);
//      lef[i]++;
//      rig[i]++;
//    }
    if(pos<n)LL::_add(1,1,n,pos+1);
    if(pos<n)RR::_add(1,1,n,pos+1);
//    lef[pos]=0,rig[pos]=num+1;
    LL::ins(1,1,n,pos);
    RR::ins(1,1,n,pos,num+1);
    ll ans=0;
//    rep(i,1,n)if(vis[i]){
//      ans+=rig[i];
//      ans-=lef[i];
//    }
    ans+=RR::sum[1];
    ans-=LL::sum[1];
//    if(num%1000==0)cerr<<num<<' '<<tp<<endl;
    write(ans-num),pc(10);
    add(pos);
  }
}

signed main(){
//  int T=read();
//  while(T--)solve();
  solve();
//  fwrite(out_buf,1,ouf-out_buf,stdout);
  return 0;
}