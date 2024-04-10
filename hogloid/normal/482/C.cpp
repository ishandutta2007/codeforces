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

int n;
char s[55][25];

lint share[1<<21];

double dp[1<<21];
int main(){
  cin>>n;
  REP(i,n) scanf("%s",s[i]);
  int m=strlen(s[0]);

  REP(i,n) REP(j,n) if(i!=j){
    lint same=0;
    REP(k,m) if(s[i][k]==s[j][k]) same|=(1ll<<k);

    share[same]|=(1ll<<i);
  }

  for(int i=(1<<m)-2;i>=0;--i){
    int other=0;
    REP(j,m) if(!(i>>j&1)){
      share[i]|=share[i|(1<<j)];
      dp[i]+=dp[i|(1<<j)];
      ++other;
    }
    dp[i]/=other;
    dp[i]+=1.0/n*__builtin_popcountll(share[i]);
  }

  printf("%.10f\n",dp[0]);
  return 0;
}