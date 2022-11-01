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

const lint INF=1e18;
const int INF2=5e8;

int n,m;
vector<pi> g[100005];

void ijk(vector<pi>* g,lint* cost,int n,const vector<int>& S){
  REP(i,n) cost[i]=INF;
  typedef pair<lint,int> pi;
  priority_queue<pi,vector<pi>, greater<pi> >pq;
  for(auto e:S){
    cost[e]=0;
    pq.push({0,e});
  }
  while(!pq.empty()){
    pi cur=pq.top();pq.pop();
    if(cur.fr>cost[cur.sc]) continue;
    for(auto e:g[cur.sc]){
      if(cost[e.fr]>cur.fr+e.sc){
        cost[e.fr]=cur.fr+e.sc;
        pq.push({cost[e.fr],e.fr});
      }
    }
  }
}
lint cost[100005];
int dist[100005];

pi idx[100005];

const int M=1000000;
vector<int> q[M+5];
void renew(){
  REP(i,n) dist[i]=INF2;
  dist[0]=0;
  q[0].pb(0);
  bool done[100005];
  CLR(done);

  for(int d=0;d<=M;++d){
    while(!q[d].empty()){
      int v=q[d].back();q[d].pop_back();
      if(!done[v]){
        done[v]=1;
        for(auto e:g[v]){
          lint co=dist[v]+e.sc-cost[e.fr]+cost[v];
          if(co<=M && dist[e.fr]>co){
            dist[e.fr]=co;
            q[co].pb(e.fr);
          }
        }
      }
    }
  }
}
int main(){
#ifdef LOCAL_REDIR
  freopen("/home/hog/Dropbox/pg/working/in.txt","r",stdin);
#endif
  int q;
  cin>>n>>m>>q;

  REP(i,m){
    int a,b,c;scanf("%d%d%d",&a,&b,&c);--a;--b;
    idx[i]={a,g[a].size()};
    g[a].pb({b,c});
  }
  ijk(g,cost,n,{0});

  bool change=false;
  REP(_,q){
    int t,c;scanf("%d%d",&t,&c);
    if(t==1){
      if(change){
        renew();
        change=false;
      }
      int v=c-1;
      lint res=dist[v]+cost[v];
      if(cost[v]==INF) res=-1;
      printf("%lld\n",res);
    }else{
      change=true;
      REP(__,c){
        int l;scanf("%d",&l);--l;
        ++g[idx[l].fr][idx[l].sc].sc;
      }
    }
  }
  return 0;
}