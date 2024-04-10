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

const int INF=5e8;

int n,k;
int ar[5005];
map<int,int> memo;
int main(){
  cin>>n>>k;
  REP(i,n){
    cin>>ar[i];
    REP(j,k){
      int val=ar[i]*(j+1);
      if(memo.count(val)==0) memo[val]=j+1;
      else chmin(memo[val],j+1);
    }
  }
  memo[0]=0;
  int q;cin>>q;
  REP(hoge,q){
    int x;cin>>x;

    int res=INF;
    REP(i,n) REP(j,k+1){
      int rest=x-ar[i]*j;
      if(memo.count(rest)) chmin(res,memo[rest]+j);
    }
    if(res>k) res=-1;
    cout<<res<<endl;
  }
  return 0;
}