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

//const int INF=5e8;

int n,M,T;
int read(){
  int h,m,s;
  scanf("%d:%d:%d",&h,&m,&s);
  return s+m*60+h*60*60;
}
int ar[20005];
int ans[20005];
int main(){
  cin>>n>>M>>T;
  REP(i,n){
    ar[i]=read();
  }
  deque<pi> dq;
  int res=0,ok=0;
  REP(i,n){
    while(!dq.empty() && dq.front().fr+T<=ar[i]) dq.pop_front();
    if(dq.size()==M){
      ans[i]=ans[dq.back().sc];
      dq.pop_back();
      dq.pb(mp(ar[i],i));
    }else{
      dq.pb(mp(ar[i],i));
      ans[i]=res;
      ++res;
    }
    if(dq.size()==M) ok=1;
  }
  if(!ok) puts("No solution");
  else {
    cout<<res<<endl;
    REP(i,n) printf("%d\n",ans[i]+1);
  }
  return 0;
}