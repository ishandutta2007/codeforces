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
const int INF2=10000;
#include<queue>
static const int MAX_SIZE=105;
struct Dinic{
  struct edge{
    int to,cap,rev;
    int id;
    bool isrev;
    edge(int st,int sc,int sr,int si,bool isr){
      to=st;cap=sc;rev=sr;
      id=si;
      isrev=isr;
    }
  };
  vector<edge> g[MAX_SIZE];
  int SS,TT;
  int rankk[MAX_SIZE],seen[MAX_SIZE];
  int src,sink;
  void add_edge(int from,int to,int cap,int id){
    g[from].pb(edge(to,cap,g[to].size(),id,false));
    g[to].pb(edge(from,0,g[from].size()-1,id,true));
  }
  void add_edge(int from,int to,int mncap,int cap,int id){//assume cap>=mncap
    add_edge(from,to,cap-mncap,id);
    add_edge(SS,to,mncap,-1);
    add_edge(from,TT,mncap,-1);
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
    add_edge(T_,S_,INF,-1);
    flow_();
    for(auto e:g[SS]) if(e.cap>0) return -1;

    src=S_;sink=T_;
    return flow_();
  }
  vector<bool> getcut(int S,int T,int n){//0: with S, 1: with T
    vector<bool> res(n);
    REP(i,n) res[i]=(rankk[i]==-1?1:0);
    return res;
  }
};

Dinic D1,D2;
int n,m,S,T;

pi ans[1005];

int gg[1005];

bool mark[1005];

int main(){
#ifdef LOCAL_REDIR
  freopen("/home/hog/Dropbox/pg/working/in.txt","r",stdin);
#endif
  cin>>n>>m>>S>>T;--S;--T;
  D2.SS=n,D2.TT=n+1;
  REP(i,m){
    int a,b,g;scanf("%d%d%d",&a,&b,&g);--a;--b;

    gg[i]=g;

    int c=(g==1?1:INF2);
    D1.add_edge(a,b,c,i);
    if(g){
      D1.add_edge(b,a,INF2,-1);
    }
  }
  int tmp=D1.flow(S,T);

  vector<bool> cut=D1.getcut(S,T,n);

  int cnt=0;
  REP(i,n) for(auto e:D1.g[i]){
      if(!e.isrev){
        if(cut[i]==0 && cut[e.to]==1){
          mark[e.id]=1;
          ++cnt;
          //  ans[e.id]={1,1};
          D2.add_edge(i,e.to,1,INF2,e.id);
        }else{
          if(gg[e.id]==1){
            D2.add_edge(i,e.to,1,INF2,e.id);
          }
        }
      }
    }

  assert(D2.flow2(S,T)!=-1);

  REP(i,n) for(auto e:D2.g[i]) if(!e.isrev && e.id>=0){
        if(mark[e.id]){
          ans[e.id]={INF2-e.cap,INF2-e.cap};
        }else{
          if(gg[e.id]==1){
            int a=INF2-e.cap;
            ans[e.id]={a,a+1};
          }
        }
    }


  REP(i,m){
    if(gg[i]==0){
      ans[i]={0,1};
    }else{
      assert(ans[i].fr>0);
    }
  }

  cout<<cnt<<endl;
  REP(i,m) assert(ans[i].sc>0);
  REP(i,m) printf("%d %d\n",ans[i].fr,ans[i].sc);


  return 0;
}