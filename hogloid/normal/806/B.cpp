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

const int INF=5e8;
int n;
int ar[125][10];
int M=5;

int slv[10];

int getlevel(int a,int b){
  if(a==0) return 5;
  int res=0;
  while(a<=b) a*=2,++res;
  return min(5,res-1);
}
int base[10];
int calc1(int id,int r){//put more wa
  int tot=n,ac=0;
  REP(i,n) if(~ar[i][id]) ++ac;
  int lb=-1,ub=1e7;
  if(ac==0) return 0;
  while(ub-lb>1){
    int md=(lb+ub)>>1;
    int p=ac,q=tot+md;
    if(getlevel(p,q)>=r) ub=md;
    else lb=md;
  }
  return ub;
}
int calc2(int id,int r){//put more ac
  int tot=n,ac=0;
  REP(i,n) if(~ar[i][id]) ++ac;
  int lb=-1,ub=1e7;
  while(ub-lb>1){
    int md=(lb+ub)>>1;
    int p=ac+md,q=tot+md;
    if(getlevel(p,q)<=r) ub=md;
    else lb=md;
  }
  return ub;
}
int check(){
 int sum[2]={0};
  REP(t,2) REP(i,5){
    if(ar[t][i]!=-1) sum[t]+=(slv[i]+1)*500-ar[t][i]*2*(slv[i]+1);
  }
  if(sum[0]<=sum[1]) return INF;

  int res=0;
  REP(i,5){
    int A=ar[0][i],B=ar[1][i];
    if(A==-1) A=INF;
    if(B==-1) B=INF;
    if(A==B) ;
    else if(A<B) chmax(res,calc1(i,slv[i]));
    else {
      if(A==INF){
        ;
        if(base[i]<=slv[i]) ;
        else res=INF;
      }else{
        chmax(res,calc2(i,slv[i]));
      }
    }

  }
  REP(i,5){
    int A=ar[0][i],B=ar[1][i];
    if(A==-1) A=INF;
    if(B==-1) B=INF;
    if(A>B){
      if(A==INF){
        int ac=0;
        REP(j,n) if(~ar[j][i]) ++ac;
        int lev=getlevel(ac,n+res);
        if(lev<=slv[i]) ;
        else res=INF;
      }
    }
  }
  return res;
}
int dfs(int d){
  if(d==5){


    return check();
  }
  int res=INF;
  REP(i,6){
    slv[d]=i;
    chmin(res,dfs(d+1));
  }
  return res;
}
int main(){
  cin>>n;
  REP(i,n) REP(j,M) cin>>ar[i][j];

  REP(j,M){
    int ac=0;
    REP(i,n) if(~ar[i][j]) ++ac;
    base[j]=getlevel(ac,n);
  }
  {
    slv[0]=slv[1]=slv[2]=1;
    slv[3]=slv[4]=slv[5]=0;
    //dump(check());
  }
  int res;
  res=dfs(0);
  if(res==INF) res=-1;
  cout<<res<<endl; 
  return 0;
}