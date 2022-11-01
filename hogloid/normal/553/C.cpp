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
struct uf{

  static const int MAXN=100005;
  int par[MAXN];
  int size[MAXN];
  void init(){
    memset(par,-1,sizeof(par));
    REP(i,MAXN) size[i]=1;
  }
  int root(int a){
    if(par[a]==-1) return a;
    return par[a]=root(par[a]);
  }
  void unite(int a,int b){
    a=root(a);b=root(b);
    if(a==b) return;
    if(size[a]<size[b]) swap(a,b);

    par[b]=a;
    size[a]+=size[b];
  }
  bool same(int a,int b){
    return root(a)==root(b);
  }
};

uf u;

int n,m;

//const int INF=5e8;
pi es[100005];
vector<int> g[100005];

int col[100005];
void FAIL(){
  puts("0");
  exit(0);
}

void dfs(int v,int c){
  col[v]=c;
  for(auto to:g[v]){
    if(col[to]==-1) dfs(to,1-c);
    else if(col[to]!=1-c) FAIL();
  }
}
int main(){
  cin>>n>>m;
  u.init();
  int m2=0;
  REP(i,m){
    int a,b,c;
    scanf("%d%d%d",&a,&b,&c);--a;--b;
    if(c) u.unite(a,b);
    else es[m2++]=mp(a,b);
  }
  prl;
  memset(col,-1,sizeof(col));
  REP(i,m2){
    int a=es[i].fr,b=es[i].sc;
    a=u.root(a);b=u.root(b);
    dump(a);dump(b);
    g[a].pb(b);
    g[b].pb(a);
  }
  prl;
  int res=1;
  int comp=0;
  REP(i,n) if(u.root(i)==i && col[i]==-1){
    dfs(i,1);
    ++comp;
  }
  --comp;
  REP(hoge,comp){
    res=res*2%1000000007;
  }
  cout<<res<<endl;
  return 0;
}