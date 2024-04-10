#pragma GCC target("avx")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>
// #include<ext/pb_ds/tag_and_trait.hpp>
// using namespace __gnu_pbds;
// #include<boost/multiprecision/cpp_int.hpp>
// namespace multiprecisioninteger = boost::multiprecision;
// using cint=multiprecisioninteger::cpp_int;
using namespace std;
using ll=long long;
using datas=pair<ll,ll>;
using ddatas=pair<long double,long double>;
using tdata=pair<ll,datas>;
using vec=vector<ll>;
using mat=vector<vec>;
using pvec=vector<datas>;
using pmat=vector<pvec>;
// using llset=tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>;
#define For(i,a,b) for(i=a;i<(ll)b;++i)
#define bFor(i,b,a) for(i=b,--i;i>=(ll)a;--i)
#define rep(i,N) For(i,0,N)
#define rep1(i,N) For(i,1,N)
#define brep(i,N) bFor(i,N,0)
#define brep1(i,N) bFor(i,N,1)
#define all(v) (v).begin(),(v).end()
#define allr(v) (v).rbegin(),(v).rend()
#define vsort(v) sort(all(v))
#define vrsort(v) sort(allr(v))
#define uniq(v) vsort(v);(v).erase(unique(all(v)),(v).end())
#define endl "\n"
#define popcount __builtin_popcountll
#define eb emplace_back
#define print(x) cout<<x<<endl
#define printyes print("Yes")
#define printno print("No")
#define printYES print("YES")
#define printNO print("NO")
#define output(v) do{bool f=0;for(auto outi:v){cout<<(f?" ":"")<<outi;f=1;}cout<<endl;}while(0)
#define matoutput(v) do{for(auto outimat:v)output(outimat);}while(0)
constexpr ll mod=1000000007;
// constexpr ll mod=998244353;
constexpr ll inf=1LL<<60;
constexpr long double eps=1e-9;
const long double PI=acosl(-1);
template<class T,class E> ostream& operator<<(ostream& os,const pair<T,E>& p){return os<<"("<<p.first<<","<<p.second<<")";}
template<class T> ostream& operator<<(ostream& os,const vector<T>& v){
  os<<"{";bool f=false;
  for(auto& x:v){if(f)os<<",";os<<x;f=true;}
  os<<"}";
  return os;
}
template<class T> ostream& operator<<(ostream& os,const set<T>& v){
  os<<"{";bool f=false;
  for(auto& x:v){if(f)os<<",";os<<x;f=true;}
  os<<"}";
  return os;
}
template<class T> ostream& operator<<(ostream& os,const multiset<T>& v){
  os<<"{";bool f=false;
  for(auto& x:v){if(f)os<<",";os<<x;f=true;}
  os<<"}";
  return os;
}
template<class T,class E> ostream& operator<<(ostream& os,const map<T,E>& v){
  os<<"{";bool f=false;
  for(auto& x:v){if(f)os<<",";os<<x;f=true;}
  os<<"}";
  return os;
}
template<class T> inline bool chmax(T& a,const T b){bool x=a<b;if(x)a=b;return x;}
template<class T> inline bool chmin(T& a,const T b){bool x=a>b;if(x)a=b;return x;}
#ifdef DEBUG
void debugg(){cout<<endl;}
template<class T,class... Args>void debugg(const T& x,const Args&... args){cout<<" "<<x;debugg(args...);}
#define debug(...) cout<<__LINE__<<" ["<<#__VA_ARGS__<<"]:",debugg(__VA_ARGS__)
#else
#define debug(...) (void(0))
#endif

inline void startupcpp(void) noexcept{
  cin.tie(0);
  ios::sync_with_stdio(false);
}

template<class S,S(*op)(S,S),S(*e)(),
        class F,S(*mapping)(S,F),F(*composition)(F,F),F(*id)()>
struct lazy_segtree{
public:
  lazy_segtree():lazy_segtree(0){}
  lazy_segtree(int n):lazy_segtree(vector<S>(n,e())){}
  lazy_segtree(const vector<S>& v):_n(int(v.size())){
    log=0;
    while((1U<<log)<(unsigned int)(_n))++log;
    size=1<<log;
    d=vector<S>(size<<1,e());
    lz=vector<F>(size,id());
    for(int i=0;i<_n;++i)d[size+i]=v[i];
    for(int i=size-1;i>=1;--i){
      update(i);
    }
  }

  void set(int p,S x){
    assert(0<=p&&p<_n);
    p+=size;
    for(int i=log;i>=1;--i)push(p>>i);
    d[p]=x;
    for(int i=1;i<=log;++i)update(p>>i);
  }

  S get(int p){
    assert(0<=p&&p<_n);
    p+=size;
    for(int i=log;i>=1;--i)push(p>>i);
    return d[p];
  }

