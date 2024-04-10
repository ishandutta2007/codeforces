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

const int INF=1e9;
int n;
int ar[4005];

set<pair<pi,pi> >state;

int difmax=0,kmax=0;
void rec(int a,int b,int k,int turn){
  if(a+b>n) return;
  if(state.count(mp(mp(a,b),mp(k,turn)))) return;
  chmax(difmax,abs(a-b));
  chmax(kmax,k);
  state.insert(mp(mp(a,b),mp(k,turn)));
  if(turn){
    rec(a,b+k,k,0);
    rec(a,b+k+1,k+1,0);
  }else{
    rec(a+k,b,k,1);
    rec(a+k+1,b,k+1,1);
  }
}

int dp[4005][130][90][2];//dp[a][b-a+65][k][turn]
bool mark[4005][130][90][2];

int sum[4005];

int get(int a,int b,int k,int t,int def){
  if(abs(b-a)<65 && k<90 && a<=n && mark[a][b-a+65][k][t]) return dp[a][b-a+65][k][t];
  return def;
}

int main(){
  cin>>n;
  REP(i,n) cin>>ar[i];
  REP(i,n) sum[i+1]=sum[i]+ar[i];

  for(int i=n;i>=0;--i) for(int j=129;j>=0;--j) for(int k=89;k>=0;--k) REP(t,2){
    int a=i,b=i+j-65;
    if(a+b>n || b<0) continue;
    int& val=dp[i][j][k][t];
    if(a+b+k>n){
      val=sum[a]-(sum[n]-sum[n-b]);
      mark[i][j][k][t]=1;
    }else{
      if(t==0){
        val=-INF;
        chmax(val,get(a+k,b,k,1,-INF));
        if(a+b+k+1<=n) chmax(val,get(a+k+1,b,k+1,1,-INF));
        if(val!=-INF) mark[i][j][k][t]=1;
      }else{
        val=INF;
        chmin(val,get(a,b+k,k,0,INF));
        if(a+b+k+1<=n) chmin(val,get(a,b+k+1,k+1,0,INF));
        if(val!=INF) mark[i][j][k][t]=1;
      }
    }
  }
  cout<<dp[0][65][1][0]<<endl;

  return 0;
}