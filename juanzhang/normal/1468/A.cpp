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
const int maxn=5e5+10;
int n,A[maxn],dp[maxn];

#define mid ((l+r)>>1)
#define lson k<<1,l,mid
#define rson k<<1|1,mid+1,r

pii val[maxn<<2];
void maintain(int k){
  val[k]=max(val[k<<1],val[k<<1|1]);
}
void build(int k,int l,int r){
  val[k]={0,-1e9};
  if(l==r)return;build(lson),build(rson);
}
void upd(int k,int l,int r,int x,pii p){
  if(l==r)return val[k]=p,void();
  x<=mid?upd(lson,x,p):upd(rson,x,p);maintain(k);
}
pii query(int k,int l,int r,int x){
  if(r<=x)return val[k];
  return x<=mid?query(lson,x):max(val[k<<1],query(rson,x));
}

#undef mid
#undef lson
#undef rson

void solve(){
  cin>>n;
  rep(i,1,n){
    A[i]=read(),dp[i]=0;
  }
  build(1,1,n);
  upd(1,1,n,1,{0,0});
  int res=0,top=0;
  static int st[maxn];
  rep(i,1,n){
    while(top&&A[st[top]]<=A[i])top--;
    int ps=st[top];
    pii p=query(1,1,n,A[i]);
    int id=-p.second;
    dp[i]=p.first+(id<ps);
    st[++top]=i;
//    printf("#%d\n",dp[i]);
//    bool f=0;
//    per(j,i-1,1){
//      if(A[i]<B[j]){
//        f=1;
//      }else{
//        chkmax(dp[i],dp[j]+f);
//      }
//    }
    dp[i]++;
    chkmax(res,dp[i]);
    upd(1,1,n,A[i],{dp[i],-i});
  }
  cout<<res<<endl;
}

signed main(){
  int T=read();
  while(T--)solve();
//  solve();
  return 0;
}