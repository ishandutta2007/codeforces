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
const double PI = 4.0*atan(1.0);

typedef complex<double> P;
const P I(0, 1);

Int omega[30];
const int M=23,Prim=31;
void fft(int n, bool inv, Int a[],Int w2) {
  Int ww=w2;
  if(inv){
    Int one=1;
    ww=one/ww;
  }
  for (int m = n; m >= 2; m >>= 1) {
    int mh = m >> 1;
    Int w=1;
    for (int i = 0; i < mh; i++) {
      for (int j = i; j < n; j += m) {
        int k = j + mh;
        Int x = a[j] - a[k];
        a[j] += a[k];
        a[k] = w * x;
      }
      w*=ww;
    }
    ww=ww*ww;
  }
  int i = 0;
  for (int j = 1; j < n - 1; j++) {
    for (int k = n >> 1; k > (i ^= k); k >>= 1);
    if (j < i) swap(a[i], a[j]);
  }
}

void conv(Int a[], Int b[],int n){
  int logn=0;
  while((1<<logn)<n) ++logn;
  assert(logn<=23);

  omega[M]=Prim;
  for(int i=M-1;i>=0;--i) omega[i]=omega[i+1]*omega[i+1];
  fft(n,false,a,omega[logn]);
  fft(n,false,b,omega[logn]);
  REP(i,n) a[i]*=b[i];
  fft(n,true,a,omega[logn]);
  REP(i,n) a[i]/=n;
}

int n,m,K;
char S[200005],T[200005];
bool ok[200005];
Int ar1[550000],ar2[550000];
const int INF=5e8;

void solve(char c){
  CLR(ar1);CLR(ar2);
  int last=-INF;
  REP(i,n){
    if(S[i]==c) last=i;
    if(i-last<=K) ar1[i]=1;
  }
  last=INF;
  for(int i=n-1;i>=0;--i) {
    if(S[i]==c) last=i;
    if(last-i<=K) ar1[i]=1;
  }
  int cnt=0;
  REP(i,m) if(T[i]==c){
    ar2[i]=1;
    ++cnt;
  }

  conv(ar1,ar2,(1<<18));

  REP(i,n-m+1){
    int cnt2=ar1[i+m-1].x;
    if(cnt==cnt2) ;
    else ok[i]=false;
  }
}
int main(){
  cin>>n>>m>>K>>S>>T;
  reverse(T,T+m);

  REP(i,n-m+1) ok[i]=1;
  char tmp[]="ATGC";
  REP(i,4) solve(tmp[i]);
  int res=0;
  REP(i,n-m+1) if(ok[i]) ++res;
  cout<<res<<endl;

  return 0;
}