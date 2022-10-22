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
 
int N;
int q(int a,int b,int c){
  assert(a!=b&&b!=c&&c!=a);
  assert(0<=a&&a<N);
  assert(0<=b&&b<N);
  assert(0<=c&&c<N);
  cout<<"? ";
  vec v={a+1,b+1,c+1};
  output(v);
  cin>>a;
  return !a;
}
int main(){
int codeforces;cin>>codeforces;while(codeforces--){
  cin>>N;
  int id[2]={-1,-1};
  vector<int> ans(N,-1);
  vector<int> preans(N/3);
  for(int i=0;i<N/3;++i){
    preans[i]=q(i*3,i*3+1,i*3+2);
    id[preans[i]]=i*3;
  }
  assert(min(id[0],id[1])>-1);

  int qlis[4]={q(id[0],id[1],id[0]+1),
                  q(id[0],id[1],id[0]+2),
                  q(id[0],id[1],id[1]+1),
                  q(id[0],id[1],id[1]+2)};

  //,
  int a=0,b=0;
  if(qlis[0]==qlis[1]&&qlis[1]==qlis[2]&&qlis[2]==qlis[3]){
    ans[id[0]]=ans[id[1]]=qlis[0];
    a=id[qlis[0]],b=id[!qlis[0]];
    ans[b+1]=ans[b+2]=!qlis[0];
    ++b;
    ans[a+1]=q(a,b,a+1);
    ans[a+2]=q(a,b,a+2);
    if(ans[a])swap(a,b);
  }else{
    ans[id[0]+1]=qlis[0];
    ans[id[0]+2]=qlis[1];
    ans[id[1]+1]=qlis[2];
    ans[id[1]+2]=qlis[3];
    for(auto x:{id[0],id[0]+1,id[0]+2,id[1],id[1]+1,id[1]+2}){
      if(ans[x]==0)a=x;
      if(ans[x]==1)b=x;
    }
    ans[id[0]]=q(a,b,id[0]);
    ans[id[1]]=q(a,b,id[1]);
  }
  for(int i=0;i<N/3;++i){
    if(ans[i*3]>=0)continue;
    if(preans[i]){
      //->
      if(q(i*3,i*3+1,a)){
        //
        ans[i*3]=ans[i*3+1]=1;
        ans[i*3+2]=q(a,b,i*3+2);
      }else{
        //
        ans[i*3+2]=1;
        ans[i*3]=q(a,b,i*3);
        ans[i*3+1]=!ans[i*3];
      }
    }else{
      //->
      if(!q(i*3,i*3+1,b)){
        //
        ans[i*3]=ans[i*3+1]=0;
        ans[i*3+2]=q(a,b,i*3+2);
      }else{
        //
        ans[i*3+2]=0;
        ans[i*3]=q(a,b,i*3);
        ans[i*3+1]=!ans[i*3];
      }
    }
  }
  vector<int> pr;
  for(int i=0;i<N;++i){
    assert(ans[i]>=0);
    if(ans[i])pr.emplace_back(i+1);
  }
  cout<<"! "<<pr.size()<<" ";
  output(pr);
}
}