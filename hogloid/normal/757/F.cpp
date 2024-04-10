#define DEB
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


#ifdef DEB
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

bool valid[200005];
struct DomTree{
  static const int MAX_V=200000;
 
  int semi[MAX_V],U[MAX_V],idom[MAX_V];
  int puf[MAX_V],par[MAX_V];
  int mn[MAX_V];
  void init(){
    memset(puf,-1,sizeof(puf));
    REP(i,MAX_V) mn[i]=i;
  }
  int root(int a){
    if(puf[a]==-1) return a;
    int r=root(puf[a]);
    if(semi[mn[puf[a]]]<semi[mn[a]]) mn[a]=mn[puf[a]];
    return puf[a]=r;
  }
  void unite(int a,int b){//a:parent
    puf[b]=a;
  }
  int eval(int v){
    root(v);
    return mn[v];
  }
  int cnt;
 
  int vs[MAX_V];//vertex sorted by dfs order
  vector<int> bucket[MAX_V];//bucket[v]:= vertices:x s.t. sdom(x)=v
  vector<int> g[MAX_V],rg[MAX_V];
 
 
  void dfs(int v){
    semi[v]=cnt;
    vs[cnt++]=v;
    for(int u:g[v]) if(semi[u]<0){
      par[u]=v;
      dfs(u);
    }
  }

  vector<int> g3[200005];
  int size[200005];
  int dfs3(int v){
    if(valid[v]) size[v]=1;
    for(auto to:g3[v]){
      size[v]+=dfs3(to);
    }
    return size[v];
  }
  int solve(int n,int r,vector<int>* g_){
    init();
    REP(i,n){
      g[i]=g_[i];
      rg[i].clear();
    }
    REP(i,n) for(auto to:g[i]){
      rg[to].pb(i);
    }
 
    REP(i,n) semi[i]=-1;
    cnt=0;
    dfs(r);
    for(int i=n-1;i>0;i--){
      int w=vs[i];
      for(int v:rg[w]){
        int u=eval(v);
        chmin(semi[w],semi[u]);
      }
      bucket[vs[semi[w]]].pb(w);
      for(int v:bucket[par[w]]) U[v]=eval(v);
      bucket[par[w]].clear();
      unite(par[w],w);
    }
    for(int i=1;i<n;i++){
      int w=vs[i];
      int u=U[w];
      if(semi[w]==semi[u]) idom[w]=semi[w];
      else idom[w]=idom[u];
    }
 
    for(int i=1;i<n;i++){
      int w=vs[i];
      idom[w]=vs[idom[w]];
    }
    idom[r]=-1;

    REP(i,n) if(i!=r) g3[idom[i]].pb(i);
    dfs3(r);
    int res=0;
    REP(i,n) if(i!=r) chmax(res,size[i]);
    return res;
  }
};
DomTree D;

int n,m,s;
vector<pi> g[200005];
const lint INF=1e18;
lint cost[200005];

vector<int> g2[200005];
int main(){
  cin>>n>>m>>s;
  --s;
  REP(i,m){
    int a,b,c;scanf("%d%d%d",&a,&b,&c);
    --a;--b;
    g[a].pb({b,c});
    g[b].pb({a,c});
  }
  REP(i,n) cost[i]=INF;
  typedef pair<lint,int> st;
  priority_queue<st,vector<st>,greater<st> >pq;
  pq.push({0,s});
  cost[s]=0;
  while(!pq.empty()){
    st cur=pq.top();pq.pop();
    if(cost[cur.sc]<cur.fr) continue;
    for(auto e:g[cur.sc]){
      if(cost[e.fr]>cur.fr+e.sc){
        cost[e.fr]=cur.fr+e.sc;
        pq.push({cost[e.fr],e.fr});
      }
    }
  }

  REP(i,n) if(cost[i]<INF) for(auto e:g[i]){
    if(cost[e.fr]==cost[i]+e.sc) g2[i].pb(e.fr);
  }
  REP(i,n) if(cost[i]<INF) valid[i]=1;
  REP(i,n) if(cost[i]==INF) g2[s].pb(i);


  int res=D.solve(n,s,g2);
  cout<<res<<endl;
  return 0;
}