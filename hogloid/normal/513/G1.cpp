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
int n,k;
double dp[205][32][32];

int perm[105];

int dest(int l,int r,int j){
  if(j<l || j>=r) return j;
  return r-1-(j-l);
}

int main(){
  cin>>n>>k;
  REP(i,n) cin>>perm[i],--perm[i];

  REP(i,n) REP(j,n) if(perm[i]<perm[j]) dp[0][i][j]+=1;

  REP(i,k) REP(j,n) REP(j2,n) if(dp[i][j][j2]>1e-100){
    double p=dp[i][j][j2];
    REP(l,n) REPN(r,n+1,l+1){
      int t1=dest(l,r,j),t2=dest(l,r,j2);
      dp[i+1][t1][t2]+=p/n/(n+1)*2;
    }
  }

  double res=0;
  REP(j,n) REP(j2,n) if(dp[k][j][j2] && j>j2) res+=dp[k][j][j2];

  printf("%.10f\n",res);

  return 0;
}