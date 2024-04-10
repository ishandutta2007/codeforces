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

template <typename T=ll>
struct BinaryIndexedTree{
  int size,bitn=0;
  T I;
  using func=function<T(T,T)>;
  func F;
  vector<T> tree;
  BinaryIndexedTree(int N,T e,func f):size(N+1),I(e),F(f),tree(size,e){}
  BinaryIndexedTree(int N):size(N+1),I(0),F([](T a,T b){return a+b;}),tree(size,0){}
  void act(int i,T x){
    for(++i;i<size;i+=-i&i){
      tree[i]=F(tree[i],x);
    }
  }
  //return F([0,i]);
  T query(int i){
    T res=I;
    for(++i;i>0;i-=-i&i){
      res=F(tree[i],res);
    }
    return res;
  }
  //sum([l,r));
  T sum(int l,int r){
    // if(--l>--r)return 0;
    assert(--l<=--r);
    if(l<0)return query(r);
    else return query(r)-query(l);
  }
  //only(N,+)
  int lower_bound(int x){
    int i=0;
    if(!bitn){
      i=size;bitn=1;
      while(i){
        i>>=1;bitn<<=1;
      }
      i=0;
    }
    for(int k=bitn;k;k>>=1){
      if(i+k<size&&tree[i+k]<x){
        i+=k;
        x-=tree[i];
      }
    }
    return i;
  }
};


tuple<ll,ll,string> solve(string s,char x){
  ll i,N=s.size();
  string nxt;
  vec id;
  rep(i,N){
    if(s[i]==x)id.emplace_back(i);
    else nxt+=s[i];
  }
  ll K=id.size();
  ll L=K,ma=0;
  rep(i,K)ma+=id[i]-i;
  ll now=ma;
  brep(i,K){
    // (id[i]->i)=>(id[i]->i+N-K)
    now-=id[i]-i;
    now+=i+N-K-id[i];
    if(chmax(ma,now))L=i;
  }
  return tuple<ll,ll,string>(L,K-L,nxt);
}

ll calc(string s,string t){
  if(s.size()!=t.size())return -1;
  ll i,N=s.size();
  pvec a(N),b(N);
  rep(i,N)a[i]=datas(s[i],i);
  rep(i,N)b[i]=datas(t[i],i);
  vsort(a);
  vsort(b);
  vec p(N);
  rep(i,N){
    if(a[i].first!=b[i].first)return -1;
    p[a[i].second]=b[i].second;
  }
  BinaryIndexedTree tree(N+1);
  ll ans=0;
  rep(i,N){
    ans+=i-tree.query(p[i]);
    tree.act(p[i],1);
  }
  return ans;
}
int main(){
  startupcpp();
int codeforces;cin>>codeforces;while(codeforces--){
  string fs;
  cin>>fs;
  string ord="ANOT";

  ll ansval=0;
  string ans=fs;
  do{
    ll i=0,j=fs.size()-1,A,B,T;
    string s=fs,ret=fs;
    rep(T,4){
      tie(A,B,s)=solve(s,ord[T]);
      while(A--)ret[i++]=ord[T];
      while(B--)ret[j--]=ord[T];
    }
    if(chmax(ansval,calc(fs,ret)))ans=ret;
    assert(s.empty()&&j+1==i);
  }while(next_permutation(all(ord)));
  print(ans);
}
}