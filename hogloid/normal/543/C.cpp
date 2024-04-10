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
int n,m;
char s[25][25];
int ar[25][25];

int dp[1<<20];
pi sep[1000];
int main(){
  cin>>n>>m;
  REP(i,n) cin>>s[i];
  REP(i,n) REP(j,m) cin>>ar[i][j];

  int cnt=0;
  REP(j,m){
    REP(c,26){
      int mask=0,sum=0,mxi=0;
      REP(i,n) if(s[i][j]=='a'+c) mask|=(1<<i),sum+=ar[i][j],chmax(mxi,ar[i][j]);;
      if(mask>0){
        sum-=mxi;
        sep[cnt++]=mp(mask,sum);
      }
    }
  }
  REP(i,n){
    int mni=*min_element(ar[i],ar[i]+m);
    sep[cnt++]=mp(1<<i,mni);
  }
  REP(i,1<<n) dp[i]=INF;
  dp[0]=0;
  REP(i,1<<n) if(dp[i]<INF){
    REP(j,cnt) chmin(dp[i|sep[j].fr],dp[i]+sep[j].sc);
  }
  cout<<dp[(1<<n)-1]<<endl;
  return 0;
}