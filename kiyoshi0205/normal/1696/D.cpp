#ifdef DEBUG
#include"stdlibrary.h"
#else
#pragma GCC target("avx")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
using namespace std;
#endif
// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>
// #include<ext/pb_ds/tag_and_trait.hpp>
// using namespace __gnu_pbds;
// #include<boost/multiprecision/cpp_int.hpp>
// namespace multiprecisioninteger = boost::multiprecision;
// using cint=multiprecisioninteger::cpp_int;
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
  cin.tie(0)->sync_with_stdio(0);
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
  if(n<r||r<0)return 0;
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
template<class S,S(*op)(S,S),S(*e)()>struct segtree{
public:
  segtree():segtree(0){}
  segtree(int n):segtree(vector<S>(n,e())){}
  segtree(const vector<S>& v):_n(int(v.size())){
    log=0;
    while((1U<<log)<(unsigned int)(_n))++log;
    size=1<<log;
    d=vector<S>(size<<1,e());
    for(int i=0;i<_n;++i)d[size+i]=v[i];
    for(int i=size-1;i>=1;--i)update(i);
  }

  void set(int p,S x){
    assert(0<=p&&p<_n);
    p+=size;
    d[p]=x;
    for(int i=1;i<=log;++i)update(p>>i);
  }

  S get(int p){
    assert(0<=p&&p<_n);
    return d[p+size];
  }

  S prod(int l,int r){
    assert(0<=l&&l<=r&&r<=_n);
    S sml=e(),smr=e();
    l+=size;
    r+=size;

    while(l<r){
      if(l&1)sml=op(sml,d[l++]);
      if(r&1)smr=op(d[--r],smr);
      l>>=1;
      r>>=1;
    }
    return op(sml,smr);
  }

  S all_prod(){return d[1];}

  template<bool(*f)(S)>int max_right(int l){
    return max_right(l,[](S x){return f(x);});
  }
  template<class F>int max_right(int l,F f){
    assert(0<=l&&l<=_n);
    assert(f(e()));
    if(l==_n)return _n;
    l+=size;
    S sm=e();
    do{
      while(~l&1)l>>=1;
      if(!f(op(sm,d[l]))){
        while(l<size){
          l<<=1;
          if(f(op(sm,d[l]))){
            sm=op(sm,d[l++]);
          }
        }
        return l-size;
      }
      sm=op(sm,d[l++]);
    }while((l&-l)!=l);
    return _n;
  }

  template<bool(*f)(S)>int min_left(int r){
    return min_left(r,[](S x){return f(x);});
  }
  template<class F>int min_left(int r,F f){
    assert(0<=r&&r<=_n);
    assert(f(e()));
    if(r==0)return 0;
    r+=size;
    S sm=e();
    do{
      --r;
      while(r>1&&(r&1))r>>=1;
      if(!f(op(d[r],sm))){
        while(r<size){
          r=r<<1|1;
          if(f(op(d[r],sm))){
            sm=op(d[r--],sm);
          }
        }
        return r+1-size;
      }
      sm=op(d[r],sm);
    }while((r&-r)!=r);
    return 0;
  }

private:
  int _n,size,log;
  vector<S> d;

  void update(int k){d[k]=op(d[k<<1],d[k<<1|1]);}
};
struct S{
  ll miv,miid,mav,maid;
};
S op(S l,S r){
  S res;
  if(l.miv<=r.miv){
    res.miv=l.miv;
    res.miid=l.miid;
  }else{
    res.miv=r.miv;
    res.miid=r.miid;
  }
  if(l.mav>=r.mav){
    res.mav=l.mav;
    res.maid=l.maid;
  }else{
    res.mav=r.mav;
    res.maid=r.maid;
  }
  return res;
}
S e(){return {inf,-1,-inf,-1};};
// #include<atcoder/all>
// using mint=atcoder::modint998244353;
// void operator>>(istream& is,mint& v){long long x;is>>x;v=x;}
// ostream& operator<<(ostream& os,const mint& v){return os<<v.val();}

ll N,M,K,H,W,A,B,C,D;
string s,t;
ll ans;
int main(){
  startupcpp();
int codeforces;cin>>codeforces;while(codeforces--){
  ll i,j;
  cin>>N;
  segtree<S,op,e> seg(N);
  vec p(N);
  rep(i,N){
    cin>>p[i];
    seg.set(i,{p[i],i,p[i],i});
  }
  ans=0;
  ll now=0;
  while(now<N-1){
    if(p[now]<p[now+1]){
      ll id=seg.max_right(now,[&](S x){return x.miv>=p[now];});
      S x=seg.prod(now,id);
      now=x.maid;
      ++ans;
    }else{
      ll id=seg.max_right(now,[&](S x){return x.mav<=p[now];});
      S x=seg.prod(now,id);
      now=x.miid;
      ++ans;
    }
  }
  print(ans);
}
}