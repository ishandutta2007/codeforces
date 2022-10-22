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
int tpn,arr[maxn],brr[maxn],ans;

int n,m;
struct Seg{
  int l,r;
  bool operator<(const Seg&o)const{
    return r<o.r;
  }
}A[maxn],B[maxn];

#define mid ((l+r)>>1)
#define lson ls[k],l,mid
#define rson rs[k],mid+1,r

int mn[maxn*40],mx[maxn*40],ls[maxn*40],rs[maxn*40],tot,rt;
void clear(){
  rep(i,1,tot)mn[i]=1e9,mx[i]=-1e9,ls[i]=0,rs[i]=0;tot=rt=1;
}
void ins(int&k,int l,int r,int x,int v1,int v2){
  if(!k)k=++tot;
  chkmin(mn[k],v1),chkmax(mx[k],v2);
  if(l!=r)x<=mid?ins(lson,x,v1,v2):ins(rson,x,v1,v2);
}
int query_mn(int k,int l,int r,int x){
  if(r<=x)return mn[k];
  return x<=mid?query_mn(lson,x):min(mn[ls[k]],query_mn(rson,x));
}
int query_mx(int k,int l,int r,int x){
  if(x<=l)return mx[k];
  return x>mid?query_mx(rson,x):max(mx[rs[k]],query_mx(lson,x));
}

#undef mid
#undef lson
#undef rson

void Sol(){
  clear();
  for(int i=1,j=1;i<=n;i++){
    for(;j<=m&&B[j].r<=A[i].r;j++){
      ins(rt,1,1e9,B[j].l,-B[j].r,B[j].r-B[j].l);
    }
    chkmax(ans,-query_mn(1,1,1e9,A[i].l)-A[i].l);
    chkmax(ans,query_mx(1,1,1e9,A[i].l));
  }
//  rep(i,1,n){
//    rep(j,1,m)if(B[j].r<=A[i].r){
//      if(B[j].l<=A[i].l){
//        chkmax(ans,B[j].r-A[i].l);
//      }else{
//        chkmax(ans,B[j].r-B[j].l);
//      }
//    }
//  }
}

void solve(){
  cin>>tpn;ll sum=0;
  rep(i,1,tpn)arr[i]=read();
  rep(i,1,tpn)brr[i]=read();
  rep(i,1,tpn){
    sum+=abs(arr[i]-brr[i]);
    if(arr[i]<brr[i]){
      A[++n]={arr[i],brr[i]};
    }else if(arr[i]>brr[i]){
      B[++m]={brr[i],arr[i]};
    }
  }
  memset(mn,0x3f,sizeof mn),memset(mx,-0x3f,sizeof mx);
  sort(A+1,A+n+1),sort(B+1,B+m+1);
  Sol();
  swap(n,m),swap(A,B);
  Sol();
  cout<<sum-2*ans<<endl;
}

signed main(){
//  int T=read();
//  while(T--)solve();
  solve();
  return 0;
}