  S prod(int l,int r){
    assert(0<=l&&l<=r&&r<=_n);
    if(l==r)return e();

    l+=size;
    r+=size;

    for(int i=log;i>=1;--i){
      if(((l>>i)<<i)!=l)push(l>>i);
      if(((r>>i)<<i)!=r)push(r>>i);
    }

    S sml=e(),smr=e();
    while(l<r){
      if(l&1)sml=op(sml,d[l++]);
      if(r&1)smr=op(d[--r],smr);
      l>>=1;
      r>>=1;
    }

    return op(sml,smr);
  }

  S all_prod(){return d[1];}

  void apply(int p,F f){
    assert(0<=p&&p<_n);
    p+=size;
    for(int i=log;i>=1;--i)push(p>>i);
    d[p]=mapping(d[p],f);
    for(int i=1;i<=log;++i)update(p>>i);
  }
  void apply(int l,int r,F f){
    assert(0<=l&&l<=r&&r<=_n);
    if(l==r)return;

    l+=size;
    r+=size;

    for(int i=log;i>=1;--i){
      if(((l>>i)<<i)!=l)push(l>>i);
      if(((r>>i)<<i)!=r)push((r-1)>>i);
    }

    {
      int l2=l,r2=r;
      while(l<r){
        if(l&1)all_apply(l++,f);
        if(r&1)all_apply(--r,f);
        l>>=1;
        r>>=1;
      }
      l=l2;
      r=r2;
    }

    for(int i=1;i<=log;++i){
      if(((l>>i)<<i)!=l)update(l>>i);
      if(((r>>i)<<i)!=r)update((r-1)>>i);
    }
  }

  template<bool(*g)(S)>int max_right(int l){
    return max_right(l,[](S x){return g(x);});
  }
  template<class G>int max_right(int l,G g){
    assert(0<=l&&l<=_n);
    assert(g(e()));
    if(l==_n)return _n;
    l+=size;
    for(int i=log;i>=1;--i)push(l>>i);
    S sm=e();
    do{
      while(~l&1)l>>=1;
      if(!g(op(sm,d[l]))){
        while(l<size){
          push(l);
          l<<=1;
          if(g(op(sm,d[l]))){
            sm=op(sm,d[l++]);
          }
        }
        return l-size;
      }
      sm=op(sm,d[l++]);
    }while((l&-l)!=l);
    return _n;
  }

  template<bool(*g)(S)>int min_left(int r){
    return min_left(r,[](S x){return g(x);});
  }
  template<class G>int min_left(int r,G g){
    assert(0<=r&&r<=_n);
    assert(g(e()));
    if(r==0)return 0;
    r+=size;
    for(int i=log;i>=1;--i)push((r-1)>>i);
    S sm=e();
    do{
      --r;
      while(r>>1&&(r&1))r>>=1;
      if(!g(op(d[r],sm))){
        while(r<size){
          push(r);
          r=r<<1|1;
          if(g(op(d[r],sm))){
            sm=op(d[r--],sm);
          }
        }
        return r+1-size;
      }
      sm=op(d[r],sm);
    }while((r&-r)!=r);
    return 0;
  }
  int _n;
private:
  int size,log;
  vector<S> d;
  vector<F> lz;

  void update(int k){d[k]=op(d[k<<1],d[k<<1|1]);}
  void all_apply(int k,F f){
    d[k]=mapping(d[k],f);
    if(k<size)lz[k]=composition(lz[k],f);
  }
  void push(int k){
    all_apply(k<<1,lz[k]);
    all_apply(k<<1|1,lz[k]);
    lz[k]=id();
  }
  friend ostream &operator<<(ostream &os,const lazy_segtree<S,op,e,F,mapping,composition,id> &p){
    lazy_segtree<S,op,e,F,mapping,composition,id> printout(p);
    for(int i=0;i<printout._n;++i){os<<"{,"[i>0]<<printout.prod(i,i+1);}
    os<<"}";
    return os;
  }
};

namespace segtreefunction{
  bool op(bool a,bool b){return a|b;}
  bool e(){return false;}
}
using segtree=lazy_segtree<bool,segtreefunction::op,segtreefunction::e,bool,segtreefunction::op,segtreefunction::op,segtreefunction::e>;
struct unionfind{
  private:
  int maxN;
  vector<int> par,treesize;
  public:unionfind(int N) :maxN(N),par(N),treesize(N,1){
    for(int i=0;i<maxN;++i)par[i]=i;
  }
  int root(int x){
    while(par[x]!=x){
      x=par[x]=par[par[x]];
    }
    return x;
  }
  bool unite(int x,int y){
    x=root(x);
    y=root(y);
    if(x==y)return false;
    if(treesize[x]>treesize[y])swap(x,y);
    par[x]=y;
    treesize[y]+=treesize[x];
    return true;
  }
  bool unite(pair<int,int> v){
    return unite(v.first,v.second);
  }
  bool parcheck(int x,int y){
    return root(x)==root(y);
  }
  bool parcheck(pair<int,int> v){
    return parcheck(v.first,v.second);
  }
  int size(int x){
    return treesize[root(x)];
  }
  void clear(){
    treesize.assign(maxN,1);
    for(int i=0;i<maxN;++i)par[i]=i;
  }
  vector<vector<int>> groups(){
    vector<vector<int>> res(maxN);
    for(int i=0;i<maxN;++i)res[root(i)].eb(i);
    // return res;
    vector<vector<int>> res2;
    for(vector<int> x:res){
      if(x.size())res2.eb(x);
    }
    return res2;
  }
};

