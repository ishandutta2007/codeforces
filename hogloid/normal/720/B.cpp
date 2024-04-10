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

//const int INF=5e8;


int n,m,m2;
vector<pair<pi,int> > g[10005];
pair<pi,int> es[20005];
int low[10005],pre[10005],cnt;
int dfs(int v,int p){
  pre[v]=low[v]=cnt;++cnt;
  for(auto e:g[v]){
    int to=e.fr.fr;
    if(e.sc==p) continue;
    if(pre[to]==-1) chmin(low[v],dfs(to,e.sc));
    else{
      chmin(low[v],pre[to]);
    }
    if(low[to]>pre[v]){
      es[m2++]={{v,to},e.fr.sc};
    }
  }
  return low[v];
}


vector<pi> belong[10005];
vector<int> cycle[10005];

bool vis[10005];

vector<int> path;

int K;//n.o. cycles
void prep(int v,int p){
  vis[v]=1;
  path.pb(v);
  for(auto e:g[v]){
    if(e.sc==p) continue;
    int to=e.fr.fr;
    if(vis[to]){
      for(int i=path.size()-1;i>=0;--i) if(path[i]==to){
        REPN(j,path.size(),i) cycle[K].pb(path[j]);
        ++K;
        break;
      }
    }else{
      prep(to,e.sc);
    }
  }
  path.pop_back();
}


const int INF=5e8;
struct Dinic{
  struct edge{
    int to,cap,rev;
    edge(int st,int sc,int sr){
      to=st;cap=sc;rev=sr;
    }
  };
  static const int MAX_SIZE=30005;
  vector<edge> g[MAX_SIZE];
  int rankk[MAX_SIZE],seen[MAX_SIZE];
  int src,sink;
  int SS,TT;
  void add_edge(int from,int to,int cap){
    g[from].pb(edge(to,cap,g[to].size()));
    g[to].pb(edge(from,0,g[from].size()-1));
  }
  void add_edge(int from,int to,int mncap,int cap){//assume cap>=mncap
    add_edge(from,to,cap-mncap);
    add_edge(SS,to,mncap);
    add_edge(from,TT,mncap);
  }
  void bfs(int v){
    memset(rankk,-1,sizeof(rankk));
    rankk[v]=0;
    queue<int>q;q.push(v);
    while(!q.empty()){
      int cur=q.front();q.pop();
      REP(i,g[cur].size()){
        edge& e=g[cur][i];
        if(e.cap>0 && rankk[e.to]==-1){
          rankk[e.to]=rankk[cur]+1;
          q.push(e.to);
        }
      }
    }
  }
  int dfs(int v,int f){
    if(v==sink) return f;
    for(int& i=seen[v];i<g[v].size();++i){
      edge& e=g[v][i];
      if(e.cap>0 && rankk[e.to]>rankk[v]){
        int d=dfs(e.to,min(e.cap,f));
        if(d>0){
          e.cap-=d;
          g[e.to][e.rev].cap+=d;
          return d;
        }
      }
    }
    return 0;
  }
  int flow_(){
    int flow=0;
    while(1){
      bfs(src);
      if(rankk[sink]==-1) return flow;
      int f;
      memset(seen,0,sizeof(seen));
      while((f=dfs(src,INF))>0){
        flow+=f;
      }
    }
  }
  int flow(int S_,int T_){//without minflow restriction
    src=S_;
    sink=T_;
    return flow_();
  }

  int flow2(int S_,int T_){//with minflow restriction
    src=SS;sink=TT;
    add_edge(T_,S_,INF);
    flow_();
    for(auto e:g[SS]) if(e.cap>0) return -1;

    src=S_;sink=T_;
    return flow_();
  }
};
Dinic D;

vector<int> cols[10005];
int main(){
  cin>>n>>m;
  REP(i,m){
    int a,b,c;scanf("%d%d%d",&a,&b,&c);--a;--b;--c;
    if(a>b) swap(a,b);
    es[i]={{a,b},c};
    g[a].pb({{b,c},i});
    g[b].pb({{a,c},i});
  }
  m2=m;
  dump(m);
  memset(pre,-1,sizeof(pre));
  dfs(0,-1);
  dump(m2);
  REPN(i,m2,m){
    int a=es[i].fr.fr,b=es[i].fr.sc,c=es[i].sc;
    g[a].pb({{b,c},i});
    g[b].pb({{a,c},i});
  }
  m=m2;
  sort(es,es+m);

  REP(i,n) if(!vis[i]){
    prep(i,-1);
  }

  int S=K+m,T=S+1;
  REP(i,K){
    REP(j,cycle[i].size()){
      int a=cycle[i][j],b=cycle[i][(j+1)%cycle[i].size()];
      if(a>b) swap(a,b);
      int c=lower_bound(es,es+m,mp(mp(a,b),-1))->sc;
      cols[i].pb(c);
    }
    D.add_edge(S,i,cycle[i].size()-1);
    for(auto e:cols[i]){
      D.add_edge(i,K+e,1);
    }
  }
  REP(i,m) D.add_edge(K+i,T,1);
  int res=D.flow(S,T);
  cout<<res<<endl;
  return 0;
}