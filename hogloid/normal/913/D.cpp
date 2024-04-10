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

int n,T;
int ar[200005],br[200005];

vector<int> ans;
bool check(int K){
  vector<pi> cands;
  REP(i,n) if(ar[i]>=K){
    cands.pb({br[i],i});
  }
  sort(ALL(cands));
  int psum=0;
  if(cands.size()<K) return false;
  REP(i,K){
    psum+=cands[i].fr;
  }
  if(psum>T) return false;
  ans.clear();
  REP(i,K) ans.pb(cands[i].sc);
  return true;
}
int main(){
  cin>>n>>T;
  REP(i,n){
    scanf("%d%d",&ar[i],&br[i]);
  }

  int lb=0,ub=n+1;
  while(ub-lb>1){
    int md=(lb+ub)>>1;
    if(check(md)) lb=md;
    else ub=md;
  }
  cout<<lb<<endl;
  cout<<lb<<endl;
  assert(check(lb));
  for(auto e:ans) printf("%d\n",e+1);
  return 0;
}