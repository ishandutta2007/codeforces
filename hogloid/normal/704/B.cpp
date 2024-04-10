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
int n,s,e;
int a[5005],b[5005],c[5005],d[5005],x[5005];
int main(){
  cin>>n>>s>>e;--s;--e;
  REP(i,n) cin>>x[i];
  REP(i,n) cin>>a[i];
  REP(i,n) cin>>b[i];
  REP(i,n) cin>>c[i];
  REP(i,n) cin>>d[i];

  REP(i,5005) REP(j,5005) dp[i][j]=INF;
  if(s==0){
    dp[1][0]=d[0];
  }else if(e!=0){
    dp[1][1]=d[0]+b[0];
  }else if(e==0){
    dp[1][1]=b[0];
  }

  REPN(i,n,1) REP(j,n) if(dp[i][j]<INF){
    int k=j;
    if(s<i) ++k;
    if(e<i) --k;

    if(k<0) continue;
    if(j==0 && k==0) continue;

    lint dif=x[i]-x[i-1];
    lint val=dp[i][j]+dif*(j+k);
   
    if(i!=s && i!=e){
      chmin(dp[i+1][j+1],val+b[i]+d[i]);
      if(j>0) chmin(dp[i+1][j],val+b[i]+c[i]);
      if(k>0) chmin(dp[i+1][j],val+a[i]+d[i]);
      if(k>0 && j>0) chmin(dp[i+1][j-1],val+a[i]+c[i]);
    }else if(i==s){
      if(j>0) chmin(dp[i+1][j-1],val+c[i]);
      chmin(dp[i+1][j],val+d[i]);
    }else{
      chmin(dp[i+1][j+1],val+b[i]);
      if(k>0) chmin(dp[i+1][j],val+a[i]);
    }
  }
  lint res=dp[n][0];
  cout<<res<<endl;
  return 0;
}