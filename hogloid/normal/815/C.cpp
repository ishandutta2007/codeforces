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
#define dumpR(x) cerr<<"\x1b[31m"<<#x<<" = " <<(x)<<"\x1b[39m"<<endl
#define dumpY(x) cerr<<"\x1b[33m"<<#x<<" = " <<(x)<<"\x1b[39m"<<endl
#define dumpG(x) cerr<<"\x1b[32m"<<#x<<" = " <<(x)<<"\x1b[39m"<<endl
template<class T> void debug(T a,T b){ for(;a!=b;++a) cerr<<*a<<' ';cerr<<endl;}
#else
#define dump(x) ;
#define dumpR(x) ;
#define dumpY(x) ;
#define dumpG(x) ;
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
int n,B;
vector<int> g[5005];
pi ar[5005];

lint dp1[5005][5005],dp2[5005][5005];
//dp1: minimum cost if she use i-th coupon
//dp2: minimum cost if she don't use i-th coupon
int size[5005];

void merge(lint* dp1,lint* dp2,int S,int T){
  for(int i=S;i>=0;--i) for(int j=T;j>=0;--j){
    chmin(dp1[i+j],dp1[i]+dp2[j]);
  }
}
int dfs(int v){
  size[v]=1;
  dp1[v][0]=INF;dp1[v][1]=ar[v].sc;
  dp2[v][0]=0;dp2[v][1]=ar[v].fr;

  for(auto to:g[v]){
    dfs(to);
    merge(dp1[v],dp1[to],size[v],size[to]);
    merge(dp2[v],dp2[to],size[v],size[to]);

    size[v]+=size[to];
  }
  REP(i,size[v]+1) chmin(dp1[v][i],dp2[v][i]);
  return size[v];
}
int main(){
  //note that n can be 1
  cin>>n>>B;
  REP(i,n) REP(j,n+1) dp1[i][j]=dp2[i][j]=INF;
  REP(i,n){
    int c,d,x;
    scanf("%d%d",&c,&d);
    if(i>0){
      cin>>x;
      --x;
      g[x].pb(i);
    }
    ar[i]={c,c-d};
  }
  dfs(0);
  int res=0;
  for(int i=0;i<=n;++i) if(dp1[0][i]<=B) res=i;
  cout<<res<<endl;
  return 0;
}