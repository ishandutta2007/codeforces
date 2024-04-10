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

//const int INF=5e8;
lint n,K;

pi ar[65];

lint sm(lint x){
  return (x-1)/2;
}
lint lg(lint x){
  return x/2;
}

map<pair<lint,lint> ,lint> memo,memo2;
lint count(lint n,lint len){
  if(sm(n)<len || n==0) return 0;
  if(memo.count({n,len})) return memo[{n,len}];
  return memo[{n,len}]=count(sm(n),len)+count(lg(n),len)+1;
}
lint count2(lint n,lint len){
  if(sm(n)<len || n==0) return 0;
  if(memo2.count({n,len})) return memo2[{n,len}];
  return memo2[{n,len}]=count2(sm(n),len)+count2(lg(n),len)+(sm(n)==len?1:0);
}
void rec(lint n,lint wid,lint pos){
  if(n==0) return;
  if(sm(n)<wid) return;
  if(sm(n)==wid){
    if(K==0){
      cout<<pos+(n-1)/2<<endl;
      exit(0);
    }
    --K;
  }
  dump(n);dump(wid);dump(pos);dump(K);
  dump(count2(sm(n),wid));
  if(count2(sm(n),wid)>K)
    rec(sm(n),wid,pos);
  else{
    K-=count2(sm(n),wid);
    rec(lg(n),wid,pos+(n-1)/2+1);
  }
}
void solve(){
  if(K==0){
    puts("1");
    return;
  }
  if(K==1){
    cout<<n<<endl;
    return;
  }
  K-=2;

  lint lb=0,ub=n;
  while(ub-lb>1){
    lint md=(lb+ub)>>1;
    if(count(n-2,md)<K+1) ub=md;
    else lb=md;
  }
  dump(lb);
  K-=count(n-2,lb+1);
  dump(K);
  rec(n-2,lb,2);
}
int main(){
  cin>>n>>K;
  --K;
  solve();
  return 0;
}