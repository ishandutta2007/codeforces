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
const int maxn=1e5+10;
int n,q,dat[maxn],deg[maxn];pii seg1[maxn],seg2[maxn];

#define mid ((l+r)>>1)
#define lson k<<1,l,mid
#define rson k<<1|1,mid+1,r

int tag[maxn<<2],c0[maxn<<2],c1[maxn<<2];
void pushtag(int k){
  tag[k]^=1,swap(c0[k],c1[k]);
}
void pushdown(int k){
  int&x=tag[k];
  if(x)pushtag(k<<1),pushtag(k<<1|1),x=0;
}
void build(int k,int l,int r){
  c0[k]=r-l+1;if(l==r)return;build(lson),build(rson);
}
void upd(int k,int l,int r,int ql,int qr){
  if(ql<=l&&r<=qr)return pushtag(k),void();
  pushdown(k);
  if(ql<=mid)upd(lson,ql,qr);
  if(qr>mid)upd(rson,ql,qr);
  c0[k]=c0[k<<1]+c0[k<<1|1],c1[k]=c1[k<<1]+c1[k<<1|1];
}
int query(int k,int l,int r,int x){
  if(l==r)return c0[k];pushdown(k);
  return x<=mid?query(lson,x):query(rson,x);
}

#undef mid
#undef lson
#undef rson

void solve(){
  int tmpq;cin>>n>>tmpq;
  rep(i,1,n)dat[i]=read();
  sort(dat+1,dat+n+1);
  rep(i,1,tmpq){
    int x=read(),y=read();
    int l=lower_bound(dat+1,dat+n+1,x)-dat;
    int r=upper_bound(dat+1,dat+n+1,y)-dat-1;
    if(l<r)q++,seg1[q]=seg2[q]={l,r};
  }
  build(1,1,n);
  sort(seg1+1,seg1+q+1);
  sort(seg2+1,seg2+q+1,[](pii P,pii Q){
    return P.second<Q.second;
  });
  ll ans=1ll*n*(n-1)*(n-2)/6;
  for(int i=1,j1=1,j2=1;i<=n;i++){
    for(;j1<=q&&seg1[j1].first==i;j1++){
      upd(1,1,n,seg1[j1].first,seg1[j1].second);
    }
    for(;j2<=q&&seg2[j2].second<i;j2++){
      upd(1,1,n,seg2[j2].first,seg2[j2].second);
    }
    if(i>1)upd(1,1,n,i-1,i-1);
    deg[i]=c0[1]-query(1,1,n,i);
  }
  rep(i,1,n)ans-=1ll*deg[i]*(deg[i]-1)/2;
  cout<<ans<<endl;
}

signed main(){
//  int T=read();
//  while(T--)solve();
  solve();
  return 0;
}