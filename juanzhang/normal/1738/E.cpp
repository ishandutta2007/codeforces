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

int read(){
  int x=0,f=1;char c=nc();
  while(c<48)c=='-'&&(f=-1),c=nc();
  while(c>47)x=x*10+(c^48),c=nc();
  return x*f;
}
template<class T>void write(T x){
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

const int maxn=1e5+10;
int n,A[maxn],lef0[maxn],rig0[maxn];
ll sum[maxn];
ll ask(int l,int r){
  return sum[r]-sum[l-1];
}

int Inc(int x,int y){return x+y<P?x+y:x+y-P;}
int Dec(int x,int y){return x<y?x-y+P:x-y;}
void Add(int &x,int y){x+=y;if(x>=P)x-=P;}
void Sub(int &x,int y){x-=y;if(x<0)x+=P;}
int qp(int a,int k){int res=1;for(;k;k>>=1,a=1ll*a*a%P)if(k&1)res=1ll*res*a%P;return res;}

int inv[maxn],fac[maxn],ifac[maxn];
int binom(int n,int m){return n<m?0:1ll*fac[n]*ifac[m]%P*ifac[n-m]%P;}
void init(){
  fac[0]=ifac[0]=inv[1]=fac[1]=ifac[1]=1;
  rep(i,2,maxn-1)inv[i]=1ll*(P-P/i)*inv[P%i]%P,fac[i]=1ll*i*fac[i-1]%P,ifac[i]=1ll*inv[i]*ifac[i-1]%P;
}

int pw2[maxn];

int calc(int a,int b){
  int res=0;
  rep(i,0,min(a,b)){
    res=(res+1ll*binom(a+1,i+1)*binom(b+1,i+1))%P;
  }
//  rep(a,0,x)rep(b,0,y)rep(i,0,min(a,b)){
//    res=(res+1ll*binom(a,i)*binom(b,i))%P;
//  }
  return res;
}

void solve(){
  n=read();
  pw2[0]=1;
  rep(i,1,n)pw2[i]=2*pw2[i-1]%P;
  rep(i,0,n+1)A[i]=lef0[i]=rig0[i]=sum[i]=0;
  rep(i,1,n)A[i]=read(),sum[i]=sum[i-1]+A[i];
  rep(i,1,n)rig0[i]=A[i]?0:rig0[i-1]+1;
  per(i,n,1)lef0[i]=A[i]?0:lef0[i+1]+1;
  vector<pii>vec;
  vec.pb({0,n+1});
  for(int i=1,j=n+1;i<=n;i++){
    while(j>i+1&&ask(j-1,n)<ask(1,i))j--;
    if(j>i+1&&ask(j-1,n)==ask(1,i)){
      if(A[i]){
        vec.pb({i,j-1});
      }
    }
  }
  vi dp(vec.size(),0);
  if(lef0[1]==n){
    cout<<pw2[n-1]<<endl;
    return;
  }
  rep(i,0,min(lef0[1],rig0[n]))Add(dp[0],1ll*binom(lef0[1],i)*binom(rig0[n],i)%P);
  int sum=dp[0];
  rep(i,1,vec.size()-1){
    int res=sum;
    int l=vec[i].first,r=vec[i].second;
    if(l+1==r){
      dp[i]=res;
    }else if(l+1+lef0[l+1]-1>=r-1){
      dp[i]=1ll*res*(pw2[r-l]-1)%P;
    }else{
      dp[i]=1ll*calc(lef0[l+1],rig0[r-1])%P*res%P;
    }
    Add(sum,dp[i]);
//    printf("(%d %d) %d\n",l,r,dp[i]);
  }
  int as=0;
  for(int x:dp)as=(as+x)%P;
  cout<<as<<endl;
}

signed main(){
  init();
//  freopen(".in","r",stdin);
//  freopen(".out","w",stdout);
  int T;cin>>T;while(T--)solve();
//  solve();
  orzjk::flush();
  return 0;
}