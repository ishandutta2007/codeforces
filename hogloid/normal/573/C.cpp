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
vector<int> g[100005];

bool isseg[100005],isbi[100005];

map<pi,bool> memo1,memo2;
bool checkseg(int v,int p){
  if(memo1.count(mp(v,p))) return memo1[mp(v,p)];
  bool& res=memo1[mp(v,p)];

  if(g[v].size()>2) return res=false;
  for(auto to:g[v]){
    if(to==p) continue;
    if(!checkseg(to,v)) return res=false;
  }
  return res=true;
}

bool checkbi(int v,int p){
  if(memo2.count(mp(v,p))) return memo2[mp(v,p)];
  bool& res=memo2[mp(v,p)];

  if(g[v].size()>3) return res=false;
  for(auto to:g[v]){
    if(to==p) continue;
    if(!checkseg(to,v)) return res=false;
  }
  return res=true;
}

pi es[100005];

int dep[100005];
void dfs(int v,int p,int d){
  dep[v]=d;
  for(auto to:g[v]){
    if(to==p) continue;
    dfs(to,v,d+1);
  }
}

void OK(){
  puts("Yes");
  exit(0);
}
void NG(){
  puts("No");
  exit(0);
}

int main(){
  cin>>n;
  REP(i,n-1){
    int a,b;scanf("%d%d",&a,&b);
    --a;--b;
    g[a].pb(b);
    g[b].pb(a);
    es[i]=mp(a,b);
  }

  REP(i,n-1){
    int a=es[i].fr,b=es[i].sc;
    if(checkbi(a,b)) isbi[a]=1;
    if(checkbi(b,a)) isbi[b]=1;
  }

  vector<int> pivots;

  REP(i,n) if(!isbi[i]) pivots.pb(i);

  debug(ALL(pivots));

  if(pivots.empty()) OK();

  dfs(pivots[0],-1,0);
  debug(dep,dep+n);
  int mxwho=-1;
  for(auto v:pivots) if(mxwho==-1 || dep[v]>dep[mxwho]) mxwho=v;

  int A=mxwho,B=-1;
  dfs(A,-1,0);
  debug(dep,dep+n);

  int d1[100005],d2[100005];
  memcpy(d1,dep,sizeof(d1));

  mxwho=-1;
  for(auto v:pivots) if(mxwho==-1 || dep[v]>dep[mxwho]) mxwho=v;

  B=mxwho;
  dump(dep[B]);

  dfs(B,-1,0);
  debug(dep,dep+n);
  memcpy(d2,dep,sizeof(d2));

  int tot=dep[A];
  dump(A);dump(B);

  for(auto v:pivots) if(tot!=d1[v]+d2[v]) NG();
  OK();
  return 0;
}