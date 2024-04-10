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

typedef Int_<1000000007> Int;

Int mpow(Int a,lint k){
  Int res=1;
  while(k){
    if(k&1) res=res*a;
    a=a*a;
    k>>=1;
  }
  return res;
}
//const int INF=5e8;
int dp[105][105];
int ar[200005];
int n;
Int Comb[200005];

Int coef[2][200005];
void doit(int len,int& sign,int cur){
  int nxt=1-cur;
  CLR(coef[nxt]);
  for(int i=len-1;i>=0;--i){
    coef[nxt][i]+=coef[cur][i];
    coef[nxt][i+1]+=coef[cur][i]*sign;
    sign*=-1;
  }
}
int main(){
  { 
    dp[0][0]=1;
    int sign=1;
    for(int i=1;i<12;++i){
      for(int j=i-1;j>=0;--j){
        dp[i][j]+=dp[i-1][j];
        dp[i][j+1]+=dp[i-1][j]*sign;
        sign*=-1;
      }
      debug(dp[i],dp[i]+i+1);
    }
  }
  
  cin>>n;
  REP(i,n) scanf("%d",&ar[i]);
  lint n2=n;
  if(n<=4){
    int sign;
    if(n2*(n2-1)/2%2==0) sign=-1;
    else sign=1;
    int cur=0;
    coef[cur][0]=1;
    for(int i=1;i<n;++i){
      doit(i,sign,cur);
      cur^=1;
      debug(coef[cur],coef[cur]+i+1);
    }
    Int res=0;
    REP(i,n) res+=coef[cur][i]*ar[i];
    cout<<res<<endl;
    return 0;
  }

  lint n3=n;

  while(n3%4!=1) --n3;
  dump(n3);
  int len=(n3-1)/2;
  Comb[0]=1;
  for(int i=1;i<=len;++i){
    Comb[i]=Comb[i-1]*(len+1-i)/i;
  }
  for(int i=0;i<n3;i+=2){
    coef[0][i]=Comb[i/2];
  }
  int cur=0;
  bool type=(n2*(n2-1)/2%2==0?true:false);
  int sign=(type?-1:1);
  for(int i=n3;i<n;++i){
    debug(coef[cur],coef[cur]+i);
    doit(i,sign,cur);
    cur^=1;
  }
  debug(coef[cur],coef[cur]+n);
  Int res=0;
  REP(i,n) res+=coef[cur][i]*ar[i];
  cout<<res<<endl;
  return 0;
}