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

const int INF=5e8;
struct rat{
  lint a,b;//means a/b; b>0
  rat(lint x): a(x),b(1) {}
  rat(lint x,lint y){
    lint g=__gcd(x,y);
    x/=g;
    y/=g;
    if(y<0){
      y*=-1;
      x*=-1;
    }
    a=x;b=y;
  }
  rat(){}
  rat &operator +=(rat that){
    lint g=__gcd(that.b,b);
    a=(that.b/g*a+b/g*that.a);
    b=that.b/g*b;
    g=__gcd(a,b);
    a/=g;b/=g;
    return (*this);
  }
  rat &operator -=(rat that){
    that.a*=-1;
    (*this)+=that;
    return *this;
  }
  rat &operator *=(rat that){
    lint g1=abs(__gcd(a,that.b)),g2=abs(__gcd(b,that.a));
    a=a/g1*(that.a/g2);
    b=b/g2*(that.b/g1);
    return *this;
  }
  rat &operator /=(rat that){
    rat that2(that.b,that.a);
    (*this)*=that2;
    return *this;
  }
  bool operator ==(rat that) const {
    return a==that.a && b==that.b;
  }
  bool operator !=(rat that) const {
    return a!=that.a || b!=that.b;
  }
  bool operator <(rat that) const {
    return a*(that.b)<b*(that.a);
  }
  bool operator >(rat that) const{
    return (that)<(*this);
  }
  bool operator <=(rat that) const{
    return (*this)==that || (*this)<that;
  }
  bool operator >=(rat that) const{
    return (that)<=(*this);
  }
  rat operator -() const {
    return rat(-a,b);
  }
  rat operator +(rat that) const {
    return rat(*this)+=that;
  }
  rat operator -(rat that) const {
    return rat(*this)-=that;
  }
  rat operator *(rat that) const{
    return rat(*this)*=that;
  }
  rat operator /(rat that) const{
    return rat(*this)/=that;
  }
  double todbl() const{
    return a/(double)b;
  }
};
namespace std{
  ostream &operator <<(ostream& out,const rat& a){
    out<<a.todbl();
    return out;
  }
};
namespace hld{
  const int MAXN=100005;
  int belong[MAXN];
  int dep[MAXN];
  int root[MAXN];
  vector<int> path[MAXN];
  int pcnt;
  vector<int>* g;

  int vis[MAXN],leave[MAXN],ord;
  int par[MAXN];

  int size[MAXN];
  int prep(int v,int p,int d){
    par[v]=p;
    vis[v]=ord;++ord;
    dep[v]=d;
    size[v]=1;
    for(auto to:g[v]) if(to!=p){
      size[v]+=prep(to,v,d+1);
    }
    leave[v]=ord;++ord;
    return size[v];
  }
  vector<int> curpath;
  void dfs(int v,int p){
    curpath.pb(v);
    int nxt=-1;
    for(auto to:g[v]) if(to!=p){
      if(nxt==-1 || size[nxt]<size[to]) nxt=to;
    }
    if(nxt==-1){
      for(auto u:curpath) belong[u]=pcnt,root[u]=curpath[0];
      path[pcnt].swap(curpath);
      assert(curpath.empty());
      ++pcnt;
    }else{
      dfs(nxt,v);
    }
    for(auto to:g[v]) if(to!=p && to!=nxt){
      dfs(to,v);
    }
  }
  void init(vector<int>* g_,int n,int R){
    g=g_;
    pcnt=0;
    REP(i,n) path[i].clear();
    curpath.clear();
    CLR(size);
    prep(R,-1,0);

    dfs(R,-1);
  }
  bool upper(int u,int v){//R -- u -- v ?
    return vis[u]<=vis[v] && leave[v]<=leave[u];
  }
  pi climb[30],des[30];

  struct line{
    int sx,tx;
    rat stime;
    int c;
    rat calc(rat x){
      return (x-stime)*c+sx;
    }
    rat fin(){
      return rat(abs(sx-tx),abs(c))+stime;
    }
  };
    
