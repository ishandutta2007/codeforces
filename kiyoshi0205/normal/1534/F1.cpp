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
  cout<<fixed<<setprecision(15);
}

ll modinv(ll a,const ll m=mod) noexcept{
  ll b=m,u=1,v=0,t;
  while(b){
    t=a/b;
    a-=t*b; swap(a,b);
    u-=t*v; swap(u,v);
  }
  return (u+m)%m;
}

ll moddevide(const ll a,const ll b) noexcept{return (a*modinv(b))%mod;}

vec modncrlistp,modncrlistm;

ll modncr(const ll n,const ll r) noexcept{
  if(n<r)return 0;
  ll i,size=modncrlistp.size();
  if(size<=n){
    modncrlistp.resize(n+1);
    modncrlistm.resize(n+1);
    if(!size){
      modncrlistp[0]=modncrlistm[0]=1;
      size++;
    }
    For(i,size,n+1)modncrlistp[i]=modncrlistp[i-1]*i%mod;
    modncrlistm[n]=modinv(modncrlistp[n]);
    for(i=n;i>size;--i)modncrlistm[i-1]=modncrlistm[i]*i%mod;
  }
  return modncrlistp[n]*modncrlistm[r]%mod*modncrlistm[n-r]%mod;
}

ll modpow(ll a,ll n,const ll m=mod){
  if(n<0)return 0;
  ll res=1;
  while(n>0){
    if(n&1)res=res*a%m;
    a=a*a%m;
    n>>=1;
  }
  return res;
}

constexpr ll gcd(const ll a,const ll b) noexcept{return (!b)?abs(a):(a%b==0)?abs(b):gcd(b,a%b);}
constexpr ll lcm(const ll a,const ll b) noexcept{return a/gcd(a,b)*b;}

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
  vector<vector<int>> makeDAG(){
    if(!group_num)scc_ids();
    vector<vector<int>> res(group_num);
    for(auto& e:edges)if(ids[e.first]!=ids[e.second.to])res[ids[e.first]].emplace_back(ids[e.second.to]);

    for(auto& v:res){
      sort(v.begin(),v.end());
      v.erase(unique(v.begin(),v.end()),v.end());
    }
    return res;
  }
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


ll H,W,cnt;
int main(){
  startupcpp();
  cin>>H>>W;
  ll i,j,k;
  vector<string> v(H);
  rep(i,H)cin>>v[i];
  rep(i,W)cin>>j;
  scc_graph g(H*W+1);
  rep(i,H)rep(j,W){
    if(v[i][j]=='#'){
      if(i&&v[i-1][j]=='#')g.add_edge(i*W+j,(i-1)*W+j);
      if(j&&v[i][j-1]=='#')g.add_edge(i*W+j,i*W+j-1);
      if(j+1<W&&v[i][j+1]=='#')g.add_edge(i*W+j,i*W+j+1);
      For(k,i+1,H){
        if(v[k][j]=='#'){
          g.add_edge(i*W+j,k*W+j);
          break;
        }
        if(j&&v[k][j-1]=='#')g.add_edge(i*W+j,k*W+j-1);
        if(j+1<W&&v[k][j+1]=='#')g.add_edge(i*W+j,k*W+j+1);
      }
    }else g.add_edge(H*W,i*W+j);
  }
  auto sg=g.makeDAG();
  vec ch(sg.size(),0);
  for(auto v:sg)for(auto x:v)ch[x]++;
  for(auto x:ch)cnt+=x==0;
  print(cnt-1);
}