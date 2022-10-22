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
template<class T> inline bool chmax(T& a,T b){bool x=a<b;if(x)a=b;return x;}
template<class T> inline bool chmin(T& a,T b){bool x=a>b;if(x)a=b;return x;}
#ifdef DEBUG
void debugg(){cout<<endl;}
template<class T,class... Args>void debugg(const T& x,const Args&... args){cout<<" "<<x;debugg(args...);}
#define debug(...) cout<<__LINE__<<" ["<<#__VA_ARGS__<<"]:",debugg(__VA_ARGS__)
#else
#define debug(...) (void(0))
#endif

inline void startupcpp() noexcept{
  cin.tie(0);
  ios::sync_with_stdio(false);
}

vector<int> makecomplementforest(const vector<vector<int>>& g){
  const unsigned int N=g.size();
  vector<int> par(N),S(N);
  iota(allr(S),0);
  bool *inS=new bool[N];
  memset(inS,true,N);
  int *Q=new int[N];
  while(S.size()){
    const int root=S.back();
    S.pop_back();
    unsigned int Qsz=1,Qpos=0;
    par[root]=-1;
    Q[0]=root;
    inS[root]=false;
    while(Qpos<Qsz){
      const int now=Q[Qpos++];
      vector<int> L;
      L.reserve(S.size());
      for(const auto nx:g[now]){
        if(inS[nx]){
          L.emplace_back(nx);
          inS[nx]=false;
        }
      }
      for(const auto x:S){
        if(inS[x]){
          Q[Qsz++]=x;
          par[x]=now;
          inS[x]=false;
        }else inS[x]=true;
      }
      S.swap(L);
    }
  }
  delete[] inS;
  delete[] Q;
  return par;
}
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
  void sizechange(int id,int x){
    treesize[root(id)]=x;
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


ll N,M,K,H,W,A,B,C,D;
string s,t;
ll ans;
int main(){
  startupcpp();
  ll i;
  cin>>N>>M;
  vector<vector<int>> g(N);
  vector<tuple<int,int,int>> edge(M);
  for(auto& [x,a,b]:edge){
    cin>>a>>b>>x;
    --a;--b;
    g[a].emplace_back(b);
    g[b].emplace_back(a);
    A^=x;
  }
  unionfind dsu(N);
  auto v=makecomplementforest(g);
  rep(i,N){
    if(v[i]==-1)++K;
    else dsu.unite(i,v[i]);
  }
  vsort(edge);
  assert(N*(N-1)/2-M-N+K>=0);
  bool f=N*(N-1)/2-M-N+K==0;
  unionfind sdsu(N);
  for(auto [x,a,b]:edge){
    if(dsu.unite(a,b)){
      ans+=x;
      sdsu.unite(a,b);
    }else if(f&&x<A&&!sdsu.parcheck(a,b)){
      ans+=x;
      f=false;
    }
  }
  if(f)ans+=A;
  print(ans);
}