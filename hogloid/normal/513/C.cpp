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
pi range[10];

double dp[7][10005];
int main(){
  cin>>n;
  REP(i,n) cin>>range[i].fr>>range[i].sc;

  int perm[10];
  REP(i,n) perm[i]=i;

  double res=0;
  do{
    REP(i,n+1) REP(j,10005) dp[i][j]=0;

    dp[0][0]=1;
    REP(i,n){
      REP(j,10001) if(dp[i][j]>1e-100){
        double p=dp[i][j];
        int len=range[perm[i]].sc-range[perm[i]].fr+1;
        int L=range[perm[i]].fr,R=range[perm[i]].sc+1;
        if(i>0 && perm[i-1]>perm[i]) chmax(L,j+1);
        else chmax(L,j);

        if(L>=R) continue;

        if(i==n-1) res+=p/len*(R-L)*j;
        else{
          dp[i+1][L]+=p/len;
          dp[i+1][R]-=p/len;
        }
      }
      REP(j,10000) dp[i+1][j+1]+=dp[i+1][j];
    }
  }while(next_permutation(perm,perm+n));
  printf("%.10f\n",res);

  return 0;
}