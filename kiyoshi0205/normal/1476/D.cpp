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
constexpr ll mod=1000000007;
// constexpr ll mod=998244353;
constexpr ll inf=1LL<<60;
constexpr double eps=1e-9;
const double PI=acos(-1);
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

ll countdigits(ll n,ll k=10){
  ll ans=0;
  while(n){n/=k;ans++;}
  return ans;
}

ll sumdigits(ll n,ll k=10){
  ll ans=0;
  while(n){ans+=n%k;n/=k;}
  return ans;
}
template<typename T> struct segtree{
private:
  int N=1;
  T E;
  using func=function<T(T,T)>;
  func f,g;
  vector<T> tree;
public:
  segtree(){}
  segtree(vector<T>& v,T e,func Merge,func Act):E(e),f(Merge),g(Act){
    int i,K=v.size();
    while(N<K)N<<=1;
    tree.resize(N<<1);
    For(i,N,N+K)tree[i]=v[i-N];
    For(i,N+K,N<<1)tree[i]=E;
    brep1(i,N)tree[i]=f(tree[i<<1],tree[(i<<1)|1]);
  }
  segtree(vector<T>& v,T e,func Merge){*this=segtree(v,e,Merge,Merge);};
  segtree(int N,T e,func F){
    vector<T> res(N,e);
    *this=segtree(res,e,F);
  }
  void action(int i,T a){
    if((i<0)|(i>=N))return;
    i+=N;
    tree[i]=g(tree[i],a);
    while(i>1){
      i>>=1;
      tree[i]=f(tree[i<<1],tree[(i<<1)|1]);
    }
  }
  void input(int i,T a){
    if((i<0)|(i>=N))return;
    tree[i+=N]=a;
    while(i>1){
      i>>=1;
      tree[i]=f(tree[i<<1],tree[(i<<1)|1]);
    }
  }
  T queli(int a,int b){
    if((a>=b)|(a<0)|(b<=0)|(a>=N)|(b>N))return E;
    T l(E),r(E);
    for(a+=N,b+=N;a<b;a>>=1,b>>=1){
      if(a&1)l=f(l,tree[a++]);
      if(b&1)r=f(tree[--b],r);
    }
    return f(l,r);
  }
};

template<typename T>
struct LazySegmentTree{
private:
  using func=function<T(T,T)>;
  func f,g;
  size_t N=1;
  T E;
  vector<T> node,lazy;
  vector<bool> vis;
  void eval(size_t& x){
    if(!vis[x])return;
    node[x]=g(node[x],lazy[x]);
    vis[x]=false;
    if(x<N){
      if(vis[x<<1])lazy[x<<1]=g(lazy[x<<1],lazy[x]);
      else{
        lazy[x<<1]=lazy[x];
        vis[x<<1]=true;
      }
      if(vis[x<<1|1])lazy[x<<1|1]=g(lazy[x<<1|1],lazy[x]);
      else{
        lazy[x<<1|1]=lazy[x];
        vis[x<<1|1]=true;
      }
    }
  }
  void update(size_t& a,size_t& b,T& x,size_t now,size_t l,size_t r){
    eval(now);
    if((b<=l)|(r<=a))return;
    if((a<=l)&(r<=b)){
      vis[now]=true;lazy[now]=x;
      eval(now);
    }else{
      update(a,b,x,now<<1,l,(l+r)>>1);
      update(a,b,x,now<<1|1,(l+r)>>1,r);
      node[now]=f(node[now<<1],node[now<<1|1]);
    }
  }
  T call(size_t& a,size_t &b,size_t now,size_t l,size_t r){
    eval(now);
    if((b<=l)|(r<=a))return E;
    if((a<=l)&(r<=b))return node[now];
    return f(call(a,b,now<<1,l,(l+r)>>1),call(a,b,now<<1|1,(l+r)>>1,r));
  }
public:
  LazySegmentTree(){}
  LazySegmentTree(vector<T>& v,func F,func G,T Ie):f(F),g(G),E(Ie){
    size_t i=v.size();
    while(i){
      N<<=1;i>>=1;
    }
    node.resize(N<<1,E);
    lazy.resize(N<<1);
    vis.resize(N<<1,false);
    for(i=0;i<v.size();i++){
      node[N+i]=v[i];
    }
    for(i=N;i--;){
      node[i]=f(node[i<<1],node[i<<1|1]);
    }
  }
  //do g(p,x). p is all[a,b);
  void update(size_t a,size_t b,T x){
    if(a<b)update(a,b,x,1,0,N);
  }
  //get f(I) I=[a,b);
  T get(size_t a,size_t b){
    return call(a,b,1,0,N);
  }
};
struct unionfind{
  private:
  int maxN;
  vector<int> par,treesize;
  public:unionfind(int N) :maxN(N),par(N),treesize(N,1){
    for(int i=0;i<maxN;++i)par[i]=i;
  }
  int root(int x){
    while(par[x]!=x){
      x=par[x]=par[par[x]];
    }
    return x;
  }
  bool unite(int x,int y){
    x=root(x);
    y=root(y);
    if(x==y)return false;
    if(treesize[x]>treesize[y])swap(x,y);
    par[x]=y;
    treesize[y]+=treesize[x];
    return true;
  }
  bool unite(pair<int,int> v){
    return unite(v.first,v.second);
  }
  bool parcheck(int x,int y){
    return root(x)==root(y);
  }
  bool parcheck(pair<int,int> v){
    return parcheck(v.first,v.second);
  }
  int size(int x){
    return treesize[root(x)];
  }
  void clear(){
    treesize.assign(maxN,1);
    for(int i=0;i<maxN;++i)par[i]=i;
  }
  vector<vector<int>> groups(){
    vector<vector<int>> res(maxN);
    for(int i=0;i<maxN;++i)res[root(i)].eb(i);
    // return res;
    vector<vector<int>> res2;
    for(vector<int> x:res){
      if(x.size())res2.eb(x);
    }
    return res2;
  }
};
ll N,M,K,H,W,A,B,C,D;
string s,t;
ll ans;
int main(){
  startupcpp();
  int codeforces;cin>>codeforces;while(codeforces--){
  ll i,j;
  cin>>N>>s;
  unionfind dsu((N+1)*2);
  rep(i,N){
    if(s[i]=='L')dsu.unite(i+1,N+1+i);
    if(s[i]=='R')dsu.unite(i,N+1+i+1);
  }
  rep(i,N+1)cout<<dsu.size(i)<<" \n"[i==N];
}
}