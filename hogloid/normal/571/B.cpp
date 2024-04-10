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

const lint INF=1e18;

lint dp[5005][5005];
int n,k;
int ar[300005];
int main(){
  cin>>n>>k;
  REP(i,n) scanf("%d",&ar[i]);
  sort(ar,ar+n);
  int lcnt=n%k,scnt=k-lcnt;
  int lrg=n/k+1,sml=n/k;

  REP(i,k+1) REP(j,k+1) dp[i][j]=INF;

  dp[0][0]=0;
  REP(s,k+1){
    REP(i,s+1){
      int j=s-i;
      int sum=i*lrg+j*sml;
      
      if(sum+lrg<=n) chmin(dp[i+1][j],dp[i][j]+ar[sum+lrg-1]-ar[sum]);
      if(sum+sml<=n) chmin(dp[i][j+1],dp[i][j]+ar[sum+sml-1]-ar[sum]);
    }
  }
  lint res=dp[lcnt][scnt];
  cout<<res<<endl;
  return 0;
}