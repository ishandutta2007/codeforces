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
struct rolling_hash{
public:
  using u64=uint_fast64_t;
  using size_type=uint_fast32_t;
  using i128=__int128_t;

  static constexpr u64 rollmod=(1LL<<61)-1;
  static constexpr u64 base=2295;

  string str;
  vector<u64> hash_,pow;

private:
  static constexpr u64 mask30=(1LL<<30)-1;
  static constexpr u64 mask31=(1LL<<31)-1;

  size_type xorshift(size_type x) const{
    x^=x<<13;
    x^=x>>17;
    x^=x<<5;
    return x;
  }

public:
  rolling_hash(const rolling_hash &)=default;
  rolling_hash(rolling_hash&&)=default;

  rolling_hash():str(){};
  rolling_hash(const string& str):str(str){
    hash_.resize(str.size()+1,0);
    pow.resize(str.size()+1,1);
    for(size_type i=0;i<str.size();i++){
      hash_[i+1]=mul(hash_[i],base)+xorshift(str[i]+1);
      pow[i+1]=mul(pow[i],base);
      if(hash_[i+1]>=rollmod)hash_[i+1]-=rollmod;
    }
  }

  u64 mul(i128 a,i128 b) const{
    i128 t=a*b;
    t=(t>>61)+(t&rollmod);

    if(t>=rollmod)return t-rollmod;
    return t;
  }
  u64 hash() const{return hash_.back();}
  //[L,R)
  u64 hash(size_type l,size_type r) const{
    u64 ret=rollmod+hash_[r]-mul(hash_[l],pow[r-l]);
    return ret<rollmod?ret:ret-rollmod;
  }

  size_type size() const{return str.size();}
};
ll N,Q;
string s,t;
int main(){
  startupcpp();
  ll i,j;
  cin>>N>>Q>>s>>t;
  mat first(N+1,vec(26,0));
  rep(i,N){
    rep(j,26)first[i+1][j]=first[i][j]*2%mod;
    first[i+1][t[i]-'a']++;
    if(first[i+1][t[i]-'a']==mod)first[i+1][t[i]-'a']=0;
  }
  debug(first);
  while(Q--){
    ll qi;
    string qst,chst=s;
    cin>>qi>>qst;
    rep(j,N){
      if(chst.size()>=qst.size())break;
      chst+=t[j]+chst;
    }
    if(j>qi||chst.size()<qst.size()){print(0);continue;}
    ll ans=0,K=qst.size();
    rolling_hash rqs(qst),rchs(chst);
    vec cnt(26,0);
    rep(i,K){
      bool f1=true,f2=true;
      if(i&&rqs.hash(0,i)!=rchs.hash(rchs.size()-i,rchs.size()))f1=false;
      if(i<K-1&&rqs.hash(i+1,K)!=rchs.hash(0,K-i-1))f2=false;
      if(f1&&f2)cnt[qst[i]-'a']++;
    }
    debug(cnt);
    rep(i,chst.size()-K+1){
      if(rqs.hash()==rchs.hash(i,i+K))ans++;
    }
    (ans*=modpow(2,qi-j))%=mod;
    rep(i,26){
      ll tmp=first[qi][i]-first[j][i]*modpow(2,qi-j)%mod;
      if(tmp<0)tmp+=mod;
      ans+=tmp*cnt[i]%mod;
    }
    print(ans%mod);
  }
}