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

const int INF=1e9;
int n,k;

int ar[30005];


int dp[30005][205][2][2];//0:UP 1:DOWN 0:BLANK 1:IN RANGE

int solve(){
  REP(i,n+1) REP(j,k+1) REP(t,2) REP(t2,2) dp[i][j][t][t2]=-INF;
  dp[0][0][0][0]=0;
  dp[0][0][1][0]=0;

  REP(i,n) REP(j,k+1) REP(t,2){
    int sign=(t==0?1:-1);
    if(dp[i][j][t][0]>-INF){
      int val=dp[i][j][t][0];

      chmax(dp[i+1][j][t][0],val);
      if(j>0 && j+1<k) chmax(dp[i+1][j+1][t][0],val);

      chmax(dp[i][j][t][1],val);
    }
    if(dp[i][j][t][1]>-INF && j<k){
      int val=dp[i][j][t][1];
      int coef=2;
      if(j==0 || j==k-1) coef=1;

      chmax(dp[i+1][j][t][1],val+ar[i]*coef*sign);
      chmax(dp[i+1][j+1][t^1][0],val+ar[i]*coef*sign);
    }
  }
  int res=-INF;
  REP(t,2) REP(t2,2) chmax(res,dp[n][k][t][t2]);
  return res;
}
int main(){
  cin>>n>>k;
  REP(i,n) cin>>ar[i];

  int res=solve();

  cout<<res<<endl;

  return 0;
}