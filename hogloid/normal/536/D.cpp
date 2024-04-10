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
int n,m;
int S,T;
vector<pi> g[2005];
int ar[2005];
lint cost1[2005],cost2[2005];
void ijk(int S,lint* cost){
  REP(i,n) cost[i]=INF;
  cost[S]=0;
  typedef pair<lint,int> stat;
  priority_queue<stat,vector<stat>,greater<stat> >pq;
  pq.push(mp(0,S));
  while(!pq.empty()){
    stat cur=pq.top();pq.pop();
    if(cost[cur.sc]<cur.fr) continue;
    for(auto e:g[cur.sc]){
      if(cost[e.fr]>cur.fr+e.sc){
        cost[e.fr]=cur.fr+e.sc;
        pq.push(mp(cost[e.fr],e.fr));
      }
    }
  }
}

lint xzip[2005],yzip[2005],xn,ynn;
void doit(lint* cost,lint* zip,lint& m){
  REP(i,n) zip[i]=cost[i];
  sort(zip,zip+n);
  m=unique(zip,zip+n)-zip;
  REP(i,n) cost[i]=lower_bound(zip,zip+m,cost[i])-zip;
}

lint dp[2005][2005][2];

int sum[2005][2005];
lint val[2005][2005];
int getsum(int b,int t,int l,int r){
  return sum[t][r]+sum[b][l]-sum[t][l]-sum[b][r];
}
lint getval(int b,int t,int l,int r){
  return val[t][r]+val[b][l]-val[t][l]-val[b][r];
}

int main(){
  cin>>n>>m;
  cin>>S>>T;--S;--T;
  REP(i,n) cin>>ar[i];
  REP(hoge,m){
    int a,b,c;scanf("%d%d%d",&a,&b,&c);--a;--b;
    g[a].pb(mp(b,c));
    g[b].pb(mp(a,c));
  }
  ijk(S,cost1);
  ijk(T,cost2);
  doit(cost1,xzip,xn);
  doit(cost2,yzip,ynn);

  REP(i,n) ++sum[cost1[i]+1][cost2[i]+1],val[cost1[i]+1][cost2[i]+1]+=ar[i];
  REP(i,xn) REP(j,ynn){
    sum[i+1][j+1]+=sum[i+1][j]+sum[i][j+1]-sum[i][j];
    val[i+1][j+1]+=val[i+1][j]+val[i][j+1]-val[i][j];
  }
  debug(cost1,cost1+n);
  debug(cost2,cost2+n);
  debug(ar,ar+n);

  dump(val[xn][ynn]);

  for(int i=xn-1;i>=0;--i){
    for(int j=ynn-1;j>=0;--j){
      if(getsum(i,xn,j,ynn)==0) dp[i][j][0]=dp[i][j][1]=0;
      else{
        dp[i][j][0]=dp[i][j][1]=-INF;
        chmax(dp[i][j][0],dp[i+1][j][0]+getval(i,i+1,j,ynn));
        if(getsum(i,i+1,j,ynn)>0) chmax(dp[i][j][0],-dp[i+1][j][1]+getval(i,i+1,j,ynn));
        chmax(dp[i][j][1],dp[i][j+1][1]+getval(i,xn,j,j+1));
        if(getsum(i,xn,j,j+1)>0) chmax(dp[i][j][1],-dp[i][j+1][0]+getval(i,xn,j,j+1));
        dump(i);dump(j);dump(dp[i][j][0]);
      }
    }
  }
  lint res=dp[0][0][0];
  dump(res);
  if(res>0) puts("Break a heart");
  else if(res==0) puts("Flowers");
  else puts("Cry");
  return 0;
}