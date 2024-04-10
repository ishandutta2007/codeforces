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
typedef vector<int>vi;
typedef pair<int,int>pii;
const int maxn=2e5+10;
int n,q;char S[maxn],T[maxn],ans[maxn];

#define mid ((l+r)>>1)
#define lson k<<1,l,mid
#define rson k<<1|1,mid+1,r

int su[maxn<<2],cov[maxn<<2];
void pushtag(int k,int x,int l){
  cov[k]=x,su[k]=x*l;
}
void pushdown(int k,int l){
  int&x=cov[k];
  if(x!=-1)pushtag(k<<1,x,(l+1)/2),pushtag(k<<1|1,x,l/2),x=-1;
}
void maintain(int k){
  su[k]=su[k<<1]+su[k<<1|1];
}
void build(int k,int l,int r){
  cov[k]=-1;
  if(l==r){
    su[k]=S[l]=='1';
    return;
  }
  build(lson),build(rson),maintain(k);
}
void print(int k,int l,int r){
  if(l==r){
    ans[l]=su[k]+'0';
    return;
  }
  pushdown(k,r-l+1);
  print(lson),print(rson);
}
void upd(int k,int l,int r,int ql,int qr,int x){
  if(ql<=l&&r<=qr)return pushtag(k,x,r-l+1),void();
  pushdown(k,r-l+1);
  if(ql<=mid)upd(lson,ql,qr,x);
  if(qr>mid)upd(rson,ql,qr,x);
  maintain(k);
}
int query(int k,int l,int r,int ql,int qr){
  if(ql<=l&&r<=qr)return su[k];
  pushdown(k,r-l+1);int res=0;
  if(ql<=mid)res=query(lson,ql,qr);
  if(qr>mid)res+=query(rson,ql,qr);
  return res;
}

#undef mid
#undef lson
#undef rson

struct node{
  int l,r;
}Q[maxn];

void solve(){
  scanf("%d%d%s%s",&n,&q,S+1,T+1);
  rep(i,1,n)swap(S[i],T[i]);
  build(1,1,n);
  rep(i,1,q)Q[i].l=read(),Q[i].r=read();
  reverse(Q+1,Q+q+1);
  rep(i,1,q){
    int l=Q[i].l,r=Q[i].r;
    int su=query(1,1,n,l,r),le=r-l+1;
    if(2*su==le)return puts("NO"),void();
    if(le-su<(le+1)/2){
      upd(1,1,n,l,r,1);
    }else{
      upd(1,1,n,l,r,0);
    }
//    printf("(%d %d) ",su,le);
//    putchar('#'),print(1,1,n);rep(i,1,n)putchar(ans[i]);puts("");
  }
  print(1,1,n);
  bool as=1;
  rep(i,1,n)as&=ans[i]==T[i];
  puts(as?"YES":"NO");
}

signed main(){
  int T=read();
  while(T--)solve();
  return 0;
}