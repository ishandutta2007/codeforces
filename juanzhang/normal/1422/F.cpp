#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = (a), i##end = (b); i <= i##end; ++i)
#define per(i, a, b) for (int i = (a), i##end = (b); i >= i##end; --i)
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
const int maxn=1e5+10,P=1e9+7;
int n,q,A[maxn];
int len,lst[maxn*2],L[maxn],R[maxn];pii dat[maxn*4];

int tot,pri[maxn*2],ppw[10][30];

void sieve() {
  int N=2e5;
  rep(i,2,N)if(!pri[i]){
    pri[++tot]=i;
    for(int j=i+i;j<=N;j+=i)pri[j]=1;
  }
  rep(i,0,9){
    ppw[i][0]=1;
    rep(j,1,20){
      ppw[i][j]=pri[i+1]*ppw[i][j-1];
      if(ppw[i][j]>=maxn*2)break;
    }
  }
}

int qp(int a,int k){
  int res=1;
  for(;k;k>>=1,a=1ll*a*a%P)if(k&1)res=1ll*res*a%P;
  return res;
}

struct SGT{
  #define mid ((l+r)>>1)
  #define lson k<<1,l,mid
  #define rson k<<1|1,mid+1,r
  int val[maxn<<2];
  void build(int k,int l,int r,int ttt){
    if(l==r){
      int x=A[l];
      while(x%ttt==0)val[k]++,x/=ttt;return;
    }
    build(lson,ttt),build(rson,ttt),val[k]=max(val[k<<1],val[k<<1|1]);
  }
  int query(int k,int l,int r,int ql,int qr){
    if(ql<=l&&r<=qr)return val[k];int res=0;
    if(ql<=mid)res=query(lson,ql,qr);
    if(qr>mid)chkmax(res,query(rson,ql,qr));
    return res;
  }
  #undef mid
  #undef lson
  #undef rson
}TR[10];

#define mid ((l + r) >> 1)

int tn,rt[maxn*4],ls[maxn*80],rs[maxn*80],pro[maxn*80];
void ins(int &k,int rt,int l,int r,int x,int v){
  pro[k=++tn]=1ll*v*pro[rt]%P,ls[k]=ls[rt],rs[k]=rs[rt];
  if(l==r)return;
  x<=mid?ins(ls[k],ls[rt],l,mid,x,v):ins(rs[k],rs[rt],mid+1,r,x,v);
}
int query(int k,int l,int r,int x){
  if(r<=x)return pro[k];
  return x>mid?1ll*pro[ls[k]]*query(rs[k],mid+1,r,x)%P:query(ls[k],l,mid,x);
}

#undef mid

void solve() {
  sieve();
  cin>>n;
  rep(i,1,n){
    L[i]=len+1;
    int x=A[i]=read(),tmp=sqrt(x);
    for(int j=1;j<=tot&&pri[j]<=tmp;j++)if(x%pri[j]==0){
      int c=1;while(x%pri[j]==0){
        x/=pri[j],c*=pri[j];
        if(j>10)dat[++len]={pri[j],c};
      }
    }
    if(x>pri[10])dat[++len]={x,x};
    R[i]=len;
  }
  fill(pro,pro+maxn*79,1);
  rep(i,1,n)rep(j,L[i],R[i]){
    int &p=lst[dat[j].second];
    ins(rt[j],rt[j-1],0,len,p,dat[j].first),p=j;
  }
  rep(i,0,9)TR[i].build(1,1,n,pri[i+1]);
  cin>>q;int lastans=0;
  while(q--){
    int l=(read()+lastans)%n+1,r=(read()+lastans)%n+1;
    if(l>r)swap(l,r);
    int ans=1;
    rep(i,0,9)ans=1ll*ans*ppw[i][TR[i].query(1,1,n,l,r)]%P;
    ans=1ll*ans*query(rt[R[r]],0,len,L[l]-1)%P*qp(query(rt[L[l]-1],0,len,L[l]-1),P-2)%P;
    printf("%d\n",lastans=ans);
  }
}

signed main() {
//  int T=read();
//  while(T--)solve();
  solve();
  return 0;
}