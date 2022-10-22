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
template<class T,class E> ostream& operator<<(ostream& os,const map<T,E>& v){
  os<<"{";bool f=false;
  for(auto& x:v){if(f)os<<",";os<<x;f=true;}
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
    For(i,size,n+1)modncrlistp[i]=modncrlistp[i-1]*i%mod;
    modncrlistm[n]=modinv(modncrlistp[n]);
    for(i=n;i>size;--i)modncrlistm[i-1]=modncrlistm[i]*i%mod;
  }
  return modncrlistp[n]*modncrlistm[r]%mod*modncrlistm[n-r]%mod;
}

ll modpow(ll a,ll n,ll m=mod){
  if(n<0)return 0;
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
datas crt(const vec& r,const vec& m) {
  assert(r.size()==m.size());
  int n=int(r.size());
  //Contracts: 0 <=r0 < m0
  ll r0=0,m0=1;
  for(int i=0;i<n;++i){
    assert(1<=m[i]);
    ll r1=r[i]%m[i],m1=m[i];
    if(m0<m1){
      swap(r0,r1);
      swap(m0,m1);
    }
    if(m0%m1==0){
      if(r0%m1!=r1)return {0,0};
      continue;
    }
    ll a=m0%m1;
    if(a<0)a+=m1;
    ll g=m1,im=0;
    //s=g=m1,t=a,m0=im,m1=ims
    //calc inv_gcd(m0,m1)
    if(a){
      ll ims=1;
      while(a){
        ll u=g/a;
        g-=a*u;
        im-=ims*u;
        auto tmp=g;g=a;a=tmp;
        tmp=im;im=ims;ims=tmp;
      }
      if(im<0)im+=m1/g;
    }
    ll u1=(m1/g);
    if((r1-r0)%g)return {0,0};
    ll x=(r1-r0)/g%u1*im%u1;
    r0+=x*m0;
    m0*=u1;
    if(r0<0)r0+=m0;
  }
  return {r0,m0};
}
ll N,M,K;
int main(){
  startupcpp();
  // int codeforces;cin>>codeforces;while(codeforces--){
  ll i,j;
  cin>>N>>M>>K;
  vector<pair<int,int>> v(2*max(N,M),pair<int,int>(-1,-1));
  vec eqlis;
  rep(i,N){
    cin>>j;
    v[--j].first=i;
  }
  rep(i,M){
    cin>>j;
    v[--j].second=i;
  }
  for(auto [a,b]:v){
    if(min(a,b)<0)continue;
    auto t=crt({a,b},{N,M});
    if(t.second==0)continue;
    eqlis.emplace_back(t.first);
  }
  vsort(eqlis);
  ll T=lcm(N,M),ok=inf*4,ng=0;
  while(ok-ng>1){
    ll mid=(ok+ng)/2;
    ll cnt=mid/T*eqlis.size();
    cnt+=lower_bound(all(eqlis),mid%T)-eqlis.begin();
    if(mid-cnt>=K)ok=mid;
    else ng=mid;
  }
  print(ok);
}