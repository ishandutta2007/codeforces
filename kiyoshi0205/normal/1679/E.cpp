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
}
struct subsets {
  int s;

  subsets(int s_) : s(s_) {}

  struct itr {
    int s;
    int t;

    bool operator!=(itr x) { return t != -1; }
    void operator++() { t -= 1; }
    int operator*() { return t &= s; }
  };

  itr begin() { return {s, s}; }
  itr end() { return {}; }
};
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
int popcnt[1<<17];
int ans[18][1<<17];

void q(int bit,int cnt){
  for(int i=0;i<18;++i){
    ans[i][bit]+=modpow(i,cnt);
    if(ans[i][bit]>=mod)ans[i][bit]-=mod;
  }
}
int main(){
  startupcpp();
  for(int i=0;i<(1<<17);++i)popcnt[i]=popcount(i);
  int N;
  string s;
  cin>>N>>s;
  int C=count(all(s),'?');
  for(int i=0;i<N;++i){
    int tmp=C,bit=0;
    //len=odd
    q(0,tmp);
    for(int j=1;i-j>=0&&i+j<N;++j){
      if(s[i-j]==s[i+j]){
        if(s[i-j]=='?')q(bit,--tmp);
        else q(bit,tmp);
      }else if(s[i-j]!='?'&&s[i+j]!='?'){
        break;
      }else{
        int c=(s[i-j]^s[i+j]^'?')-'a';
        q(bit|=1<<c,--tmp);
      }
    }
    tmp=C;bit=0;
    //len=even
    for(int j=0;i-j>=0&&i+j+1<N;++j){
      if(s[i-j]==s[i+j+1]){
        if(s[i-j]=='?')q(bit,--tmp);
        else q(bit,tmp);
      }else if(s[i-j]!='?'&&s[i+j+1]!='?'){
        break;
      }else{
        int c=(s[i-j]^s[i+j+1]^'?')-'a';
        q(bit|=1<<c,--tmp);
      }
    }
  }
  for(auto& v:ans){
    for(int i=0;i<18;++i){
      for(int bit=0;bit<(1<<17);++bit){
        if(bit>>i&1){
          v[bit]+=v[bit^(1<<i)];
          if(v[bit]>=mod)v[bit]-=mod;
        }
      }
    }
  }
  int Q;
  cin>>Q;
  string t;
  while(Q--){
    cin>>t;
    int bit=0;
    for(auto& x:t)bit|=1<<(x-'a');
    print(ans[popcnt[bit]][bit]);
  }
}