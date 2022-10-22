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
#define double long double
using datas=pair<ll,ll>;
using ddatas=pair<double,double>;
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
#define eb emplace_back
#define print(x) cout<<x<<endl
#define printyes print("Yes")
#define printno print("No")
#define printYES print("YES")
#define printNO print("NO")
#define output(v) do{bool f=0;for(auto outi:v){cout<<(f?" ":"")<<outi;f=1;}cout<<endl;}while(0)
#define matoutput(v) do{for(auto outimat:v)output(outimat);}while(0)
const ll mod=1000000007;
// const ll mod=998244353;
const ll inf=1LL<<60;
const double PI=acos(-1);
const double eps=1e-9;
template<class T,class E> ostream& operator<<(ostream& os,const pair<T,E>& p){return os<<"("<<p.first<<","<<p.second<<")";}
template<class T> ostream& operator<<(ostream& os,const vector<T>& v){
  os<<"{";ll i;
  rep(i,v.size()){
    if(i)os<<",";
    os<<v[i];
  }
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

void startupcpp(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout<<fixed<<setprecision(15);
}

double distance(ddatas x,ddatas y){
  double a=x.first-y.first,b=x.second-y.second;
  return sqrt(a*a+b*b);
}

ll modinv(ll a,ll m=mod) {
  ll b=m,u=1,v=0,t;
  while(b){
    t=a/b;
    a-=t*b; swap(a,b);
    u-=t*v; swap(u,v);
  }
  return (u+m)%m;
}

ll moddevide(ll a,ll b){return (a*modinv(b))%mod;}

vec modncrlistp,modncrlistm;

ll modncr(ll n,ll r){
  if(n<r)return 0;
  ll i,size=modncrlistp.size();
  if(size<=n){
    modncrlistp.resize(n+1);
    modncrlistm.resize(n+1);
    if(!size){
      modncrlistp[0]=modncrlistm[0]=1;
      size++;
    }
    For(i,size,n+1){
      modncrlistp[i]=modncrlistp[i-1]*i%mod;
      modncrlistm[i]=modinv(modncrlistp[i]);
    }
  }
  return modncrlistp[n]*modncrlistm[r]%mod*modncrlistm[n-r]%mod;
}

ll modpow(ll a,ll n,ll m=mod){
  ll res=1;
  while(n>0){
    if(n&1)res=res*a%m;
    a=a*a%m;
    n>>=1;
  }
  return res;
}

ll gcd(ll a,ll b){if(!b)return abs(a);return (a%b==0)?abs(b):gcd(b,a%b);}
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}

ll countdigits(ll n){
  ll ans=0;
  while(n){n/=10;ans++;}
  return ans;
}

ll sumdigits(ll n){
  ll ans=0;
  while(n){ans+=n%10;n/=10;}
  return ans;
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
ll N,M,K,H,W,A,B,C,D;
string s,t;
ll ans;
int main(){
  startupcpp();
  // int codeforces;cin>>codeforces;while(codeforces--){
  ll i,j;
  cin>>N>>K;
  vec glis(N);
  rep(i,N){
    cin>>glis[i];
    glis[i]--;
  }
  unionfind dsu(N);
  pvec edge;
  vec par(N,-1);
  rep(A,K){
    cin>>i>>j;
    --i;--j;
    dsu.unite(i,j);
    edge.eb(i,j);
    par[j]=i;
  }
  vec col(N);
  vec colorder(N);
  auto v=dsu.groups();
  M=v.size();
  scc_graph ch(M);
  vector<scc_graph> chs;
  rep(i,M){
    chs.eb(scc_graph(v[i].size()));
    rep(j,v[i].size()){
      colorder[v[i][j]]=j;
      col[v[i][j]]=i;
    }
  }
  
  rep(i,N){
    if(glis[i]==-1)continue;
    if(col[i]!=col[glis[i]])ch.add_edge(col[glis[i]],col[i]);
    else{
      j=col[i];
      chs[j].add_edge(colorder[glis[i]],colorder[i]);
    }
  }

  for(auto x:edge){
    j=col[x.first];
    chs[j].add_edge(colorder[x.first],colorder[x.second]);
  }
  auto asdfg=ch.scc();
  if(asdfg.size()!=M){print(0);return 0;}
  vec ans;
  for(auto vv:asdfg){
    auto sc=chs[vv[0]].scc();
    for(auto x:sc){
      if(x.size()!=1){print(0);return 0;}
      ans.eb(v[vv[0]][x[0]]+1);
    }
  }
  output(ans);
// }
}