struct HLD{
private:
  //!
  vector<vector<int>> g;
  int fdfs(int now,int p){
    int d=0;
    par[now]=p;
    for(size_t i=0;i+1<g[now].size();++i){
      if(g[now][i]==p)swap(g[now][i],g[now].back());
      if(chmax(d,fdfs(g[now][i],now)))swap(g[now][0],g[now][i]);
    }
    g[now].pop_back();
    return d+1;
  }
  void sdfs(int now){
    in[now]=ETlist.size();
    ETlist.emplace_back(now);
    for(size_t i=0;i<g[now].size();++i){
      nxt[g[now][i]]=i?g[now][i]:nxt[now];
      sdfs(g[now][i]);
    }
    out[now]=ETlist.size();
  }
public:
  // nxt[i]:iheavy root
  // Heavy edge i = [in[nxt[i]],in[i]]
  // sub tree i = [in[i],out[i])
  vector<int> par,nxt,in,out,ETlist;
  segtree solvetree;
  // HLD(const vector<vector<int>>& G,int first=0):g(G),par(G.size()),nxt(G.size()),in(G.size()),out(G.size()),solvetree(G.size()){
  //   ETlist.reserve(G.size());
  //   init(first);
  // };
  HLD(int N):g(N),par(N),nxt(N),in(N),out(N),solvetree(N){ETlist.reserve(N);};
  void add_edge(int a,int b){
    g[a].emplace_back(b);
    g[b].emplace_back(a);
  }
  void init(int first=0){
    {
      int d=0;par[first]=-1;
      for(auto& x:g[first])if(chmax(d,fdfs(x,first)))swap(x,g[first][0]);
    }
    nxt[first]=first;
    sdfs(first);
  }
  int lca(int a,int b){
    if(in[a]>in[b])swap(a,b);
    if(nxt[a]==nxt[b])return a;
    return lca(a,par[nxt[b]]);
  }
  bool solveprod(int a,int b){
    if(in[a]>in[b])swap(a,b);
    if(nxt[a]==nxt[b])return solvetree.prod(in[a]+1,in[b]+1);
    return solveprod(a,par[nxt[b]])|solvetree.prod(in[nxt[b]],in[b]+1);
  }
  void solveapply(int a,int b){
    if(in[a]>in[b])swap(a,b);
    if(nxt[a]==nxt[b])solvetree.apply(in[a]+1,in[b]+1,true);
    else{
      solveapply(a,par[nxt[b]]);
      solvetree.apply(in[nxt[b]],in[b]+1,true);
    }
  }
};

vector<vector<pair<int,int>>> g;
vector<bool> xorlist;
int N,Q;
void dfs(int now=0,int par=-1,bool s=false){
  xorlist[now]=s;
  for(auto&[f,to]:g[now]){
    if(to==par)continue;
    dfs(to,now,s^f);
  }
}
int main(){
  startupcpp();
  cin>>N>>Q;
  g.resize(N);
  HLD hld(N);
  unionfind dsu(N);
  vector<bool> ans(Q);
  //id u v w
  vector<tuple<int,int,int,bool>> edge;
  for(int i=0;i<Q;++i){
    int u,v,w;
    cin>>u>>v>>w;
    --u;--v;
    if(dsu.unite(u,v)){
      ans[i]=true;
      g[u].emplace_back(w,v);
      g[v].emplace_back(w,u);
      hld.add_edge(u,v);
    }else edge.emplace_back(i,u,v,!w);
  }
  for(int i=1;i<N;++i)if(dsu.unite(0,i)){
    g[0].emplace_back(0,i);
    hld.add_edge(0,i);
  }
  hld.init();
  xorlist.resize(N);
  dfs();
  for(auto&[id,u,v,w]:edge){
    if((xorlist[u]^xorlist[v]^w)||hld.solveprod(u,v)){
      ans[id]=false;
      continue;
    }
    ans[id]=true;
    hld.solveapply(u,v);
  }
  for(auto f:ans){
    if(f)printYES;
    else printNO;
  }
}