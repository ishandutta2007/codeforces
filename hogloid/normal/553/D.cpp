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

int n,m,k;
vector<int> g[100005];
int mark[100005],done[100005];

int fcnt[100005];

bool check(double md){
  CLR(fcnt);
  CLR(done);
  queue<int> q;
  REP(i,n) if(mark[i]){
    q.push(i);
    done[i]=1;
  }
  while(!q.empty()){
    int cur=q.front();q.pop();
    for(auto to:g[cur]){
      ++fcnt[to];
      if(!done[to] && fcnt[to]/(double)g[to].size()>=1-md){
        q.push(to);
        done[to]=1;
      }
    }
  }
  REP(i,n) if(!done[i]) return true;
  return false;
}
int main(){
  cin>>n>>m>>k;
  REP(i,k){
    int a;scanf("%d",&a);--a;
    mark[a]=1;
  }
  REP(i,m){
    int a,b;scanf("%d%d",&a,&b);--a;--b;
    g[a].pb(b);
    g[b].pb(a);
  }

  double lb=0,ub=1;
  REP(hoge,50){
    double md=(lb+ub)/2;

    if(check(md)) lb=md;
    else ub=md;
  }
  check(lb-1e-11);

  vector<int> res;
  REP(i,n) if(!done[i]) res.pb(i);
  cout<<res.size()<<endl;
  for(auto v:res) printf("%d\n",v+1);
  return 0;
}