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
int n;
int ar[100005];

int cost1[100005],cost2[100005];
void doit(int* cost){
  pi ever=mp(-1,0);
  REP(i,n){
    cost[i]=(i-ever.fr)+ever.sc;
    if(ever.sc-ever.fr>(ar[i]-i)){
      ever=mp(i,ar[i]);
    }
  }
}
int main(){
  cin>>n;
  REP(i,n) scanf("%d",&ar[i]);

  doit(cost1);
  reverse(ar,ar+n);
  doit(cost2);
  reverse(ar,ar+n);
  reverse(cost2,cost2+n);

  int dist[100005]={0};

  REP(i,n) dist[i]=min({cost1[i],cost2[i],ar[i]});

  int res=*max_element(dist,dist+n);

  cout<<res<<endl;

  return 0;
}