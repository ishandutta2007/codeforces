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
#define print(x) cout<<x<<endl
#define printyes print("Yes")
#define printno print("No")
#define printYES print("YES")
#define printNO print("NO")
#define output(v) do{bool f=0;for(auto outi:v){cout<<(f?" ":"")<<outi;f=1;}cout<<endl;}while(0)
#define matoutput(v) do{for(auto outimat:v)output(outimat);}while(0)
// const ll mod=1000000007;
const ll mod=998244353;
const ll inf=1LL<<60;
const double PI=acos(-1);
const double eps=1e-9;
template<class T,class E> ostream& operator<<(ostream& os,pair<T,E>& p){return os<<"{"<<p.first<<","<<p.second<<"}";}
template<class T> inline bool chmax(T& a,T b){bool x=a<b;if(x)a=b;return x;}
template<class T> inline bool chmin(T& a,T b){bool x=a>b;if(x)a=b;return x;}

void startupcpp(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout<<fixed<<setprecision(15);
}

vec par,treesize,edgesize;
mat dp;
int root(int x){
  while(par[x]!=x){
    x=par[x]=par[par[x]];
  }
  return x;
}
void solve(int a,int b){
  a=root(a);b=root(b);
  if(a==b){
    if(++edgesize[a]==treesize[a]*(treesize[a]-1)/2)dp[a].eb(1);
    return;
  }
  if(treesize[a]>treesize[b])swap(a,b);
  par[a]=b;
  treesize[b]+=treesize[a];
  edgesize[b]+=edgesize[a]+1;
  vec next(treesize[b]-1,0);
  int i,j;
  rep(i,dp[a].size())rep(j,dp[b].size())(next[i+j]+=dp[a][i]*dp[b][j]%mod)%=mod;
  dp[b].swap(next);
  if(edgesize[b]==treesize[b]*(treesize[b]-1)/2)dp[b].eb(1);
}
int main(){
  startupcpp();
  ll i,j,N;
  cin>>N;
  pvec v(N*(N-1)/2);
  rep(i,N)rep(j,N){
    ll x;
    cin>>x;
    if(i<j)v[--x]=datas(i,j);
  }
  par.resize(N);treesize.resize(N,1);edgesize.resize(N,0);
  rep(i,N)par[i]=i;
  dp.resize(N,vec(1,1));
  for(auto x:v){
    solve(x.first,x.second);
  }
  auto ans=dp[root(0)];
  reverse(all(ans));
  output(ans);
}