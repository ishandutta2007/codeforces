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
const int maxn=5e4+10;
ll K;int P;
int n,m,S[maxn];

inline void Add(int&x,int y){x+=y;if(x>=P)x-=P;}

struct matrix{
  int arr[2][2];
  void clear(){memset(arr,0,sizeof arr);}
  inline int*operator[](const int&pos){return arr[pos];}
  inline void print(){rep(i,0,1)rep(j,0,1)printf("%d%c",arr[i][j],"\n "[j<1]);}
}E;
matrix operator*(matrix A,matrix B){
  matrix res;res.clear();
  rep(k,0,1)rep(i,0,1)rep(j,0,1)Add(res[i][j],1ll*A[i][k]*B[k][j]%P);
  return res;
}
matrix qp(matrix A,ll k){
  matrix res=E;
  for(;k;k>>=1,A=A*A)if(k&1)res=res*A;
  return res;
}
void minit(){
  E.clear();rep(i,0,1)E[i][i]=1;
}

#define mid ((l+r)>>1)
#define lson k<<1,l,mid
#define rson k<<1|1,mid+1,r

matrix val[maxn<<2];
void build(int k,int l,int r){
  if(l==r){
    auto tmp=val[k].arr;
    tmp[0][0]=S[l],tmp[1][0]=S[(l+n-1)%n],tmp[0][1]=1,tmp[1][1]=0;return;
  }
  build(lson),build(rson),val[k]=val[k<<1]*val[k<<1|1];
}
matrix query(int k,int l,int r,int ql,int qr){
  if(ql<=l&&r<=qr)return val[k];
  if(qr<=mid)return query(lson,ql,qr);
  if(ql>mid)return query(rson,ql,qr);
  return query(lson,ql,qr)*query(rson,ql,qr);
}

#undef mid
#undef lson
#undef rson

struct node{
  ll p;int s;
}dat[maxn];

matrix trans(ll l,ll r){
  if(l>r)return E;
//  rep(i,l,r)printf("#%d\n",i);
//  matrix res=E;
//  rep(i,l,r){
//    matrix J;
//    J[0][0]=S[i%n],J[0][1]=1,J[1][1]=0,J[1][0]=S[(i-1)%n];
//    res=res*J;
//  }
//  return res;
  if(l/n==r/n){
    return query(1,0,n-1,l%n,r%n);
  }
  return query(1,0,n-1,l%n,n-1)*qp(val[1],r/n-l/n-1)*query(1,0,n-1,0,r%n);
}

void solve(){
  minit();
  cin>>K>>P>>n;
  if(K<2)return cout<<K%P<<endl,void();
  rep(i,0,n-1)S[i]=read()%P;
  build(1,0,n-1);
  cin>>m;
  rep(i,1,m){
    cin>>dat[i].p;dat[i].s=read()%P;
  }
  sort(dat+1,dat+m+1,[](node X,node Y){
    return X.p<Y.p;
  });
  ll cur=1;
  matrix M;M.clear(),M.arr[0][0]=1%P;
  rep(i,1,m){
    ll p=dat[i].p;
    if(p>=K)break;
    M=M*trans(cur,p-1);
    matrix J;
    J[0][0]=dat[i].s,J[0][1]=1,J[1][1]=0,J[1][0]=i>1&&dat[i-1].p==dat[i].p-1?dat[i-1].s:S[(p-1)%n];
//    puts("");
//    M.print();
//    puts("*");
//    J.print();
//    puts("");
    M=M*J;
//    printf("#%lld\n",p);
    cur=p+1;
    if(cur==K)break;
    if(i<m&&dat[i+1].p==dat[i].p+1)continue;
    J[0][0]=S[(p+1)%n],J[1][0]=dat[i].s;
    M=M*J;
    cur++;
  }
  M=M*trans(cur,K-1);
  cout<<M.arr[0][0]<<endl;
}

signed main(){
//  int T=read();
//  while(T--)solve();
  solve();
  return 0;
}