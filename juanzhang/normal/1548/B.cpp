#include<bits/stdc++.h>
using namespace std;

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

ll read(){
  ll x=0,f=1;char c=nc();
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

const int maxn=2e5+10;
int n;ll A[maxn],B[maxn];

int N;
ll tr[maxn*4];
void init(){
  for(N=1;N<n;N<<=1);
  rep(i,1,n)tr[N+i-1]=A[i];
  rep(i,n+1,N)tr[N+i-1]=0;
  per(i,N-1,1)tr[i]=__gcd(tr[i<<1],tr[i<<1|1]);
}
ll query(ll l,ll r){
  ll res=__gcd(tr[l+=N-1],tr[r+=N-1]);
  for(;(l^r)>>1;l>>=1,r>>=1){
    if(~l&1)res=__gcd(res,tr[l^1]);
    if(r&1)res=__gcd(res,tr[r^1]);
  }
  return res;
}
ll abso(ll x){
  return x<0?-x:x;
}

void solve(){
  n=read();
  rep(i,1,n)B[i]=read();
  if(n==1)return write(1),pc(10),void();
  n--;
  rep(i,1,n)A[i]=B[i+1]-B[i];
  int ans=1;
  init();
  for(int i=1,j=1;i<=n;i++){
    chkmax(j,i);
    while(j<n&&abso(query(i,j+1))>1)j++;
    if(abso(query(i,j))>1)chkmax(ans,j-i+2);
  }
  write(ans),pc(10);
}

signed main(){
  int T;cin>>T;while(T--)solve();
//  solve();
  orzjk::flush();
  return 0;
}