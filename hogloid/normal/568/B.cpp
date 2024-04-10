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
template<class T> void debug(T a,T b){ for(;a!=b;++a) cerr<<*a<<' ';cerr<<endl;}
#else
#define dump(x) ;
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

//const int INF=5e8;


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
Int C[4005][4005];
Int dp[4005][2];
int main(){
  int n;
  cin>>n;
  REP(i,n+1){
    C[i][0]=1;
    REP(j,i) C[i][j+1]=C[i-1][j+1]+C[i-1][j];
  }
  dp[0][0]=1;
  REP(i,n) REP(t,2) if(dp[i][t].x!=0){
    REPN(j,n-i+1,1){
      if(j==1){
        dp[i+j][t]+=dp[i][t]*C[n-i-1][j-1];
        dp[i+j][1]+=dp[i][t]*C[n-i-1][j-1];
      }else{
        dp[i+j][t]+=dp[i][t]*C[n-i-1][j-1];
      }
    }
  }
  cout<<dp[n][1]<<endl;
  return 0;
}