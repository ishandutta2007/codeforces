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

int n;
int g[2005][2005];

lint cost[2005];
bool done[2005],mark[2005];

pair<int,pi> es[2000005];
int main(){
  cin>>n;
  REP(i,n) REP(j,n-1-i){
    scanf("%d",&g[i][i+1+j]);
    g[i+1+j][i]=g[i][i+1+j];
  }
  int mini=1e9+10;
  REP(i,n) REP(j,i){
    chmin(mini,g[i][j]);
  }
  REP(i,n) REP(j,n) if(i!=j) g[i][j]-=mini;
  int m=0;
  REP(i,n) REP(j,i) es[m++]={g[i][j],{i,j}};

  REP(i,n) cost[i]=INF;
  REP(i,n) REP(j,i) if(g[i][j]==0){
    mark[i]=mark[j]=1;
    cost[i]=cost[j]=0;
  }
  sort(es,es+m);
  REP(i,m){
    if(es[i].fr==0) continue;
    int a=es[i].sc.fr,b=es[i].sc.sc,c=es[i].fr;
    chmin(cost[b],cost[a]+c);
    chmin(cost[a],cost[b]+c);
    chmin(cost[b],c*2ll);
    chmin(cost[a],c*2ll);
  }
  REP(i,n){
    lint res=1e18;
    if(mark[i]){
      res=mini*(lint)(n-1);
    }else{
      res=cost[i];
      res+=mini*(lint)(n-1);
    }
    printL(res);
    putchar('\n');
  }
/*
  REP(i,n) cost[i]=INF;
  REP(i,n) REP(j,i) if(g[i][j]==mini){
    cost[i]=cost[j]=0;
  }

  REP(hoge,n){
    int who=-1;
    REP(i,n) if(!done[i] && (who==-1 || cost[i]<cost[who])) who=i;
    done[who]=1;
    REP(i,n) chmin(cost[i],cost[who]+g[who][i]-mini
  }
*/



  return 0;
}