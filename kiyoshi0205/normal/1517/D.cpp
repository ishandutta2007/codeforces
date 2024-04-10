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

int N,M,K,yoko[500][500],tate[500][500],dp[20][500][500];
int main(){
  startupcpp();
  cin>>N>>M>>K;
  if(K&1){
    mat ans(N,vec(M,-1));
    matoutput(ans);
    return 0;
  }
  K/=2;
  for(int i=0;i<N;++i)for(int j=0;j<M-1;++j)cin>>yoko[i][j];
  for(int i=0;i<N-1;++i)for(int j=0;j<M;++j)cin>>tate[i][j];
  for(int k=0;k<K;++k)for(int i=0;i<N;++i)for(int j=0;j<M;++j)dp[k+1][i][j]=mod;
  for(int k=0;k<K;++k)for(int i=0;i<N;++i)for(int j=0;j<M;++j){
    if(i)chmin(dp[k+1][i-1][j],dp[k][i][j]+tate[i-1][j]);
    if(i<N-1)chmin(dp[k+1][i+1][j],dp[k][i][j]+tate[i][j]);
    if(j)chmin(dp[k+1][i][j-1],dp[k][i][j]+yoko[i][j-1]);
    if(j<M-1)chmin(dp[k+1][i][j+1],dp[k][i][j]+yoko[i][j]);
    // fill(ch[0],ch[0]+400,mod);
    // ch[0][210]=0;
    // for(int k=0;k<K;++k){
    //   fill(ch[1],ch[1]+400,mod);
    //   for(int a=-k;a<=k;++a)for(int b=-k;b<=k;++b){
    //     int x=i+a,y=j+b;
    //     if(x<0||x>N||y<0||y>M)continue;
    //     int now=(a+10)*20+b+10;
    //     if(ch[0][now]==mod)continue;
    //     if(x>0)chmin(ch[1][now-20],ch[0][now]+tate[x-1][y]);
    //     if(x<N-1)chmin(ch[1][now+20],ch[0][now]+tate[x][y]);
    //     if(y>0)chmin(ch[1][now-1],ch[0][now]+yoko[x][y-1]);
    //     if(y<M-1)chmin(ch[1][now+1],ch[0][now]+yoko[x][y]);
    //   }
    //   swap(ch[0],ch[1]);
    // }
    // cout<<*min_element(ch[0],ch[0]+400)*2<<" \n"[j==M-1];
  }
  int i,j;
  mat ans(N,vec(M));
  rep(i,N)rep(j,M)ans[i][j]=dp[K][i][j]*2;
  matoutput(ans);
}