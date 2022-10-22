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

ll N;
int main(){
  startupcpp();
  cin>>N;
  ll i;
  vec v(N);
  rep(i,N)cin>>v[i];
  if(N==1){
    print(v[0]);
    return 0;
  }
  vec p,m;
  for(auto x:v){
    if(x>0)p.emplace_back(x);
    else m.emplace_back(-x);
  }
  vec sump(p.size()+1,0),summ(m.size()+1,0),rsump(p.size()+1,0),rsumm(m.size()+1,0);
  {
  vrsort(p);
  vrsort(m);
  rep(i,p.size())sump[i+1]=sump[i]+p[i];
  rep(i,m.size())summ[i+1]=summ[i]+m[i];
  reverse(all(p));
  reverse(all(m));
  rep(i,p.size())rsump[i+1]=rsump[i]+p[i];
  rep(i,m.size())rsumm[i+1]=rsumm[i]+m[i];
  }
  pvec ch;
  if(N%3==0)ch.emplace_back(N-1,1);
  if(N%3==1)ch.emplace_back(N,0);
  if(N%3==2)ch.emplace_back(0,N);
  i=abs(ch[0].first-ch[0].second)-2;
  if(i%3==0)i-=2;
  while(i>0){
    //i
    ll A=(N-i)/2,B=(N+i)/2;
    if(ch.back().first<ch.back().second)swap(A,B);
    ch.emplace_back(A,B);
    i-=2;
    if(i%3==0)i-=2;
  }
  ll ans=-inf;
  bool f=N%2==1;
  if(f)ch.pop_back();
  for(auto[pcnt,mcnt]:ch){
    ll ret=0;
    if(pcnt<=int(p.size()))ret+=sump[pcnt];
    else{
      ret+=sump.back();
      pcnt-=p.size();
      ret-=rsumm[pcnt];
    }
    if(mcnt<=int(m.size()))ret+=summ[mcnt];
    else{
      ret+=summ.back();
      mcnt-=m.size();
      ret-=rsump[mcnt];
    }
    chmax(ans,ret);
  }
  debug(ans);
  if(f){
    ll ret=0,pcnt=N/2+1,mcnt=N/2;
    if(pcnt<=int(p.size()))ret+=sump[pcnt];
    else{
      ret+=sump.back();
      pcnt-=p.size();
      ret-=rsumm[pcnt];
    }
    if(mcnt<=int(m.size()))ret+=summ[mcnt];
    else{
      ret+=summ.back();
      mcnt-=m.size();
      ret-=rsump[mcnt];
    }
    vec p(N/2+1),m(N/2);
    rep(i,N){
      if(i&1)m[i/2]=v[i];
      else p[i/2]=v[i];
    }
    debug(ret,p,m);
    if(ret==accumulate(all(p),0LL)-accumulate(all(m),0LL)){
      //mendou case
      ret-=(*min_element(all(p))-*max_element(all(m)))*2;
      debug(ret);
    }
    chmax(ans,ret);
  }
  print(ans);
}