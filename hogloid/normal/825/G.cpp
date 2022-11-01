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
vector<int> g[1000005];
pi que[1000005];
int n,q;

int mn[1000005];
void dfs(int v,int p){
  chmin(mn[v],v);
  for(auto to:g[v]) if(to!=p){
      mn[to]=mn[v];
      dfs(to,v);
    }
}
int main(){
#ifdef LOCAL_REDIR
  freopen("/home/hog/Dropbox/pg/working/in.txt","r",stdin);
#endif
  cin>>n>>q;
  REP(i,n-1){
    int a,b;scanf("%d%d",&a,&b);--a;--b;
    g[a].pb(b);
    g[b].pb(a);
  }
  REP(i,q){
    int a,x;scanf("%d%d",&a,&x);--x;
    que[i]={a,x};
  }
  int R=(que[0].sc+1)%n;
  mn[R]=R;
  dfs(R,-1);

  int all=R;
  int last=0;
  REP(i,q){
    int a=que[i].fr,v=que[i].sc;
    v=(v+1+last)%n;
    if(a==1){
      chmin(all,mn[v]);
    }else{
      last=min(all,mn[v])+1;
      printf("%d\n",last);
    }
  }

  return 0;
}