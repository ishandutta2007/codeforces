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
#define uniq(v) vsort(v),(v).erase(unique(all(v)),(v).end())
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
// constexpr ll mod=1000000007;
constexpr ll mod=998244353;
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
  cin.tie(0)->sync_with_stdio(0);
  cout<<fixed<<setprecision(15);
}
struct scc_graph{
public:
  scc_graph(int n):_n(n){}
  scc_graph(vector<vector<int>> g):_n(g.size()){
    for(int i=0;i<_n;++i)for(auto& x:g[i])add_edge(i,x);
    scc_ids();
  }
  scc_graph(vector<vector<long long>> g):_n(g.size()){
    for(int i=0;i<_n;++i)for(auto& x:g[i])add_edge(i,x);
    scc_ids();
  }

  void add_edge(int from,int to){
    assert(0<=from&&from<_n);
    assert(0<=to&&to<_n);
    edges.push_back({from,{to}});
  }
  void add_clause(int i,bool f,int j,bool g){
    assert(0<=i&&i*2<_n);
    assert(0<=j&&j*2<_n);
    add_edge(i<<1|!f,j<<1|g);
    add_edge(j<<1|!g,i<<1|f);
  }
  //n must be *2
  vector<bool> solve_twosat(){
    if(!group_num)scc_ids();
    int m=_n>>1;
    vector<bool> answer(m);
    for(int i=0;i<m;++i){
      if(ids[i<<1]==ids[i<<1|1])return{};
      answer[i]=ids[i<<1]<ids[i<<1|1];
    }
    return answer;
  }

  vector<vector<int>> scc(){
    if(!group_num)scc_ids();
    vector<int> counts(group_num);
    for(auto& x:ids)counts[x]++;
    vector<vector<int>> groups(group_num);
    for(int i=0;i<group_num;++i)groups[i].reserve(counts[i]);
    for(int i=0;i<_n;++i)groups[ids[i]].push_back(i);
    return groups;
  }
  int size(){return group_num;}
  int operator[](int k) const{return ids[k];}
private:
  int _n,group_num=0;
  struct edge{
    int to;
  };
  struct csr{
    vector<int> start;
    vector<edge> elist;
    csr(int n,const vector<pair<int,edge>>& edges):start(n+1),elist(edges.size()){
      for(auto& e:edges)++start[e.first+1];
      for(int i=0;i<n;++i)start[i+1]+=start[i];
      auto counter=start;
      for(auto& e:edges)elist[counter[e.first]++]=e.second;
    }
  };
  vector<int> ids;
  vector<pair<int,edge>> edges;
  // @return pair of(# of scc,scc id)
  void scc_ids(){
    auto g=csr(_n,edges);
    int now_ord=0;
    vector<int> visited,low(_n),ord(_n,-1);
    ids.resize(_n);
    visited.reserve(_n);
    auto dfs=[&](auto self,int v)-> void{
      low[v]=ord[v]=now_ord++;
      visited.push_back(v);
      for(int i=g.start[v];i<g.start[v+1];++i){
        auto to=g.elist[i].to;
        if(ord[to]==-1){
          self(self,to);
          low[v]=min(low[v],low[to]);
        }else{
          low[v]=min(low[v],ord[to]);
        }
      }
      if(low[v]==ord[v]){
        while(true){
          int u=visited.back();
          visited.pop_back();
          ord[u]=_n;
          ids[u]=group_num;
          if(u==v)break;
        }
        group_num++;
      }
    };
    for(int i=0;i<_n;++i){
      if(ord[i]==-1)dfs(dfs,i);
    }
    for(auto& x:ids){
      x=group_num-1-x;
    }
  }
};

ll N,M,K,H,W,A,B,C,D;
string s,t;
ll ans;
int main(){
  startupcpp();
// int codeforces;cin>>codeforces;while(codeforces--){
  ll i,j;
  cin>>N>>M>>K;
  vec a(N);
  rep(i,N)cin>>a[i];
  pvec edge(M);
  for(auto&[u,v]:edge){
    cin>>u>>v;
    --u;--v;
  }
  ll ok=1000000001,ng=0;
  while(ok-ng>1){
    ll mid=(ok+ng)/2;
    scc_graph g(N);
    for(auto&[u,v]:edge){
      if(a[u]<=mid&&a[v]<=mid)g.add_edge(u,v);
    }
    auto scc=g.scc();
    if(ll(scc.size())<N){
      ok=mid;
      continue;
    }
    mat sg(N);
    for(auto&[u,v]:edge){
      if(a[u]<=mid&&a[v]<=mid)sg[u].emplace_back(v);
    }
    vec dp(N,0);
    rep(i,N){
      auto x=scc[i][0];
      if(a[x]>mid)continue;
      chmax(dp[x],1LL);
      for(auto y:sg[x])chmax(dp[y],dp[x]+1);
    }
    if(*max_element(all(dp))>=K)ok=mid;
    else ng=mid;
  }
  if(ok==1000000001)ok=-1;
  print(ok);
// }
}