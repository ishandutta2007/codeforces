#include<bits/stdc++.h>
#define REP(i,m) for(int i=0;i<(m);++i)
#define REPN(i,m,in) for(int i=(in);i<(m);++i)
#define ALL(t) (t).begin(),(t).end()
#define CLR(a) memset((a),0,sizeof(a))
#define pb push_back
#define mp make_pair
#define fr first
#define sc second

using namespace std;


#ifndef ONLINE_JUDGE
#define dump(x)  cerr << #x << " = " << (x) << endl
#define prl cerr<<"called:"<< __LINE__<<endl
#define dumpR(x) cerr<<"\x1b[31m"<<#x<<" = " <<(x)<<"\x1b[39m"<<endl
#define dumpY(x) cerr<<"\x1b[33m"<<#x<<" = " <<(x)<<"\x1b[39m"<<endl
#define dumpG(x) cerr<<"\x1b[32m"<<#x<<" = " <<(x)<<"\x1b[39m"<<endl
template<class T> void debug(T a,T b){ for(;a!=b;++a) cerr<<*a<<' ';cerr<<endl;}
#else
#define dump(x) ;
#define dumpR(x) ;
#define dumpY(x) ;
#define dumpG(x) ;
#define prl ;
template<class T> void debug(T a,T b){ ;}
#endif

template<class T> void chmin(T& a,const T& b) { if(a>b) a=b; }
template<class T> void chmax(T& a,const T& b) { if(a<b) a=b; }
typedef long long int lint;
typedef pair<int,int> pi;

namespace std{
  template<class S,class T>
  ostream &operator <<(ostream& out,const pair<S,T>& a){
    out<<'('<<a.fr<<','<<a.sc<<')';
    return out;
  }
}

lint readL(){
  lint res;
#ifdef ONLINE_JUDGE
  scanf("%I64d",&res);
#else
  scanf("%lld",&res);
#endif
  return res;
}
void printL(lint res){
#ifdef ONLINE_JUDGE
  printf("%I64d",res);
#else
  printf("%lld",res);
#endif
}

template<lint mod>
struct Int_{
  unsigned x;
  unsigned mpow(Int_ a,unsigned k){
    Int_ res=1;
    while(k){
      if(k&1) res=res*a;
      a=a*a;
      k>>=1;
    }
    return res.x;
  }
  unsigned inverse(Int_ a){
    return mpow(a,mod-2);
  }
  Int_(): x(0) { }
  Int_(long long sig) {
    int sigt=sig%mod;
    if(sigt<0) sigt+=mod;
    x=sigt;
  }
  unsigned get() const { return (unsigned)x; }
  
  Int_ &operator+=(Int_ that) { if((x += that.x) >= mod) x -= mod; return *this; }
  Int_ &operator-=(Int_ that) { if((x += mod - that.x) >= mod) x -= mod; return *this; }
  Int_ &operator*=(Int_ that) { x = (unsigned long long)x * that.x % mod; return *this; }
  Int_ &operator=(Int_ that) { x=that.x; return *this;}
  Int_ &operator/=(Int_ that) { x=(unsigned long long) x * inverse(that.x)%mod; return *this;}
  bool operator==(Int_ that) const { return x==that.x; }
  bool operator!=(Int_ that) const { return x!=that.x; }

  Int_ operator-() const { return Int_(0)-Int_(*this);}
  Int_ operator+(Int_ that) const { return Int_(*this) += that; }
  Int_ operator-(Int_ that) const { return Int_(*this) -= that; }
  Int_ operator*(Int_ that) const { return Int_(*this) *= that; }
  Int_ operator/(Int_ that) const { return Int_(*this) /= that; }
  Int_ inv(){
    return Int_(mpow(x,mod-2));
  }
};

namespace std{
  template<lint mod>
  ostream &operator <<(ostream& out,const Int_<mod>& a){
    out<<a.get();
    return out;
  }
  template<lint mod>
  istream &operator >>(istream& in,Int_<mod>& a){
    in>>a.x;
    return in;
  }
};

typedef Int_<998244353> Int;

Int mpow(Int a,lint k){
  Int res=1;
  while(k){
    if(k&1) res=res*a;
    a=a*a;
    k>>=1;
  }
  return res;
}
/*
const int M;
Int fact[M+2],invf[M+2];
void prep(){
  fact[0]=invf[0]=1;
  REP(i,M){
    fact[i+1]=fact[i]*(i+1);
  }
  invf[M]=fact[M].inv();
  for(int i=M-1;i>=0;--i) invf[i]=invf[i+1]*(i+1);
}
Int C(int a,int b){
  if(a<0 || b<0 || a<b) return 0;
  return fact[a]*invf[a-b]*invf[b];
}
*/
//const int INF=5e8;


Int dp[2005][2005];
Int dp2[2005];
Int dp3[2005][2005];
Int dp4[2005];
int n;
int a,b;

Int pwX[4000005],pwY[4000005];

void showfrac(int a,int b){
  Int sample=a;
  sample/=b;
  dump(sample);
}
int main(){
  cin>>n>>a>>b;
  Int X=a;X/=b;
  Int Y=-X+1;
  dump(X);dump(Y);

  pwX[0]=pwY[0]=1;
  REP(i,n*n+1){
    pwX[i+1]=pwX[i]*X;
    pwY[i+1]=pwY[i]*Y;
  }

  dp3[1][0]=1;
  dp3[1][1]=1;
  for(int i=1;i<n;++i){
    for(int j=0;j<=i;++j){
      dp3[i+1][j+1]+=dp3[i][j]*pwX[(i-j)];
      dp3[i+1][j]+=dp3[i][j]*pwY[j];
    }
  }

  dp2[1]=0;

  for(int i=2;i<=n;++i){

    REPN(j,i,1) dp[i][j]=dp3[i][j];
    REPN(j,i,1){
      Int T=dp4[j];
    //  REPN(k,j,1) T+=dp[j][k];
      dp[i][j]-=dp[i][j]*T;
    }
    Int tot=0;
    REPN(j,i,1){
      tot+=dp[i][j];
    }
    dp4[i]=tot;
    REPN(j,i,1){
      dp2[i]+=dp[i][j]*((dp2[i-j]-(i-j)*(i-j-1)/2)+dp2[j]);
    }
    dp2[i]+=i*(i-1)/2;
    dp2[i]/=tot;
  }
  cout<<dp2[n]<<endl;
  return 0;
}