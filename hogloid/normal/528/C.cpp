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
int n,m;
pi es[400005];
int deg[100005];

vector<pi> g[100005];
int used[400005];
vector<int> cycle;
void dfs(int v,vector<int>& sub,int r){
  if(sub.size()>0 && v==r) return;
  sub.pb(v);
  for(auto e:g[v]) if(!used[e.sc]){
    used[e.sc]=1;
    --deg[v];--deg[e.fr];
    dfs(e.fr,sub,r);
    break;
  }
}
void solve(int v){
  vector<int> sub;
  dfs(v,sub,v);
  for(auto u:sub){
    if(deg[u]>0){
      solve(u);
    }
    cycle.pb(u);
  }
}

int main(){
  cin>>n>>m;
  REP(i,m){
    int a,b;scanf("%d%d",&a,&b);--a;--b;
    es[i]=mp(a,b);
    ++deg[a];++deg[b];
  }
  REP(i,n) if(deg[i]&1){
    int j=i+1;
    ++deg[i];
    while(j<n && !(deg[j]&1)) ++j;
    ++deg[j];
    es[m++]=mp(i,j);
    i=j;
  }
  if(m&1){
    deg[0]+=2;
    es[m++]=mp(0,0);
  }
  REP(i,m){
    int a=es[i].fr,b=es[i].sc;
    g[a].pb(mp(b,i));
    g[b].pb(mp(a,i));
  }
  solve(0);
  cycle.pb(0);
  cout<<m<<endl;
  REP(i,m){
    int a=cycle[i],b=cycle[i+1];
    if(i&1) swap(a,b);
    printf("%d %d\n",a+1,b+1);
  }
  return 0;
}