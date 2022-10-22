#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=(a),i##end=(b);i<=i##end;++i)
#define per(i,a,b) for(int i=(a),i##end=(b);i>=i##end;--i)
//mt19937 Rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
template<typename T>void chkmax(T&x,T y){if(x<y)x=y;}
template<typename T>void chkmin(T&x,T y){if(x>y)x=y;}

typedef double db;
typedef long long ll;
typedef vector<int>vi;
typedef pair<int,int>pii;

namespace orzjk{
  const int SZ=1e6;
  char buf[SZ],*p1=buf,*p2=buf;
  char nc(){
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,SZ,stdin),p1==p2)?EOF:*p1++;
  }
  char fub[SZ],*p3=fub,*p4=fub+SZ;
  void pc(char c){
    p3==p4&&(fwrite(fub,1,SZ,stdout),p3=fub);
    *p3++=c;
  }
  void flush(){
    fwrite(fub,1,p3-fub,stdout),p3=fub;
  }
}
using orzjk::nc;
using orzjk::pc;

//#define nc getchar
//#define pc putchar

ll read(){
  ll x=0,f=1;char c=nc();
  while(c<48)c=='-'&&(f=-1),c=nc();
  while(c>47)x=x*10+(c^48),c=nc();
  return x*f;
}
void write(int x){
  static char st[11];
  if(!x)return pc(48),void();
  char*p=st;
  if(x<0)x=-x,pc('-');
  for(;x;x/=10)*p++=x%10|48;
  do{
    pc(*--p);
  }while(p!=st);
}

const int maxn=2e5+10;
int n,m,q,all;

#define mid ((l+r)>>1)
#define lson k<<1,l,mid
#define rson k<<1|1,mid+1,r

int tag[maxn<<2];
int trans[maxn<<2][2][32];
void get(int*A,int x){
  rep(i,0,all){
    if(x&1){
      A[i]=(i<<1|1)&all;
    }else{
      A[i]=((i<<1)&all)|(i!=all);
    }
  }
}
void pushtag(int k){
  tag[k]^=1,swap(trans[k][0],trans[k][1]);
}
void pushdown(int k){
  if(tag[k]){
    pushtag(k<<1);
    pushtag(k<<1|1);
    tag[k]=0;
  }
}
void maintain(int k){
  rep(_,0,1)rep(i,0,all)trans[k][_][i]=trans[k<<1|1][_][trans[k<<1][_][i]];
}
void build(int k,int l,int r){
  if(l==r){
    ll x=(read()-1)&1;
    tag[k]=x;
    get(trans[k][0],x);
    get(trans[k][1],x^1);
  }else build(rson),build(lson),maintain(k);
}
void upd(int k,int l,int r,int ql,int qr){
  if(ql<=l&&r<=qr)return pushtag(k),void();
  pushdown(k);
  if(ql<=mid)upd(lson,ql,qr);
  if(qr>mid)upd(rson,ql,qr);
  maintain(k);
}
int cur;
void query(int k,int l,int r,int ql,int qr){
  if(ql<=l&&r<=qr)return cur=trans[k][0][cur],void();
  pushdown(k);
  if(ql<=mid)query(lson,ql,qr);
  if(qr>mid)query(rson,ql,qr);
}

#undef mid
#undef lson
#undef rson

void solve(){
  n=read(),m=read(),q=read();
  all=(1<<m)-1;
  build(1,1,n);
  while(q--){
    int op=read(),l=read(),r=read();
    swap(l,r);
    l=n-l+1;
    r=n-r+1;
    if(op==1){
      ll x=read();
      if(x%2==0)continue;
      upd(1,1,n,l,r);
    }else{
      cur=all;
      query(1,1,n,l,r);
      puts(cur&1?"1":"2");
    }
  }
}

signed main(){
//  int T=read();
//  while(T--)solve();
  solve();
  orzjk::flush();
  return 0;
}