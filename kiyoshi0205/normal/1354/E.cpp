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
#define endl "\n"
#define eb emplace_back
#define print(v) cout<<v<<endl
#define printyes cout<<"Yes"<<endl
#define printno cout<<"No"<<endl
#define printYES cout<<"YES"<<endl
#define printNO cout<<"NO"<<endl
#define output(v) do{bool f=0;for(auto outi:v){cout<<(f?" ":"")<<outi;f=1;}cout<<endl;}while(0)
#define matoutput(v) do{for(auto outimat:v)output(outimat);}while(0)
const ll mod=1000000007;
// const ll mod=998244353;
const ll inf=1LL<<60;
const double PI = acos(-1);
const double eps = 1e-9;
template<class T> inline bool chmax(T& a,T b){bool x=a<b;if(x)a=b;return x;} 
template<class T> inline bool chmin(T& a,T b){bool x=a>b;if(x)a=b;return x;} 

void startupcpp(){
  cin.tie(0);
  ios::sync_with_stdio(false);
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
  bool unite(int x,int y){
    x=root(x);
    y=root(y);
    if(x==y)return false;
    if(treesize[x]>treesize[y])swap(x,y);
    par[x]=y;
    treesize[y]+=treesize[x];
    return true;
  }
  bool parcheck(int x,int y){
    return root(x)==root(y);
  }
  int size(int x){
    return treesize[root(x)];
  }
  void clear(){
    treesize.assign(maxN,1);
    for(int i=0;i<maxN;++i)par[i]=i;
  }
};

int main(){
  // startupcpp();
  ll i,j,N,M,collim[3],chcnt=0;
  cin>>N>>M;
  rep(i,3)cin>>collim[i];
  unionfind utree(N*2);
  while(M--){
    cin>>i>>j;
    --i;--j;
    utree.unite(i,j+N);
    utree.unite(i+N,j);
  }
  rep(i,N)if(utree.parcheck(i,i+N))break;
  if(i!=N){
    printNO;
    return 0;
  }
  vector<bitset<5001>> dp(1,bitset<5001>("1"));
  vector<bool> used(N,false);
  mat alis,blis;
  rep(i,N){
    if(used[i])continue;
    vec a,b;
    auto bs=dp.back();
    For(j,i,N<<1){
      if(utree.parcheck(i,j)){
        (j<N?a:b).eb(j%N);
        used[j%N]=true;
      }
    }
    if(a.size()>b.size())swap(a,b);
    alis.eb(a);
    blis.eb(b);
    dp.eb(bs|(bs<<(b.size()-a.size())));
    chcnt+=a.size();
  }
  if(chcnt>collim[1]||!dp[alis.size()][collim[1]-=chcnt]){
    printNO;
    return 0;
  }
  printYES;
  vec ans(N);
  brep(i,alis.size()){
    if(blis[i].size()<=alis[i].size()+collim[1]&&dp[i][collim[1]+alis[i].size()-blis[i].size()]){
      collim[1]-=blis[i].size()-alis[i].size();
      alis[i].swap(blis[i]);
    }
    for(auto x:alis[i]){ans[x]=2;}
    for(auto x:blis[i]){
      if(collim[0]){
        --collim[0];
        ans[x]=1;
      }else{
        ans[x]=3;
      }
    }
  }
  rep(i,N)cout<<ans[i];
  cout<<endl;
}