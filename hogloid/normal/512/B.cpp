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

const int INF=5e8;

int n;

pi card[305];
vector<int> factor;

vector<int> dp[305];
int main(){
  cin>>n;
  REP(i,n) cin>>card[i].fr;
  REP(i,n) cin>>card[i].sc;

  REP(i,n){
    int tmp=card[i].fr;
    for(int j=1;j*j<=tmp;++j) if(tmp%j==0){
      factor.pb(j);
      factor.pb(tmp/j);
    }
  }
  factor.pb(0);
  sort(ALL(factor));
  factor.erase(unique(ALL(factor)),factor.end());

  int m=factor.size();

  REP(i,n+1) dp[i].resize(m,INF);

  dp[0][0]=0;

  REP(i,n) REP(j,m) if(dp[i][j]<INF){
    chmin(dp[i+1][j],dp[i][j]);
    int k=factor[j];
    int l=card[i].fr;

    int nxt=__gcd(k,l);
    nxt=lower_bound(ALL(factor),nxt)-factor.begin();

    chmin(dp[i+1][nxt],dp[i][j]+card[i].sc);
  }
  int res=dp[n][1];
  if(res==INF) res=-1;

  cout<<res<<endl;
  return 0;
}