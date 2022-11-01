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

Int mpow(Int a,lint k){
  Int res=1;
  while(k){
    if(k&1) res=res*a;
    a=a*a;
    k>>=1;
  }
  return res;
}

Int dp[5005][5005];
int n;
Int C[5005][5005];
char s[5005],s2[5005];
int nxt[5005][26];
int main(){
  REP(i,5004){
    C[i][0]=1;
    REP(j,i) C[i][j+1]=C[i-1][j+1]+C[i-1][j];
  }
  
  cin>>n;
  int N=n,n2=0;
  scanf("%s",s);
  REP(i,n){
    int j=i;
    while(j<n && s[j]==s[i]) ++j;
    s2[n2++]=s[i];
    i=j-1;
  }
  n=n2;
  CLR(s);
  REP(i,n) s[i]=s2[i];

  memset(nxt,-1,sizeof(nxt));
  REP(i,n){
    for(int j=i;j<n;++j) if(nxt[i][s[j]-'a']==-1){
      nxt[i][s[j]-'a']=j;
    }
  }


  dp[0][0]=1;
  REP(i,n) REP(j,i+1) if(dp[i][j].x){
    REP(c,26){
      int k=nxt[i][c];
      if(k==-1) continue;
      if(i && s[i-1]==s[k]){
        continue;
      }
      dp[k+1][j+1]+=dp[i][j];
    }
    dp[n][j]+=dp[i][j];
  }

  Int res=0;
  REPN(i,n+1,1){
    Int tmp=dp[n][i];
    int m=N-i;
    tmp*=C[i-1+m][m];
    res+=tmp;
  }
  cout<<res<<endl;
  return 0;
}