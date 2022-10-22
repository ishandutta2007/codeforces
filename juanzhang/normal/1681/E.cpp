#include<bits/stdc++.h>
using namespace std;

#define int long long

#define rep(i,a,b) for(int i=(a),i##end=(b);i<=i##end;++i)
#define per(i,a,b) for(int i=(a),i##end=(b);i>=i##end;--i)
mt19937 Rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
template<typename T>void chkmax(T&x,T y){if(x<y)x=y;}
template<typename T>void chkmin(T&x,T y){if(x>y)x=y;}

#define pb push_back
#define ALL(x) (x).begin(),(x).end()
#define mem(x) memset((x),0,sizeof(x))

typedef double db;
typedef long long ll;
typedef vector<int>vi;
typedef pair<int,int>pii;

typedef unsigned u32;
typedef unsigned uint;
typedef unsigned long long u64;

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
void write(int x){
  static char st[21];
  if(!x)return pc(48),void();
  char*p=st;
  if(x<0)x=-x,pc('-');
  for(;x;x/=10)*p++=x%10|48;
  do{
    pc(*--p);
  }while(p!=st);
}

//const int P=1e9+7;
const int P=998244353;
int qp(int a,int k){
  int res=1;for(;k;k>>=1,a=1ll*a*a%P)if(k&1)res=1ll*res*a%P;return res;
}

const int maxn=1e5+10;
int n,q;

struct mat{
  int arr[2][2];
  void clear(){
    memset(arr,0x3f,sizeof arr);
  }
  int*operator[](int pos){
    return arr[pos];
  }
  const int*operator[](int pos)const{
    return arr[pos];
  }
  void pr(){
    printf("(%d %d)\n",arr[0][0],arr[0][1]);
  }
}I;
mat operator*(mat A,mat B){
  static mat C;
  C.clear();
  rep(i,0,1)rep(k,0,1)rep(j,0,1)chkmin(C[i][j],A[i][k]+B[k][j]);
  return C;
}

#define mid ((l+r)>>1)
#define lson k<<1,l,mid
#define rson k<<1|1,mid+1,r

mat T[maxn<<2];
void upd(int k,int l,int r,int x,mat M){
  if(l==r)T[k]=M;
  else x<=mid?upd(lson,x,M):upd(rson,x,M),T[k]=T[k<<1]*T[k<<1|1];
}
void query(int k,int l,int r,int ql,int qr,mat&M){
  if(ql<=l&&r<=qr){
    M=M*T[k];return;
  }
  if(ql<=mid)query(lson,ql,qr,M);
  if(qr>mid)query(rson,ql,qr,M);
}

#undef mid

struct point{
  int x,y;
  int lev(){
    return max(x,y);
  }
  void read(){
    x=::read(),y=::read();
  }
}A[maxn],A2[maxn],B[maxn],B2[maxn];

int qdis(point a,point b){
  return abs(a.x-b.x)+abs(a.y-b.y);
}

void solve(){
  n=read();
  rep(i,1,n-1){
    A[i].read(),B[i].read();
    A2[i]=A[i],A2[i].x++;
    B2[i]=B[i],B2[i].y++;
  }
  q=read();
  rep(i,2,n-1){
    mat M;
    M[0][0]=1+qdis(A2[i-1],A[i]);
    M[0][1]=1+qdis(A2[i-1],B[i]);
    M[1][0]=1+qdis(B2[i-1],A[i]);
    M[1][1]=1+qdis(B2[i-1],B[i]);
    upd(1,1,n,i,M);
  }
  while(q--){
    point a,b;
    a.read(),b.read();
    if(a.lev()>b.lev())swap(a,b);
    int ans;
    if(a.lev()==b.lev()){
      ans=qdis(a,b);
    }else{
      mat M;
      M.clear();
      M[0][0]=qdis(A[a.lev()],a);
      M[0][1]=qdis(B[a.lev()],a);
//      M.pr();
      if(a.lev()+1<b.lev())query(1,1,n,a.lev()+1,b.lev()-1,M);
//      M.pr();
      ans=min(M[0][0]+qdis(A2[b.lev()-1],b)+1,M[0][1]+qdis(B2[b.lev()-1],b)+1);
    }
    write(ans),pc(10);
  }
}

signed main(){
//  freopen("data.in","r",stdin);
//  freopen(".out","w",stdout);
//  int T;cin>>T;while(T--)solve();
  solve();
  orzjk::flush();
  return 0;
}