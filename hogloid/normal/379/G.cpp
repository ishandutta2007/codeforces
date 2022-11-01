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

struct uf{

  static const int MAXN=3000;
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



int n,m;
vector<pi> g[4005];

vector<pi> belong[4005];
vector<int> cycle[4005];

bool vis[4005];
vector<int> path;

int K;//n.o. cycles
void prep(int v,int p){
  vis[v]=1;
  path.pb(v);
  for(auto e:g[v]){
    if(e.sc==p) continue;
    int to=e.fr;
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

pi es[8005];
typedef vector<int> vi;
map<pi,vector<vi> >memo;

void update(vi& a,const vi& b,const vi& c){
  if(a.size()<b.size()+c.size()-1) a.resize(b.size()+c.size()-1);
  REP(i,b.size()) REP(j,c.size()){
    chmax(a[i+j],b[i]+c[j]);
  }
}

void update2(vi& a,const vi& b){
  int n=a.size(),m=b.size();
  a.resize(n+m-1);
  for(int i=n-1;i>=0;--i) for(int j=m-1;j>=0;--j){
    chmax(a[i+j],a[i]+b[j]);
  }
}
void merge(vi& a,const vi& b){
  int n=a.size(),m=b.size();
  if(n<m) a.resize(m);
  REP(i,m) chmax(a[i],b[i]);
}

vector<vi> dfs(int v,int p){//p:id of cycle
  if(memo.count({v,p})) return memo[{v,p}];
  auto& res=memo[{v,p}];
  res.resize(3,vi(1));
  for(auto e:belong[v]){
     int id=e.fr,pos=e.sc;
     if(id==p) continue;
     vi dp[2][3][3];//0:R 1:B 2:blank
     int cur=0,nxt=1;
     dp[0][0][0].resize(1);
     dp[0][1][1].resize(1);
     dp[0][2][2].resize(1);
     int clen=cycle[id].size();
     REPN(i,clen,1){
       int to=cycle[id][(pos+i)%clen];
       auto dp2=dfs(to,id);

       REP(l,3) REP(j,3) REP(k,3) if(j==2 || k==2 || j==k){
         update(dp[nxt][l][k],dp[cur][l][j],dp2[k]);
       }
       swap(cur,nxt);
       REP(j,3) REP(k,3) dp[nxt][j][k].clear();
     }
     REP(j,3) REP(k,3) if(j==2 || k==2 || j==k){
       if(j!=k) merge(dp[cur][j][j],dp[cur][j][k]);
     }
     REP(j,3){
       update2(res[j],dp[cur][j][j]);
     }
  }

  res[0].insert(res[0].begin(),-INF);
  for(auto& e:res[1]) ++e;
  return res;
}
uf u;
int main(){
  cin>>n>>m;
  REP(i,m){
    int a,b;scanf("%d%d",&a,&b);--a;--b;
    es[i]={a,b};
  }
  REP(i,m){
    u.init();
    REP(j,m) if(i!=j) u.unite(es[j].fr,es[j].sc);
    if(!u.same(es[i].fr,es[i].sc)){
      es[m++]=es[i];
    }
  }
  REP(i,m){
    int a=es[i].fr,b=es[i].sc;
    g[a].pb({b,i});
    g[b].pb({a,i});
  }
  prep(0,-1);
  REP(i,K) REP(j,cycle[i].size()) belong[cycle[i][j]].pb({i,j});


  auto res=dfs(0,-1);

  int ans[3000];
  REP(i,n+1) ans[i]=-1;
  REP(t,3) REP(j,res[t].size()) chmax(ans[j],res[t][j]);
  REP(i,n+1) printf("%d\n",ans[i]);
  return 0;
}