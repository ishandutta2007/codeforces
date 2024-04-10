#define DEB
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


#ifdef DEB
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
template<lint mod>
struct Int_{
  unsigned x;
  int mpow(Int_ a,int k){
    Int_ res=1;
    while(k){
      if(k&1) res=res*a;
      a=a*a;
      k>>=1;
    }
    return res.x;
  }
  int inverse(Int_ a){
    return mpow(a,mod-2);
  }
  Int_(): x(0) { }
  Int_(long long sig) { int sigt = sig % mod; if(sigt < 0) sigt += mod; x = sigt; }
  int get() const { return (int)x; }
  
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

typedef Int_<1000000021> Int1;
typedef Int_<1000000009> Int2;

typedef pair<Int1,Int2> pI;

char s[50005];
int n;

Int1 sum[50005],pw1[50005];
Int2 sum2[50005],pw2[50005];
bool cmp(int i,int j,int len){
  if(sum[i+len]-sum[i]*pw1[len] == sum[j+len]-sum[j]*pw1[len] && 
    sum2[i+len]-sum2[i]*pw2[len] == sum2[j+len]-sum2[j]*pw2[len]) return true;
    return false;
}

int getlcp(int i,int j){
  int lb=0,ub=n-max(i,j)+1;
  while(ub-lb>1){
    int md=(lb+ub)>>1;
    if(cmp(i,j,md)) lb=md;
    else ub=md;
  }
  return lb;
}
int getlcs(int i,int j){
  int lb=0,ub=min(i,j);
  while(ub-lb>1){
    int md=(lb+ub)>>1;
    if(cmp(i-md,j-md,md)) lb=md;
    else ub=md;
  }
  return lb;
}

bool check(int L){
  for(int i=0;i+L<=n;i+=L){
    if(getlcp(i,i+L)+getlcs(i,i+L)>=L){
      return true;
    }
  }
  return false;
}

const int P=100000007;
void init(){
  sum[0]=0;
  sum2[0]=0;
  REP(i,n){
    sum[i+1]=(sum[i]*P)+(s[i]);
    sum2[i+1]=sum2[i]*P+s[i];
  }
}

void del(int L){

  int m=L,same=0;
  for(int i=m;i<n;++i){
    if(s[i]==s[m-L]) ++same;
    else same=0;
    if(same==L){
      m-=L;
      same=0;
    }
    s[m++]=s[i];
  }
  n=m;
  s[m]='\0';

  init();
}
int main(){
  scanf("%s",s);
  n=strlen(s);

  pw1[0]=1;pw2[0]=1;
  REP(i,n){
    pw1[i+1]=pw1[i]*P;
    pw2[i+1]=pw2[i]*P;
  }
  init();

  for(int i=1;i*2<=n;++i){
    if(check(i)){
      del(i);
    }
  }
  cout<<s<<endl;


  return 0;
}