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

int read(){
  int x=0,f=1;char c=nc();
  while(c<48)c=='-'&&(f=-1),c=nc();
  while(c>47)x=x*10+(c^48),c=nc();
  return x*f;
}
void write(ll x){
  static char st[21];
  if(!x)return pc(48),void();
  char*p=st;
  if(x<0)x=-x,pc('-');
  for(;x;x/=10)*p++=x%10|48;
  do{
    pc(*--p);
  }while(p!=st);
}

const int maxn=3e4+10;
int n,q,W[maxn],H[maxn];
int tidW[maxn],tidH[maxn];
int mpW[maxn],mpH[maxn];

int cant[maxn];
int A[maxn],B[maxn];

struct matrix{
  ll arr[4][4];
  void clear(){
    memset(arr,-0x3f,sizeof arr);
  }
  ll*operator[](const int&pos){
    return arr[pos];
  }
  const ll*operator[](const int&pos)const{
    return arr[pos];
  }
};
matrix operator*(matrix A,matrix B){
  static matrix C;C.clear();
  for(int i=0;i<4;++i)for(int k=0;k<4;++k)if(A[i][k]>=0)for(int j=0;j<4;++j)chkmax(C[i][j],A[i][k]+B[k][j]);
  return C;
}

#define mid ((l+r)>>1)
#define lson k<<1,l,mid
#define rson k<<1|1,mid+1,r

matrix T[maxn<<2];

void satori(matrix&M,int pos){
  M.clear();
  rep(i,0,1)M[i][i<<1|1]=0;
  if(cant[pos]!=pos)rep(i,0,1)M[i][i<<1]=1ll*A[pos]*B[pos];
  if(pos>1&&cant[pos]!=pos-1&&cant[pos-1]!=pos)M[1][0]=1ll*A[pos-1]*B[pos]+1ll*A[pos]*B[pos-1];
  if(pos>2){
    if(cant[pos]!=pos-2&&cant[pos-2]!=pos)chkmax(M[2][0],1ll*A[pos-2]*B[pos]+1ll*A[pos]*B[pos-2]);
    if(cant[pos]!=pos-2&&cant[pos-1]!=pos&&cant[pos-2]!=pos-1)chkmax(M[3][0],1ll*A[pos-2]*B[pos-1]+1ll*A[pos-1]*B[pos]+1ll*A[pos]*B[pos-2]);
    if(cant[pos]!=pos-1&&cant[pos-1]!=pos-2&&cant[pos-2]!=pos)chkmax(M[3][0],1ll*A[pos]*B[pos-1]+1ll*A[pos-1]*B[pos-2]+1ll*A[pos-2]*B[pos]);
  }
}
void build(int k,int l,int r){
  if(l==r)satori(T[k],l);
  else build(lson),build(rson),T[k]=T[k<<1]*T[k<<1|1];
}
void upd(int k,int l,int r,int x){
  if(l==r)satori(T[k],l);
  else x<=mid?upd(lson,x):upd(rson,x),T[k]=T[k<<1]*T[k<<1|1];
}

#undef mid
#undef lson
#undef rson

void solve(){
  n=read(),q=read();
  rep(i,1,n)W[i]=read(),tidW[i]=i;
  rep(i,1,n)H[i]=read(),tidH[i]=i;
  sort(tidW+1,tidW+n+1,[](int x,int y){return W[x]>W[y];});
  sort(tidH+1,tidH+n+1,[](int x,int y){return H[x]>H[y];});
  rep(i,1,n)mpW[tidW[i]]=i,A[i]=W[tidW[i]];
  rep(i,1,n)mpH[tidH[i]]=i,B[i]=H[tidH[i]];
  rep(i,1,n)cant[mpW[i]]=mpH[i];
//  rep(i,1,n)printf("%d%c",A[i],"\n "[i<n]);
//  rep(i,1,n)printf("%d%c",B[i],"\n "[i<n]);
  build(1,1,n);
//  write(T[1][0][0]),pc(10);
  while(q--){
    int x=mpW[read()],y=mpW[read()];
    swap(cant[x],cant[y]);
    rep(i,0,2){
      if(x+i<=n)upd(1,1,n,x+i);
      if(y+i<=n)upd(1,1,n,y+i);
    }
    write(T[1][0][0]),pc(10);
  }
}

signed main(){
//  int T;cin>>T;
//  while(T--)solve();
  solve();
  orzjk::flush();
  return 0;
}