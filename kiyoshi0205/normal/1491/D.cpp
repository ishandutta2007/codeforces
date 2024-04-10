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

long double distance(ddatas x,ddatas y){
  long double a=x.first-y.first,b=x.second-y.second;
  return sqrtl(a*a+b*b);
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
bool check(int A,int B){
  if(A>B)return false;
  if(A==B)return true;
  if(A%2==B%2)return check(A/2,B/2);
  if((B&1)||sumdigits(A,2)<sumdigits(B,2))return false;
  int ch=(A+1)&(-A-1);
  --ch;ch&=B;
  return check(A,B);
}
bool judge(int A,int B){
  if(A>B)return false;
  if(A==B)return true;
  for(int bit=A;bit;bit=(bit-1)&A){
    if(judge(A+bit,B))return true;
  }
  return false;
}
ll N,M,K,H,W,C,D;
string t;
ll ans;
bool solve(ll A,ll B){
  if(A>B)return false;
  debug(A,B);
  if(A==B)return true;
  if(A%2==B%2)return solve(A/2,B/2);
  if((B&1)||sumdigits(A,2)<sumdigits(B,2))return false;
  ll C=countdigits(B,2);
  if(A&(1<<(C-1)))return solve(A^(1<<(C-1)),B^(1<<(C-1)));
  ll i,j=sumdigits(B,2);
  brep(i,C){
    if(sumdigits(A,2)==j-1)break;
    if(A>>i&1)A^=1<<i;
  }
  B^=1<<(C-1);
  return solve(A,B);
  // ll i,j=sumdigits(B,2);
  // if(A>B||sumdigits(A,2)<j){
  //   return false;
  // }
  // if(sumdigits(A,2)>j){
  //   C=countdigits(A,2);
  //   int nowcnt=j;
  //   brep(i,C){
  //     if(A>>i&1){
  //       --nowcnt;
  //       if(nowcnt==0){
  //         break;
  //       }
  //     }
  //   }
  //   //0indexed iAbitcount=Bbitcount
  //   if(C-i==j){
  //     A+=1<<C;
  //     brep(i,C){
  //       if(sumdigits(A,2)==j)break;
  //       if(A>>i&1)A^=1<<i;
  //     }
  //   }else{
  //     assert(A>>i&1);
  //     D=A+(1<<i);
  //     while(sumdigits(D,2)<j){
  //       D|=1<<i;
  //       i++;
  //     }
  //     while(sumdigits(D,2)>j){
  //       if(D>>i&1)D^=1<<i;
  //       i--;
  //     }
  //     A=D;
  //   }
  // }
  // if(A>B)return false;
  // assert(sumdigits(A,2)==sumdigits(B,2));
  // bool f=true;
  // while(A&&B&&f){
  //   if((A&-A)>(B&-B))return false;
  //   A-=A&-A;
  //   B-=B&-B;
  // }
  // return true;
}
int main(){
  // startupcpp();
  ll A,B;
  // solve(2,4);
  // return 0;
  // rep(A,20)rep(B,20){
  //   debug(A+1,B+1);
  //   if(solve(A+1,B+1)!=judge(A+1,B+1)){debug(A+1,B+1,judge(A+1,B+1));return 0;}
  // }
  // return 0;
  int codeforces;cin>>codeforces;while(codeforces--){
    cin>>A>>B;
    if(solve(A,B))printYES;
    else printNO;
  }
}