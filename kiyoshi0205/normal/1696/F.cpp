#ifdef DEBUG
#include"stdlibrary.h"
#else
#pragma GCC target("avx")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
using namespace std;
#endif
// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>
// #include<ext/pb_ds/tag_and_trait.hpp>
// using namespace __gnu_pbds;
// #include<boost/multiprecision/cpp_int.hpp>
// namespace multiprecisioninteger = boost::multiprecision;
// using cint=multiprecisioninteger::cpp_int;
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
  cin.tie(0)->sync_with_stdio(0);
  cout<<fixed<<setprecision(15);
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
  bool merge(int x,int y){
    x=root(x);
    y=root(y);
    if(x==y)return false;
    if(treesize[x]>treesize[y])swap(x,y);
    par[x]=y;
    treesize[y]+=treesize[x];
    return true;
  }
  bool merge(pair<int,int> v){
    return merge(v.first,v.second);
  }
  bool same(int x,int y){
    return root(x)==root(y);
  }
  bool same(pair<int,int> v){
    return same(v.first,v.second);
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
    for(int i=0;i<maxN;++i)res[root(i)].emplace_back(i);
    // return res;
    vector<vector<int>> res2;
    for(vector<int> x:res){
      if(x.size())res2.emplace_back(x);
    }
    return res2;
  }
};

ll dist[100][100];
int main(){
  startupcpp();
int codeforces;cin>>codeforces;while(codeforces--){
  ll i,j,k,N;
  cin>>N;
  vector<vector<string>> inp(N-1);
  unionfind edgedsu(N*N);
  rep(i,N)rep(j,i)edgedsu.merge(i*N+j,j*N+i);
  rep(i,N-1){
    inp[i].reserve(N-1-i);
    inp[i].resize(N-1-i);
    rep(j,N-1-i){
      cin>>inp[i][j];
      rep(k,N){
        if(inp[i][j][k]&1)edgedsu.merge(i*N+k,(i+j+1)*N+k);
      }
    }
  }
  rep(i,N)if(edgedsu.size(i*N+i)!=1)break;
  if(i!=N){
    printno;
    continue;
  }
  auto dsug=edgedsu.groups();
  unionfind dsu(N);
  pvec ans;
  for(auto edgelis:dsug){
    if((ll)edgelis.size()!=2*(N-1))continue;
    dsu.clear();
    for(auto x:edgelis)dsu.merge(x/N,x%N);
    if(dsu.size(0)!=N)continue;
    rep(i,N){
      rep(j,N)dist[i][j]=inf;
      dist[i][i]=0;
    }
    for(auto x:edgelis)dist[x/N][x%N]=1;
    rep(k,N)rep(i,N)rep(j,N)chmin(dist[i][j],dist[i][k]+dist[k][j]);
    bool f=false;
    rep(i,N-1){
      if(f)break;
      rep(j,N-1-i){
        if(f)break;
        rep(k,N){
          if(f)break;
          if(inp[i][j][k]&1){
            f=dist[i][k]!=dist[i+j+1][k];
          }else{
            f=dist[i][k]==dist[i+j+1][k];
          }
        }
      }
    }
    if(f)continue;
    for(auto x:edgelis)if(x/N<x%N)ans.emplace_back(x/N+1,x%N+1);
    break;
  }
  if(ans.size()){
    printyes;
    for(auto&[a,b]:ans)print(a<<" "<<b);
  }else printno;
}
}