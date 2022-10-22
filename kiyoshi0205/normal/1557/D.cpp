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

// Merge:0->interval set,1->point set
template<typename T,int Merge=1>
struct rangeset:set<pair<T,T>>{
private:
  using P=pair<T,T>;
  using seitr=_Rb_tree_const_iterator<P>;
  const T TINF=numeric_limits<T>::max()/2;
public:
  // There are all [L,R] (not [L,R) )
  rangeset(){
    this->emplace(-TINF,-TINF);
    this->emplace(TINF,TINF);
  }

  // [L,R] covered?
  bool covered(T L,T R){
    assert(L<=R);
    seitr itr(--this->lower_bound(P(L+1,L)));
    return R<=itr->second;
  }
  bool covered(T x){
    return covered(x,x);
  }

  // what is covered [L,R] (not cover->return [-TINF,-TINF])
  P covered_by(T L,T R){
    assert(L<=R);
    seitr itr(--this->lower_bound(P(L+1,L)));
    if(R<=itr->second)return *itr;
    else return *(this->begin());
  }
  P covered_by(T x){
    return covered_by(x,x);
  }
  //insert [L,R] and merge, return (how many add point or interval)
  pair<seitr,T> insert(T L,T R){
    assert(L<=R);
    seitr itr(--this->lower_bound(P(L+1,L)));
    if(R<=itr->second)return pair<seitr,T>(itr,0);

    T deletecnt(0);
    if(itr->second<L-Merge){
      ++itr;
    }else{
      L=itr->first;
      deletecnt=itr->second-itr->first+Merge;
      itr=this->erase(itr);
    }
    while(itr->second<=R){
      deletecnt+=itr->second-itr->first+Merge;
      itr=this->erase(itr);
    }
    if(itr->first<=R+Merge){
      R=itr->second;
      deletecnt+=itr->second-itr->first+Merge;
      itr=this->erase(itr);
    }
    itr=this->emplace_hint(itr,L,R);
    return pair<seitr,T>(itr,R-L+Merge-deletecnt);
  }
  pair<seitr,T> insert(T x){
    // assert(Merge==1);
    return insert(x,x);
  }
  //delete intersect [L,R], return (how many erase point or interval)
  T remove(T L,T R){
    assert(L<=R);
    seitr itr(--this->lower_bound(P(L+1,L)));
    if(R<=itr->second){
      if(itr->first<=L-Merge)this->emplace_hint(itr,itr->first,L-Merge);
      if(itr->second>=R+Merge)this->emplace_hint(next(itr),R+Merge,itr->second);
      this->erase(itr);
      return R-L+Merge;
    }
    T deletecnt(0);
    if(itr->second<=L-Merge){
      ++itr;
    }else{
      deletecnt=itr->second-L+Merge;
      if(itr->first<=L-Merge)this->emplace_hint(itr,itr->first,L-Merge);
      itr=this->erase(itr);
    }
    while(itr->second<=R){
      deletecnt+=itr->second-itr->first+Merge;
      itr=this->erase(itr);
    }
    if(itr->first<R+Merge){
      deletecnt+=R-itr->first+Merge;
      if(R+Merge<=itr->second)this->emplace_hint(next(itr),R+Merge,itr->second);
      this->erase(itr);
    }
    return deletecnt;
  }
  T remove(T x){
    // assert(Merge==1);
    return remove(x,x);
  }
  T mex(T x){
    // assert(Merge==1);
    seitr itr(--this->lower_bound(P(x+1,x)));
    if(x<=itr->second)return itr->second+1;
    else return x;
  }
};

ll N,M,K,H,W,A,B,C,D;
string s,t;
ll ans;
int main(){
  startupcpp();
  ll i;
  cin>>N>>M;
  pvec v;
  {
    vector<rangeset<ll>> se(N);
    while(M--){
      cin>>i>>A>>B;
      se[--i].insert(A,B);
    }
    rep(i,N){
      for(auto [l,r]:se[i]){
        if(abs(l)>mod)continue;
        v.emplace_back(l,i+1);
        v.emplace_back(r+1,-i-1);
      }
    }
  }
  mat g(N);
  vsort(v);
  set<ll> se;
  for(auto x:v){
    auto id=x.second;
    if(id<0){
      se.erase(-id);
      continue;
    }
    auto itr=se.emplace(id).first;
    if(itr!=se.begin())g[*prev(itr)-1].emplace_back(id-1);
    if(++itr!=se.end())g[id-1].emplace_back(*itr-1);
  }
  debug(g);
  vec dp(N,1),bf(N,-1);
  rep(i,N){
    uniq(g[i]);
    for(auto x:g[i]){
      if(chmax(dp[x],dp[i]+1))bf[x]=i;
    }
  }
  i=max_element(all(dp))-dp.begin();
  vec ch(N,1);
  do{
    ch[i]=0;
    i=bf[i];
  }while(i>=0);
  print(accumulate(all(ch),0LL));
  vec ans;
  rep(i,N)if(ch[i])ans.emplace_back(i+1);
  output(ans);
}