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
template<class S,
      S(*op)(S,S),
      S(*e)(),
      class F,
      S(*mapping)(S,F),
      F(*composition)(F,F),
      F(*id)()>
struct lazy_segtree{
public:
  lazy_segtree():lazy_segtree(0){}
  lazy_segtree(int n):lazy_segtree(vector<S>(n,e())){}
  lazy_segtree(const vector<S>& v):_n(int(v.size())){
    log=0;
    while((1U<<log)<(unsigned int)(_n))++log;
    size=1<<log;
    d=vector<S>(size<<1,e());
    lz=vector<F>(size,id());
    for(int i=0;i<_n;++i)d[size+i]=v[i];
    for(int i=size-1;i>=1;--i){
      update(i);
    }
  }
 
  void set(int p,S x){
    assert(0<=p&&p<_n);
    p+=size;
    for(int i=log;i>=1;--i)push(p>>i);
    d[p]=x;
    for(int i=1;i<=log;++i)update(p>>i);
  }
 
  S get(int p){
    assert(0<=p&&p<_n);
    p+=size;
    for(int i=log;i>=1;--i)push(p>>i);
    return d[p];
  }
 
  S prod(int l,int r){
    assert(0<=l&&l<=r&&r<=_n);
    if(l==r)return e();
 
    l+=size;
    r+=size;
 
    for(int i=log;i>=1;--i){
      if(((l>>i)<<i)!=l)push(l>>i);
      if(((r>>i)<<i)!=r)push(r>>i);
    }
 
    S sml=e(),smr=e();
    while(l<r){
      if(l&1)sml=op(sml,d[l++]);
      if(r&1)smr=op(d[--r],smr);
      l>>=1;
      r>>=1;
    }
 
    return op(sml,smr);
  }
 
  S all_prod(){return d[1];}
 
  void apply(int p,F f){
    assert(0<=p&&p<_n);
    p+=size;
    for(int i=log;i>=1;--i)push(p>>i);
    d[p]=mapping(d[p],f);
    for(int i=1;i<=log;++i)update(p>>i);
  }
  void apply(int l,int r,F f){
    assert(0<=l&&l<=r&&r<=_n);
    if(l==r)return;
 
    l+=size;
    r+=size;
 
    for(int i=log;i>=1;--i){
      if(((l>>i)<<i)!=l)push(l>>i);
      if(((r>>i)<<i)!=r)push((r-1)>>i);
    }
 
    {
      int l2=l,r2=r;
      while(l<r){
        if(l&1)all_apply(l++,f);
        if(r&1)all_apply(--r,f);
        l>>=1;
        r>>=1;
      }
      l=l2;
      r=r2;
    }
 
    for(int i=1;i<=log;++i){
      if(((l>>i)<<i)!=l)update(l>>i);
      if(((r>>i)<<i)!=r)update((r-1)>>i);
    }
  }
 
  template<bool(*g)(S)>int max_right(int l){
    return max_right(l,[](S x){return g(x);});
  }
  template<class G>int max_right(int l,G g){
    assert(0<=l&&l<=_n);
    assert(g(e()));
    if(l==_n)return _n;
    l+=size;
    for(int i=log;i>=1;--i)push(l>>i);
    S sm=e();
    do{
      while(~l&1)l>>=1;
      if(!g(op(sm,d[l]))){
        while(l<size){
          push(l);
          l<<=1;
          if(g(op(sm,d[l]))){
            sm=op(sm,d[l++]);
          }
        }
        return l-size;
      }
      sm=op(sm,d[l++]);
    }while((l&-l)!=l);
    return _n;
  }
 
  template<bool(*g)(S)>int min_left(int r){
    return min_left(r,[](S x){return g(x);});
  }
  template<class G>int min_left(int r,G g){
    assert(0<=r&&r<=_n);
    assert(g(e()));
    if(r==0)return 0;
    r+=size;
    for(int i=log;i>=1;--i)push((r-1)>>i);
    S sm=e();
    do{
      --r;
      while(r>>1&&(r&1))r>>=1;
      if(!g(op(d[r],sm))){
        while(r<size){
          push(r);
          r=r<<1|1;
          if(g(op(d[r],sm))){
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
  vector<F> lz;
 
  void update(int k){d[k]=op(d[k<<1],d[k<<1|1]);}
  void all_apply(int k,F f){
    d[k]=mapping(d[k],f);
    if(k<size)lz[k]=composition(lz[k],f);
  }
  void push(int k){
    all_apply(k<<1,lz[k]);
    all_apply(k<<1|1,lz[k]);
    lz[k]=id();
  }
};
struct S{
  ll cnt[2];ll ans;
};
S eS(){return {};}
bool e(){return false;}
S f(S a,S b){
  a.ans+=b.ans+a.cnt[1]*b.cnt[0];
  a.cnt[0]+=b.cnt[0];
  a.cnt[1]+=b.cnt[1];
  return a;
}
S g(S a,bool b){
  if(!b)return a;
  swap(a.cnt[0],a.cnt[1]);
  a.ans=a.cnt[0]*a.cnt[1]-a.ans;
  return a;
}
bool h(bool a,bool b){
  return a^b;
}
ll A,B;
ll calc(S x){
  return A*(x.cnt[0]*x.cnt[1]-x.ans)+B*x.ans;
}

int main(){
  startupcpp();
  // int codeforces;cin>>codeforces;while(codeforces--){
  ll i,N;
  string s;
  cin>>s>>A>>B;
  N=s.size();
  vec ch;
  vector<S> v;
  rep(i,N){
    S x=eS();
    if(s[i]=='?'){
      ch.eb(i);
      x.cnt[0]++;
    }else{
      x.cnt[s[i]&1]++;
    }
    v.eb(x);
  }
  lazy_segtree<S,f,eS,bool,g,h,e> tree(v);
  ll ans=calc(tree.all_prod());
  for(auto x:ch){
    tree.apply(x,x+1,true);
    chmin(ans,calc(tree.all_prod()));
  }
  for(auto x:ch){
    tree.apply(x,x+1,true);
    chmin(ans,calc(tree.all_prod()));
  }
  print(ans);
  // }
}