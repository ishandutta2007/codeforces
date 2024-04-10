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

const int INF=5e8;
struct Dinic{
  struct edge{
    int to,cap,rev;
    edge(int st,int sc,int sr){
      to=st;cap=sc;rev=sr;
    }
  };
  static const int MAX_SIZE=210;
  vector<edge> g[MAX_SIZE];
  int SS,TT;
  int rankk[MAX_SIZE],seen[MAX_SIZE];
  int src,sink;
  void init(){
    REP(i,MAX_SIZE) g[i].clear();
  }
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
  int flow(int S_,int T_){
    src=S_;
    sink=T_;
    return flow_();
  }

  int flow2(int S_,int T_){
    src=SS;sink=TT;
    add_edge(T_,S_,INF);
    flow_();
    for(auto e:g[SS]) if(e.cap>0) return -1;

    src=S_;sink=T_;
    return flow_();
  }
  vector<bool> getcut(int S,int T,int n,int& fl){//0: with S, 1: with T
    fl=flow(S,T);
    vector<bool> res(n);
    REP(i,n) res[i]=(rankk[i]==-1?1:0);
    return res;
  }
};

typedef pair<int,pi> E;
struct gomTree{
  static const int MAXN=205;
  vector<int> vs[MAXN];
  Dinic D;
  void addE(int a,int b,int c){
    D.add_edge(a,b,c);
    D.add_edge(b,a,c);
  }
  vector<E> getTree(vector<E> es,int n){
    int m=1;
    vector<E> res;
    REP(i,MAXN) vs[i].clear();
    REP(i,n) vs[0].pb(i);
    for(int i=0;i<n;++i){
      while(vs[i].size()>1){
        D.init();
        REP(j,i) REP(k,vs[j].size()-1) addE(vs[j][k],vs[j][k+1],INF);
        for(auto e:es) addE(e.sc.fr,e.sc.sc,e.fr);
        for(auto e:res) if(e.sc.fr!=i && e.sc.sc!=i) addE(vs[e.sc.fr][0],vs[e.sc.sc][0],INF);
        int S=vs[i][0],T=vs[i][1];
        int F;
        vector<bool> cut=D.getcut(S,T,n,F);
        vector<int> vs1,vs2;
        for(auto v:vs[i]){
          if(cut[v]) vs2.pb(v);
          else vs1.pb(v);
        }
        for(auto& e:res){
          if(e.sc.sc==i) swap(e.sc.sc,e.sc.fr);
          if(e.sc.fr==i && cut[vs[e.sc.sc][0]]==1) e.sc.fr=m;
        }
        res.pb({F,{i,m}});
        vs[i]=vs1;vs[m++]=vs2;
      }
    }
    for(auto& e:res){
      e.sc.fr=vs[e.sc.fr][0];
      e.sc.sc=vs[e.sc.sc][0];
    }
    return res;
  }
};

gomTree gom;
int n,m;
vector<E> es;

vector<pi> g[205];
int main(){
  cin>>n>>m;
  REP(i,m){
    int a,b,c;scanf("%d%d%d",&a,&b,&c);
    --a;--b;
    es.pb({c,{a,b}});
  }
  vector<E> es2=gom.getTree(es,n);
  int c2=-1,S=-1;
  for(auto e:es2){
    int a=e.sc.fr,b=e.sc.sc,c=e.fr;
    g[a].pb({b,c});
    g[b].pb({a,c});
    if(c2<c){
      c2=c;
      S=a;
    }
  }
  int res=0;
  for(auto e:es2) res+=e.fr;
  vector<int> path;
  priority_queue<pi> pq;pq.push({INF,S});
  bool vis[205]={0};
  while(!pq.empty()){
    pi cur=pq.top();pq.pop();
    int v=cur.sc;
    if(vis[v]) continue;
    vis[v]=1;
    path.pb(v);
    for(auto e:g[v]){
      pq.push({e.sc,e.fr});
    }
  }
  cout<<res<<endl;
  for(auto e:path) cout<<e+1<<endl;
  return 0;
}