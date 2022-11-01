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

vector<int> es[200005];
vector<pi> g[200005];

bool ans[200005];
bool used[200005],mark[200005];
int sign(int a){
  if(a>0) return 1;
  if(a<0) return -1;
  dump("HOGE");
  return 0;
}
void dfs(int v){
  mark[v]=1;
  while(!g[v].empty()){
    pi e=g[v].back();
    g[v].pop_back();
    dump(v);
    dump(g[v].size());
    dump(e);
    if(used[abs(e.sc)-1]){
      continue;
    }
    used[abs(e.sc)-1]=1;
    dump(e);
    ans[abs(e.sc)-1]=(sign(e.sc)>0?1:0);
    dfs(e.fr);
  }
}

bool vis2[200005];
int findcy(int v,int pid){
  if(vis2[v]) return v;
  vis2[v]=1;
  for(auto e:g[v]){
    if(abs(e.sc)==pid) continue;
    int r=findcy(e.fr,abs(e.sc));
    if(r>=0){
      return r;
    }
  }
  return -1;
}
void fail(){
  puts("NO");
  exit(0);
}

int main(){
  cin>>n>>m;
  REP(i,n){
    int c;scanf("%d",&c);
    REP(j,c){
      int a;scanf("%d",&a);
      int id=abs(a)-1;
      es[id].pb((i+1)*sign(a));
    }
  }
  REP(i,m){
    if(es[i].empty()) continue;
    if(es[i].size()==2 && sign(es[i][0])!=sign(es[i][1])){
      int a=abs(es[i][0])-1,b=abs(es[i][1])-1;
      g[a].pb(mp(b,(i+1)*sign(es[i][1])));
      g[b].pb(mp(a,(i+1)*sign(es[i][0])));
    }
  }
  REP(i,m){
    if(es[i].empty()) continue;
    if(es[i].size()==2 && sign(es[i][0])==sign(es[i][1])){
      int a=abs(es[i][0])-1,b=abs(es[i][1])-1;
      ans[i]=(sign(es[i][0])==1?1:0);
      mark[a]=mark[b]=1;
    }else if(es[i].size()==1){
      int a=abs(es[i][0])-1;
      ans[i]=(sign(es[i][0])==1?1:0);
      mark[a]=1;
    }
  }
  debug(ans,ans+m);
  REP(i,n) if(mark[i]){
    dfs(i);
  }
  debug(ans,ans+m);

  REP(i,n) if(!mark[i]){
    int v=findcy(i,-1);
    if(v==-1){
      fail();
    }
    dfs(v);
  }
  puts("YES");
  string res;
  debug(ans,ans+m);
  REP(i,m) res+=(ans[i]?"1":"0");
  cout<<res<<endl;
  return 0;
}