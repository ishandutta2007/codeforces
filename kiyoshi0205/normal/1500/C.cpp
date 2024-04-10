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

struct segtree{
private:
  int N=1;
  vector<ll> tree;
public:
  segtree(){}
  segtree(vector<ll>& v){
    int i,K=v.size();
    while(N<K)N<<=1;
    tree.resize(N<<1);
    For(i,N,N+K)tree[i]=v[i-N];
    For(i,N+K,N<<1)tree[i]=inf;
    brep1(i,N)tree[i]=min(tree[i<<1],tree[(i<<1)|1]);
  }
  ll prod(int a,int b){
    if((a>=b)|(a<0)|(b<=0)|(a>=N)|(b>N))return inf;
    ll l(inf),r(inf);
    for(a|=N,b+=N;a<b;a>>=1,b>>=1){
      if(a&1)l=min(l,tree[a++]);
      if(b&1)r=min(tree[--b],r);
    }
    return min(l,r);
  }
};

ll N,M;
mat a,b;
vec ans;
void manup(ll id){
  vector<datas> t(N);
  ll i;
  rep(i,N)t[i]=datas(a[i][id],i);
  vsort(t);
  mat next(N);
  rep(i,N)swap(a[t[i].second],next[i]);
  swap(a,next);
}
int main(){
  startupcpp();
  // int codeforces;cin>>codeforces;while(codeforces--){
  ll i,j;
  cin>>N>>M;
  a.resize(N,vec(M));
  b.resize(N,vec(M));
  rep(i,N)rep(j,M)cin>>a[i][j];
  rep(i,N)rep(j,M)cin>>b[i][j];
  vec sortchecksum(M,0);
  queue<ll> pque,sque;
  rep(j,M){
    rep(i,N-1){
      if(b[i][j]>b[i+1][j])sortchecksum[j]++;
    }
    if(!sortchecksum[j])pque.emplace(j);
  }
  vec sorted(M,0),parted(N-1,0);
  while(pque.size()){
    //part and check
    while(!pque.empty()){
      auto now=pque.front();pque.pop();
      if(!chmax(sorted[now],1LL))continue;
      ans.emplace_back(now+1);
      rep(i,N-1)if(b[i][now]<b[i+1][now])sque.emplace(i);
    }
    //sort check and nextpart check
    while(!sque.empty()){
      auto now=sque.front();sque.pop();
      if(!chmax(parted[now],1LL))continue;
      rep(j,M){
        if(b[now][j]>b[now+1][j]){
          if(--sortchecksum[j]==0)pque.emplace(j);
        }
      }
    }
  }
  reverse(all(ans));
  for(auto x:ans)manup(x-1);
  if(a==b){
    print(ans.size());
    output(ans);
  }else print(-1);
}