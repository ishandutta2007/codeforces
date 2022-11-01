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
#include<complex>
const double PI=acos(-1.0);
typedef complex<double> P;
namespace std {
  bool operator < (const P& a, const P& b) {
    return real(a) != real(b) ? real(a) < real(b) : imag(a) < imag(b);
  }
}
double cross(const P& a, const P& b) {
  return imag(conj(a)*b);
}
double getit(P a,P b,P c){
  return abs(cross(b-a,c-a));
}
double dot(const P& a, const P& b) {
  return real(conj(a)*b);
}


//const int INF=5e8;
int n;
P ps[200005];
pi ps2[200005];
double pw2[200005];
/*
double dp[105];
double expAreaSmall(P* ps,int n){
  double res=0;
  REP(i,n+1) dp[i]=0;
  dp[0]=0;
  REP(i,n){
    for(int j=i+1;j<n;++j){
      dp[j]+=dp[i]+abs(cross(ps[0],ps[i],ps[j]));
    }
  }
  res=dp[n];
  ps[n]=ps[1];
  res+=expAreaSmall(ps+1,n-1);
  return res;
}*/
double expArea(){
  double res=0;
  REPN(i,n-1,1) res+=getit(ps[0],ps[i],ps[i+1]);
  res-=res/pw2[n];

  REP(i,n){
    double prob=0.5;
    double sum=0;
    REPN(j,min(100,n),1){
      prob*=0.5;
      sum+=getit(ps[i],ps[i+j],ps[i+j+1]);
      double coef=0.5;
      if(j==n-1) coef=1;
      res-=prob*sum*coef;
    }
  }
  if(n<=100){
    double tmp=pw2[n]/(pw2[n]-1-n-n*(double)(n-1)/2);
    res*=tmp;
  }
  return res/2;
}
double expBorder(){
  double res=0;
  REP(i,n) REPN(j,min(i+100,i+n),i+1){
    int x=ps2[j].fr-ps2[i].fr,y=ps2[j].sc-ps2[i].sc;
    res+=__gcd(abs(x),abs(y))/pw2[j-i+1];

    if(n<100) res-=__gcd(abs(x),abs(y))/pw2[n];
  }
  if(n<=100){
    double tmp=pw2[n]/(pw2[n]-1-n-n*(double)(n-1)/2);
    res*=tmp;
  }
  return res;
}
int main(){
  cin>>n;
  pw2[0]=1;
  REP(i,n*2) pw2[i+1]=pw2[i]*2;
  REP(i,n){
    int a,b;
    scanf("%d%d",&a,&b);
    ps2[i]=mp(a,b);
    ps2[i+n]=ps2[i];
    ps[i]=P((double)a,(double)b);
    ps[i+n]=ps[i];
  }

  double area=expArea();
  dump(area);
  double brd=expBorder();
  dump(brd);
  double res=area+1-brd/2;
  printf("%.10f\n",res);
  return 0;
}