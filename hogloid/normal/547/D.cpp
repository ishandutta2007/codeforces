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
pi ps[200005];

set<pi> g[400005];
const int L=200001;
vector<int> oddE;
void del(int i){
  g[ps[i].fr].erase(mp(ps[i].sc+L,i));
  g[ps[i].sc+L].erase(mp(ps[i].fr,i));
}

void rec(int v){
  oddE.pb(g[v].begin()->sc);
  int to=g[v].begin()->fr;
  del(g[v].begin()->sc);
  if(g[to].size()&1) rec(to);
}

int res[200005];
int deg[400005];
void dfs(int v,int& c){
  while(!g[v].empty()){
    auto it=g[v].begin();
    int to=it->fr,id=it->sc;
    res[id]=c;

    deg[v]+=(c==0?-1:1);
    deg[to]+=(c==0?-1:1);

    c^=1;
    del(id);
    dfs(to,c);
  }
}
int main(){
  cin>>n;
  REP(i,n){
    scanf("%d%d",&ps[i].fr,&ps[i].sc);
    g[ps[i].fr].insert(mp(ps[i].sc+L,i));
    g[ps[i].sc+L].insert(mp(ps[i].fr,i));
  }
  REP(i,L*2) if(g[i].size()&1){
    rec(i);
  }
  prl;
  REP(i,L*2){
    int c=0;
    dfs(i,c);
  }
  prl;
  reverse(ALL(oddE));
  int c=0;
  for(auto id:oddE){
    int a=ps[id].fr,b=ps[id].sc+L;
    res[id]=(c&1);
    ++c;
  }
  REP(i,n) putchar(res[i]?'r':'b');
  putchar('\n');

  return 0;
}