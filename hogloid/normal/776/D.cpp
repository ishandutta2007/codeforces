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

//const int INF=5e8;

struct SCC{
  static const int MAX_N=200005;
  vector<int> g[MAX_N],rg[MAX_N];
  int vis[MAX_N],order[MAX_N],cnt;
  int group[MAX_N],gcnt;
  void adde(int a,int b){
    g[a].pb(b);
    rg[b].pb(a);
  }
  void dfs(int v){
    vis[v]=1;
    REP(i,g[v].size()) if(!vis[g[v][i]]){
      dfs(g[v][i]);
    }
    order[cnt++]=v;
  }
  void rdfs(int v){
    vis[v]=1;
    group[v]=gcnt;
    REP(i,rg[v].size()) if(!vis[rg[v][i]]){
      rdfs(rg[v][i]);
    }
  }

  void scc(int n){
    memset(vis,0,sizeof(vis));
    cnt=gcnt=0;
    REP(i,n) if(!vis[i]){
      dfs(i);
    }
    memset(vis,0,sizeof(vis));
    for(int i=n-1;i>=0;--i) if(!vis[order[i]]){
      rdfs(order[i]);
      ++gcnt;
    }
  }
  bool ok(int n2){
    REP(i,n2) if(group[i]==group[i+n2]) return false;
    return true;
  }
};
SCC G;
int n,m;
int ar[100005];

vector<int> bel[100005];
int main(){
  cin>>n>>m;
  REP(i,n) scanf("%d",&ar[i]);
  REP(i,m){
    int K;scanf("%d",&K);
    REP(j,K){
      int a;scanf("%d",&a);--a;
      bel[a].pb(i);
    }
  }
  REP(i,n){
    int x=bel[i][0],y=bel[i][1];
    if(ar[i]==0){
      G.adde(x,y+m);
      G.adde(y+m,x);
      G.adde(x+m,y);
      G.adde(y,x+m);
    }else{
      G.adde(x,y);
      G.adde(y,x);
      G.adde(x+m,y+m);
      G.adde(y+m,x+m);
    }
  }
  G.scc(m*2);
  puts(G.ok(m)?"YES":"NO");
  return 0;
}