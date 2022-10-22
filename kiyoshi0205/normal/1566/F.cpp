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

int N,M;
pvec inputsegment(vec a){
  pvec res;
  int l,r;
  for(int i=0;i<M;++i){
    cin>>l>>r;
    if(lower_bound(all(a),l)!=upper_bound(all(a),r))continue;
    res.emplace_back(l,r);
  }
  M=res.size();
  vsort(res);
  set<datas> se;
  for(int i=0;i<M;++i){
    if(i&&res[i-1].first==res[i].first)continue;
    auto itr=se.lower_bound(datas(res[i].second,0));
    while(itr!=se.end())itr=se.erase(itr);
    se.emplace(res[i].second,res[i].first);
  }
  res.clear();
  for(auto[r,l]:se)res.emplace_back(l,r);
  M=res.size();
  debug(a);
  debug(res);
  return res;
}
int main(){
  startupcpp();
int codeforces;cin>>codeforces;while(codeforces--){
  int i,j=0;
  cin>>N>>M;
  vec a(N+4);
  rep(i,N)cin>>a[i];
  a[i++]=-inf;
  a[i++]=-inf-1;
  a[i++]=inf;
  a[i++]=inf+1;
  vsort(a);
  pvec segment=inputsegment(a);
  vec dp(1,0);
  vec bfv(1,0);
  rep(i,N+3){
    // a[i] to a[i+1]
    pvec ch;
    while(j<M&&segment[j].first<a[i+1]){
      assert(a[i]<segment[j].first&&segment[j].second<a[i+1]);
      ch.emplace_back(segment[j++]);
    }
    ll k,init=inf;
    rep(k,dp.size())chmin(init,dp[k]+bfv[k]);
    vec ndp(ch.size()+1,init);
    ndp.back()=*min_element(all(dp));
    rep(k,ch.size()){
      chmin(ndp[k],ndp.back()+ch[ch.size()-k-1].first-a[i]);
      ndp[k]+=ch[ch.size()-k-1].first-a[i];
      if(k)ndp[k]+=a[i+1]-ch[ch.size()-k].second;
    }
    if(ch.size())ndp.back()+=a[i+1]-ch[0].second;
    swap(dp,ndp);
    bfv.clear();
    bfv.emplace_back(0);
    brep(k,ch.size())bfv.emplace_back(a[i+1]-ch[k].second);
  }
  print(dp[0]);
}
}