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

class starry_sky_tree {
  array<ll,131072> c;

  void init_build() {
    size_t m = c.size();
    for (size_t i = m/2; i-- > 1;) {
      ll ma = std::max(c[i<<1], c[i<<1|1]);
      c[i<<1] -= ma;
      c[i<<1|1] -= ma;
      c[i] = ma;
    }
  }

  void maintain(size_t i) {
    ll ma = std::max(c[i<<1], c[i<<1|1]);
    c[i<<1] -= ma;
    c[i<<1|1] -= ma;
    c[i] += ma;
  }

public:
  starry_sky_tree() {
    c.fill(0);
  }

  void add(size_t l, size_t r, const ll& x) {
    size_t m = c.size();
    l += m/2;
    r += m/2;
    while (l < r) {
      if (l & 1) {
        c[l] += x;
        ++l;
      }
      if (r & 1) {
        --r;
        c[r] += x;
      }
      if ((l-1) > 1) maintain((l-1)>>1);
      if (r < m) maintain(r>>1);
      l >>= 1;
      r >>= 1;
    }
    for (size_t i = l-1; i > 1; i >>= 1)
      maintain(i);
    assert(r < m);
    for (size_t i = r; i >= 1; i >>= 1)
      maintain(i);
  }

  ll max(size_t l, size_t r) const {
    assert(l < r);
    size_t m = c.size();
    l += m/2;
    r += m/2;
    vector<size_t> vll, rr;
    size_t li = l;
    size_t ri = r;
    while (li < ri) {
      if (li & 1) vll.push_back(li++);
      if (ri & 1) rr.push_back(--ri);
      li >>= 1;
      ri >>= 1;
    }

    vector<ll> cand;
    ll curl = c[1];
    for (size_t i = li-1; i > 1; i >>= 1) curl += c[i];
    for (size_t i = li-1; !vll.empty();) {
      size_t j = vll.back();
      (i <<= 1) |= 1;
      if (i == j) {
        cand.push_back(curl+c[i--]);
        vll.pop_back();
      }
      curl += c[i];
    }
    ll curr = c[1];
    for (size_t i = ri; i > 1; i >>= 1) curr += c[i];
    for (size_t i = ri; !rr.empty();) {
      size_t j = rr.back();
      i <<= 1;
      if (i == j) {
        cand.push_back(curr+c[i++]);
        rr.pop_back();
      }
      curr += c[i];
    }
    return *max_element(cand.begin(), cand.end());
  }
};

int main(){
  startupcpp();
  ll i,j,N,K,allsum=0;
  cin>>N>>K;
  vector<starry_sky_tree> dp(K);
  vec bfindex(N,-1);
  ll x;
  cin>>x;
  bfindex[--x]=0;
  rep1(i,N){
    cin>>x;
    --x;
    rep1(j,K)dp[j].add(i,i+1,dp[j-1].max(0,i));
    if(bfindex[x]>=0){
      ll t=i-bfindex[x];
      allsum+=t;
      rep1(j,K)dp[j].add(bfindex[x]+1,i+1,t);
    }
    bfindex[x]=i;
  }
  print(allsum-dp[K-1].max(0,N));
}