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
int mod;
struct Int {
  unsigned x;
  int mpow(Int a,int k){
    Int res=1;
    while(k){
      if(k&1) res=res*a;
      a=a*a;
      k>>=1;
    }
    return res.x;
  }
  int inverse(Int a){
    return mpow(a,mod-2);
  }
  Int(): x(0) { }
  Int(long long sig) { int sigt = sig % mod; if(sigt < 0) sigt += mod; x = sigt; }
  int get() const { return (int)x; }
  
  Int &operator+=(Int that) { if((x += that.x) >= mod) x -= mod; return *this; }
  Int &operator-=(Int that) { if((x += mod - that.x) >= mod) x -= mod; return *this; }
  Int &operator*=(Int that) { x = (unsigned long long)x * that.x % mod; return *this; }
  Int &operator=(Int that) { x=that.x; return *this;}
  Int &operator/=(Int that) { x=(unsigned long long) x * inverse(that.x)%mod; return *this;}
  Int &operator- () { x=mod-x; if(x==mod) x=0; return *this;}
  bool operator==(Int that){ return x==that.x; }
  bool operator!=(Int that){ return x!=that.x; }


  Int operator+(Int that) const { return Int(*this) += that; }
  Int operator-(Int that) const { return Int(*this) -= that; }
  Int operator*(Int that) const { return Int(*this) *= that; }
  Int operator/(Int that) const { return Int(*this) /= that; }

};


namespace std{
  ostream &operator <<(ostream& out,const Int& a){
    out<<a.get();
    return out;
  }
  istream &operator >>(istream& in,Int& a){
    in>>a.x;
    return in;
  }
};
//const int INF=5e8;
Int dp[2][505][505];
int n,m,b;
int ar[505];
int main(){
  cin>>n>>m>>b>>mod;
  REP(i,n) cin>>ar[i];

  dp[0][0][0]=1;
  int cur=0,nxt=1;

  REP(i,m){
    REP(j,b+1) REP(k,n) if(dp[cur][j][k]!=0){
      if(j+ar[k]<=b) dp[nxt][j+ar[k]][k]+=dp[cur][j][k];
      dp[cur][j][k+1]+=dp[cur][j][k];
    }
    swap(cur,nxt);
    CLR(dp[nxt]);
  }

  Int res=0;
  REP(j,b+1) REP(k,n) res+=dp[cur][j][k];
  cout<<res<<endl;
  return 0;
}