  int getpath(int u,int v,pi* ar){
    int c1=0,c2=0;
    while(!upper(root[u],v)){
      climb[c1++]=mp(u,par[root[u]]);
      u=par[root[u]];
    }
    while(!upper(root[v],u)){
      des[c2++]=mp(par[root[v]],v);
      v=par[root[v]];
    }
    assert(belong[u]==belong[v]);

    if(dep[u]<dep[v]){
      climb[c1++]=mp(u,v);
    }else{
      des[c2++]=mp(u,v);
    }
    int cnt=0;
    REP(i,c1) ar[cnt++]=climb[i];
    for(int i=c2-1;i>=0;--i) ar[cnt++]=des[i];
    return cnt;
  }
  int getLCA(int u,int v){
    while(!upper(root[u],v)){
      u=par[root[u]];
    }
    while(!upper(root[v],u)){
      v=par[root[v]];
    }
    assert(belong[u]==belong[v]);

    if(dep[u]<dep[v]) return u;
    else return v;
  }
  int getd(int a,int b){
    return dep[a]+dep[b]-2*dep[getLCA(a,b)];
  }
  vector<line> query[MAXN];
  void push_query(int u,int v,int t,int c){
    pi segs[50];
    int cnt=getpath(u,v,segs);
    REP(i,cnt){
      int a=segs[i].fr,b=segs[i].sc;
      int R=root[(dep[a]>dep[b]?a:b)];
      int id=belong[(dep[a]>dep[b]?a:b)];
      int l=dep[a]-dep[R]+1,r=dep[b]-dep[R]+1;

      int d=getd(u,a);
      int c2=(l<=r?c:-c);
      rat stime=rat(d,c)+t;
      query[id].pb((line){l,r,stime,c2});
    }
  }
  rat T(0);
  int id2;
  struct cmp{
    bool operator ()(int a,int b) const{
      return query[id2][a].calc(T)<query[id2][b].calc(T);
    }
  };
  pair<rat,int> event[200005];
  rat calc(int i,int j){
    line a=query[id2][i],b=query[id2][j];
    if(a.stime>b.stime) swap(a,b);
    rat sx2=(b.stime-a.stime)*a.c+a.sx;
    if(sx2==b.sx) return b.stime;
    if(b.c==a.c) return INF;
    rat res=(-sx2+b.sx)/(a.c-b.c)+b.stime;
    if(res<=min(b.fin(),a.fin()) && res>=b.stime) return res;
    return INF;
  }
  rat solve(int id){
    id2=id;
    int m=0;
    int n=query[id].size();
    REP(i,query[id].size()){
      line q=query[id][i];
      
      event[m++]=mp(q.stime,i);
      event[m++]=mp(q.fin(),i+n);
    }
    sort(event,event+m);

    set<int,cmp> S;

    rat ans(INF);
    REP(i,m){
      pair<rat,int> e=event[i];
      int x=e.sc%n;
      T=e.fr;
      if(T>=ans) break;

      if(e.sc>=n){//remove
        S.erase(x);
        auto it=S.lower_bound(x);
        if(it!=S.end() && it!=S.begin()){
          auto it2=it;--it2;
          chmin(ans,calc(*it,*it2));
        }
      }else{
        auto it=S.lower_bound(x);
        if(it!=S.end()){
          chmin(ans,calc(*it,x));
        }
        if(it!=S.begin()){
          --it;
          chmin(ans,calc(*it,x));
        }
        S.insert(x);
      }
    }
    return ans;
  }
  rat solve(){
    rat ans(INF);
    REP(i,pcnt) chmin(ans,solve(i));
    return ans;
  }
}


vector<int> g[100005];
int n,m;
int main(){
  cin>>n>>m;
  REP(i,n-1){
    int a,b;scanf("%d%d",&a,&b);--a;--b;
    g[a].pb(b);
    g[b].pb(a);
  }
  hld::init(g,n,0);
  REP(i,m){
    int t,c,a,b;scanf("%d%d%d%d",&t,&c,&a,&b);--a;--b;
    hld::push_query(a,b,t,c);
  }
  rat res=hld::solve();
  if(res==INF) puts("-1");
  else printf("%.10f\n",res.todbl());
  return 0;
}