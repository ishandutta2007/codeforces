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
int n,T;
pi ar[5005];

double mpow[105][5005];

double latsum[105][5005];

double dp[5005][5005];
int main(){

  REP(i,101){
    mpow[i][0]=1;
    REP(j,5003) mpow[i][j+1]=mpow[i][j]*(100-i)/100.0;
    double ever=0;
    REP(j,5003){
      latsum[i][j]=1-ever*i/100.0;
      ever+=mpow[i][j];
    }
  }

  cin>>n>>T;
  REP(i,n) cin>>ar[i].fr>>ar[i].sc;

  dp[0][0]=1;

  double res=0;
  REP(i,n){

    double prob=ar[i].fr/100.0;
    REP(j,T+1) if(dp[i][j]>1e-100){
      double p=dp[i][j];

      dp[i+1][j+1]+=p*prob;
      if(j+ar[i].sc<=T) dp[i+1][j+ar[i].sc]-=p*mpow[ar[i].fr][ar[i].sc-1]*prob;
      else res+=p*latsum[ar[i].fr][T-j]*i;
    }
    REP(j,T) if(dp[i+1][j]>1e-100){
      dp[i+1][j+1]+=dp[i+1][j]*(1-prob);
    }
    REP(j,T) if(dp[i][j]>1e-100){
      double p=dp[i][j];
      if(j+ar[i].sc<=T) dp[i+1][j+ar[i].sc]+=p*latsum[ar[i].fr][ar[i].sc-1];
    }
  }
  REP(j,T+1) res+=dp[n][j]*n;

  printf("%.10f\n",res);
  return 0;
}