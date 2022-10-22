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
template<class T,class E> ostream& operator<<(ostream& os,pair<T,E>& p){return os<<"{"<<p.first<<","<<p.second<<"}";}
template<class T> inline bool chmax(T& a,T b){bool x=a<b;if(x)a=b;return x;}
template<class T> inline bool chmin(T& a,T b){bool x=a>b;if(x)a=b;return x;}

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
template <typename T>
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
  T queli(int i){
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
    if(l<0)return queli(r);
    else return queli(r)-queli(l);
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
ll N,M,K,H,W,A,B,C,D;
string s,t;
ll ans;
int main(){
  startupcpp();
  // int codeforces;cin>>codeforces;while(codeforces--){
  ll i,j;
  cin>>N>>s;
  mat g(26);
  vec v(N);
  rep(i,N){
    g[s[i]-'a'].eb(i);
  }
  for(auto x:g){
    K=x.size();
    rep(i,K)v[x[i]]=N-1-x[K-i-1];
  }
  BinaryIndexedTree<ll> bits(N+1);
  rep(i,N){
    ans+=i-bits.queli(v[i]);
    bits.act(v[i],1);
  }
  print(ans);
}