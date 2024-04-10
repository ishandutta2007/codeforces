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
int n;
vector<int> g[200005];
int val[200005];
lint dp[200005][2];
void merge(lint* a,lint* b){
  lint tmp[2]={-INF,-INF};
  REP(i,2) REP(j,2){
    chmax(tmp[i^j],a[i]+b[j]);
  }
  REP(i,2) a[i]=tmp[i];
}
void rec(int v){
  dp[v][0]=0;
  dp[v][1]=-INF;
  for(auto to:g[v]){
    rec(to);
    merge(dp[v],dp[to]);
  }
  chmax(dp[v][1],dp[v][0]+val[v]);
}
int main(){
  cin>>n;
  REP(i,n){
    int p,a;scanf("%d%d",&p,&a);--p;
    val[i]=a;
    if(p>=0) g[p].pb(i);
  }
  rec(0);
  lint res=max(dp[0][1],dp[0][0]);
  cout<<res<<endl;

  return 0;
}