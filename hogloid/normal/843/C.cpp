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
int n;
vector<int> g[200005];

vector<pair<int,pi> >ans;
static const int MAX_N=200005;
int cut[MAX_N],size[MAX_N],whole;
int root,rcost;
int getsize(int v,int p){
  size[v]=1;
  REP(i,g[v].size()){
    int to=g[v][i];
    if(to!=p && cut[to]==0) size[v]+=getsize(to,v);
  }
  return size[v];
}

int wei[200005];
void getbestroot(int v,int p){
  int maxi=0;
  REP(i,g[v].size()){
    int to=g[v][i];
    if(to!=p && cut[to]==0){
      getbestroot(to,v);
      maxi=max(maxi,size[to]);
    }
  }
  int rest=whole-size[v];
  maxi=max(maxi,rest);
  wei[v]=maxi;
  if(maxi<rcost){
    rcost=maxi;
    root=v;
  }
}


int root2;
int curlink;
void dfs3(int v,int p){
  if(v!=root2 && p!=root2){
    ans.pb({root,{curlink,v}});
    ans.pb({v,{p,root2}});
    curlink=v;
  }
  for(auto to:g[v]){
    if(p!=to){
      dfs3(to,v);
    }
  }
}

void solve(int v,int p){
  REP(i,g[v].size()){
    int to=g[v][i];
    if(cut[to]==0 && to!=p){
      root2=to;
      curlink=root2;
      dfs3(to,v);
      if(curlink!=root2){
        ans.pb({v,{curlink,root2}});
      }
    }
  }
}
int dfs(int v){
  getsize(v,-1);
  if(size[v]==1) return v;
  whole=size[v];
  rcost=INF;
  getbestroot(v,-1);

  if(rcost*2==whole && whole==n){
    vector<int> rs;
    REP(i,n) if(rcost==wei[i]){
        rs.pb(i);
      }
    assert(rs.size()==2);
    root=rs[0];
    solve(rs[0],rs[1]);
    root=rs[1];
    solve(rs[1],rs[0]);
    return -1;
  }else {
    v = root;
    solve(v,-1);
  }
  cut[v]=0;
  return v;
}

int main(){
#ifdef LOCAL_REDIR
  freopen("/home/hog/Dropbox/pg/working/in.txt","r",stdin);
#endif
  cin>>n;
  REP(i,n-1){
    int a,b;scanf("%d%d",&a,&b);--a;--b;
    g[a].pb(b);
    g[b].pb(a);
  }

  dfs(0);

  cout<<ans.size()<<endl;
  for(auto e:ans){
    printf("%d %d %d\n",e.fr+1,e.sc.fr+1,e.sc.sc+1);
  }
  return 0;
}