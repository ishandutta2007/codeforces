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
#include<queue>
int src,sink;
static const int MAX_SIZE=100005;
int n,m;
lint r,b;
pi ps[100005];
map<pi,int> cnt;
map<int,int> Xcnt,Ycnt,X_ndup,Y_ndup;
map<int,int> Xcon,Ycon;
map<int,int> Xidx,Yidx;
void ng(){
  puts("-1");
  exit(0);
}

int xpos[100005],ypos[100005];
const int INF=5e8;
struct Dinic{
  struct edge{
    int to,cap,rev;
    edge(int st,int sc,int sr){
      to=st;cap=sc;rev=sr;
    }
  };
  vector<edge> g[MAX_SIZE];
  int SS,TT;
  int rankk[MAX_SIZE],seen[MAX_SIZE];
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
  char ans[100005];
  void solve(int S,int T){
    int n1=Xcon.size(),n2=Ycon.size();
    bool flip=false;
    if(r>b) swap(r,b),flip=true;
    int fl=flow2(S,T);
    if(fl==-1) ng();

    lint res2=b*n-(b-r)*fl;

    REP(i,n) ans[i]='b';

    map<pi,int> turn;
    map<int,int> Xn,Yn;
    REP(i,n1){
      for(auto e:g[i]){
        int cdif=g[e.to][e.rev].cap;
        if(e.to>=n1 && e.to<n1+n2){
          turn[mp(xpos[i],ypos[e.to])]+=cdif;
        }else if(e.to==T){
          Xn[xpos[i]]+=cdif;
        }
      }
    }
    for(auto e:g[S]){
      if(e.to>=n1 && e.to<n1+n2){
        Yn[ypos[e.to]]+=g[e.to][e.rev].cap;
      }
    }
    REP(i,n){
      if(!Xcon.count(ps[i].fr) && !Ycon.count(ps[i].sc)){
        ans[i]='r';
      }else if(turn[ps[i]]>0){
        --turn[ps[i]];
        ans[i]='r';
      }else if(Xcon.count(ps[i].fr) && !Ycon.count(ps[i].sc) && Xn[ps[i].fr]>0){
        --Xn[ps[i].fr];
        ans[i]='r';
      }else if(Ycon.count(ps[i].sc) && !Xcon.count(ps[i].fr) && Yn[ps[i].sc]>0){
        --Yn[ps[i].sc];
        ans[i]='r';
      }
    }
    if(flip){
      REP(i,n) ans[i]=(ans[i]=='r'?'b':'r');
      swap(r,b);
    }

    lint res=0;
    REP(i,n){
      if(ans[i]=='r') res+=r;
      else res+=b;
    }
    cout<<res<<endl;
    ans[n]='\0';
    printf("%s\n",ans);
  }
};

Dinic D;
//const int INF=5e8;

int main(){
  cin>>n>>m>>r>>b;
  REP(i,n){
    scanf("%d%d",&ps[i].fr,&ps[i].sc);
    cnt[ps[i]]++;
    Xcnt[ps[i].fr]++;
    Ycnt[ps[i].sc]++;
  }
  REP(i,m){
    int t,l,d;
    scanf("%d%d%d",&t,&l,&d);
    if(t==1){
      if(Xcon.count(l)==0) Xcon[l]=d;
      else chmin(Xcon[l],d);
    }else{
      if(Ycon.count(l)==0) Ycon[l]=d;
      else chmin(Ycon[l],d);
    }
  }
  REP(i,n){
    if(Xcon.count(ps[i].fr) && !Ycon.count(ps[i].sc)) X_ndup[ps[i].fr]++;
    if(Ycon.count(ps[i].sc) && !Xcon.count(ps[i].fr)) Y_ndup[ps[i].sc]++;
  }

  int i=0;
  for(auto e:Xcon){
    Xidx[e.fr]=i;
    xpos[i]=e.fr;
    ++i;
  }
  for(auto e:Ycon){
    Yidx[e.fr]=i;
    ypos[i]=e.fr;
    ++i;
  }

  int S=i,T=i+1,&SS=D.SS,&TT=D.TT;
  SS=i+2;
  TT=i+3;

  for(auto e:Xcon){
    int x=e.fr,d=e.sc;
    int id=Xidx[x];
    int tot=Xcnt[x];
    int least=max(0,(tot-d+1)/2),maxi=tot-least;
    if(least>maxi) ng();
    int free=X_ndup[x];
    D.add_edge(S,id,least,maxi);
    D.add_edge(id,T,free);
  }
  for(auto e:Ycon){
    int y=e.fr,d=e.sc;
    int id=Yidx[y];
    int tot=Ycnt[y];
    int least=max(0,(tot-d+1)/2),maxi=tot-least;
    if(least>maxi) ng();
    int free=Y_ndup[y];
    D.add_edge(id,T,least,maxi);
    D.add_edge(S,id,free);
  }
  for(auto e:cnt){
    if(Xcon.count(e.fr.fr) && Ycon.count(e.fr.sc)){
      int a=Xidx[e.fr.fr],b=Yidx[e.fr.sc];
      D.add_edge(a,b,e.sc);
    }
  }
  D.solve(S,T);
  return 0;
}