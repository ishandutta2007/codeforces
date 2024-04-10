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
const int maxn=5e5+10,P=998244353;
int n,m,A[maxn];char str[maxn];

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
void ins(int k,int l,int r,int x){
  if(l==r){
    auto tmp=val[k].arr;
    tmp[1][1]=0,tmp[0][1]=1;
    tmp[0][0]=(A[x]+1),tmp[1][0]=x>1&&A[x-1]==1?9-A[x]:0;
    return;
  }
  x<=mid?ins(lson,x):ins(rson,x),val[k]=val[k<<1]*val[k<<1|1];
}

#undef mid
#undef lson
#undef rson

void solve(){
  minit();
  scanf("%d%d%s",&n,&m,str+1);rep(i,1,n)A[i]=str[i]-'0',ins(1,1,n,i);
  while(m--){
    int xx=read(),yy=read();A[xx]=yy;ins(1,1,n,xx);if(xx<n)ins(1,1,n,xx+1);
    printf("%d\n",val[1][0][0]);
  }
}

signed main(){
//  int T=read();
//  while(T--)solve();
  solve();
  return 0;
}