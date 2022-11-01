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
int n,K;

struct mypq{
  priority_queue<int,vector<int>,greater<int> > pq,rm;
  void push(int v){
    pq.push(v);
  }
  void pop(){
    while(!rm.empty() && rm.top()==pq.top()){
      rm.pop();pq.pop();
    }
    pq.pop();
  }
  int top(){
    while(!rm.empty() && rm.top()==pq.top()){
      rm.pop();pq.pop();
    }
    return pq.top();
  }
  void remove(int v){
    rm.push(v);
  }
  void clear(){
    while(!rm.empty()) rm.pop();
    while(!pq.empty()) pq.pop();
  }
};

struct UF {
  vector<int> d,size; // *-1
  vector<pair<int,int>> history;

  int comp,comp_prev;
  UF(){}
  void init(int n){
    d.clear();
    comp=0;
    size.clear();
    history.clear();
    d.resize(n,-1);
    size.resize(n,1);
  }
  int root(int x){
    if(d[x] < 0) return x;
    return root(d[x]);
  }
  void unite(int x, int y){
    dump(x);dump(y);dump(comp);
    x = root(x); y = root(y);
    if(x == y) return;
    if(d[x] > d[y]) swap(x,y);
    if(d[x] == d[y]) {
      history.pb(make_pair(x,d[x]));
      d[x]--;
    }
    history.pb(make_pair(y,d[y]));

    size[y]+=size[x];
    --comp;
    d[y] = x;
  }
  void snapshot() {
    comp_prev=comp;
    history.clear();
  }
  int query(){
    return comp;
  }
  void enable(int v){
    ++comp;
  }
  void rollback() {
    while (history.size()) {
      d[history.back().first] = history.back().second;
      history.pop_back();
    }
    comp=comp_prev;
  }
};

const int B=500;
struct uf{
  static const int MAXN=B;
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



UF U;
int m;
vector<int> g[100005],rg[100005];

int ans[100005];

vector<pair<pi,int> >query[100000/B+10];
int main(){
  cin>>n>>K;
  cin>>m;
  REP(i,m){
    int a,b;scanf("%d%d",&a,&b);--a;--b;
    if(a>b) swap(a,b);
    g[a].pb(b);
    rg[b].pb(a);
  }
  int q;cin>>q;
  REP(i,q){
    int l,r;scanf("%d%d",&l,&r);--l;

    //[l...r)
    int len=r-l;
    if(len<=B){
      uf u;
      u.init();
      dump(i);
      REPN(j,r,l) for(auto to:g[j]) if(to<r){
        dump(to);dump(j);
        u.unite(to-l,j-l);
      }
      int res=0;
      REP(j,len) if(u.root(j)==j) ++res;
      ans[i]=res;
    }else{
      query[l/B].pb({{l,r},i});
    }
  }

  int MX=100000/B+10;

  REP(buck,MX){
    U.init(n);
    sort(ALL(query[buck]));
    vector<pair<pi,int> >& que=query[buck];
    debug(ALL(que));
    sort(ALL(que),[&](pair<pi,int> a,pair<pi,int> b){
      return a.fr.sc<b.fr.sc;
    });
    int lb=(buck+1)*B;
    int cur=lb;
    REP(i,que.size()){
      dump(i);
      dump(lb);
      while(cur<que[i].fr.sc){
        dump(cur);
        U.enable(cur);
        for(auto e:rg[cur]) if(e>=lb){
          U.unite(cur,e);
        }
        ++cur;
      }
      U.snapshot();
      int l=que[i].fr.fr;
      for(int j=lb-1;j>=l;--j){
        dump(j);
        U.enable(j);
        for(auto to:g[j]) if(to<que[i].fr.sc){
          U.unite(j,to);
        }
      }
      ans[que[i].sc]=U.query();
      U.rollback();
    }
  }
  REP(i,q) printf("%d\n",ans[i]);
  return 0;
}