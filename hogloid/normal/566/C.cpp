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

const int INF=5e8;
int n;
int w[200005];
static const int MAX_N=200005;
vector<pair<int,int> > g[MAX_N];
int cut[MAX_N],size[MAX_N],whole;
int root,rcost;
int getsize(int v,int p){
  size[v]=1;
  REP(i,g[v].size()){
    int to=g[v][i].fr;
    if(to!=p && cut[to]==0) size[v]+=getsize(to,v);
  }
  return size[v];
}
void getbestroot(int v,int p){
  int maxi=0;
  REP(i,g[v].size()){
    int to=g[v][i].fr;
    if(to!=p && cut[to]==0){
      getbestroot(to,v);
      maxi=max(maxi,size[to]);
    }
  }
  int rest=whole-size[v];
  maxi=max(maxi,rest);
  if(maxi<rcost){
    rcost=maxi;
    root=v;
  }
}
vector<int> cand;
int cnt;
int ways[MAX_N];

double dfs2(int v,int p,int d){
  double res=w[v]*sqrt((double)d);
  for(auto e:g[v]){
    if(e.fr==p) continue;
    res+=dfs2(e.fr,v,d+e.sc);
  }
  return res;
}

void dfs(int v){
  getsize(v,-1);
  if(size[v]==1){
    cand.pb(v);
    return;
  }
  whole=size[v];
  rcost=INF;
  getbestroot(v,-1);
  v=root;

  cand.pb(root);

  cut[v]=1;
  double mx=-1;
  int nxt=-1;
  REP(i,g[v].size()){
    pi& e=g[v][i];
    if(cut[e.fr]==0){
      double a=dfs2(e.fr,v,e.sc);
      if(mx<a){
        mx=a;
        nxt=e.fr;
      }
    }
  }
  if(~nxt) dfs(nxt);
  cut[v]=0;
}

double calc(int v,int p,int d){
  double res=w[v]*sqrt((double)d)*d;
  for(auto e:g[v]){
    if(e.fr==p) continue;
    res+=calc(e.fr,v,d+e.sc);
  }
  return res;
}


int main(){
  cin>>n;
  REP(i,n) scanf("%d",&w[i]);
  REP(i,n-1){
    int a,b,l;
    scanf("%d%d%d",&a,&b,&l);--a;--b;
    g[a].pb(mp(b,l));
    g[b].pb(mp(a,l));
  }
  dfs(0);

  double res=1e100;
  int R;
  for(auto v:cand){
    double t=calc(v,-1,0);
    if(res>t){
      res=t;
      R=v;
    }
  }
  printf("%d %.10f\n",R+1,res);
  return 0;
}