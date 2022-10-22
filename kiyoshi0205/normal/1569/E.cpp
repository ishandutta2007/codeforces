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
// constexpr ll mod=1000000007;
constexpr ll mod=998244353;
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

vector<int> sumlis(vector<int>& v){
  assert(v.size()==8);
  vector<int> res(256);
  for(int i=0;i<256;++i){
    int tmp=0;
    for(int j=0;j<8;++j){
      if(i>>j&1){
        tmp+=v[j];
        if(tmp>=mod)tmp-=mod;
      }
    }
    res[i]=tmp;
  }
  vsort(res);
  return res;
}

ll powA[18]={1};
int main(){
  startupcpp();
  ll K,A,H,N;
  cin>>K>>A>>H;
  N=1<<K;
  powA[1]=A;
  for(int i=2;i<18;++i)powA[i]=powA[i-1]*A%mod;
  if(K<=4){
    vector<vector<int>> plis={{1}};
    int i;
    rep(i,K){
      int bit,j,sz=1<<i;
      vector<vector<int>> nxtplis;
      vector<int> nxtp(sz*2);
      for(auto p:plis){
        rep(j,sz){
          nxtp[j*2]=p[j];
          nxtp[j*2+1]=sz+1;
        }
        rep(bit,1<<sz){
          rep(j,sz)if(bit>>j&1)swap(nxtp[j*2],nxtp[j*2+1]);
          nxtplis.emplace_back(nxtp);
          rep(j,sz)if(bit>>j&1)swap(nxtp[j*2],nxtp[j*2+1]);
        }
      }
      swap(plis,nxtplis);
    }
    debug(plis.size());
    for(auto p:plis){
      ll t=0;
      rep(i,N)t+=powA[p[i]]*(i+1);
      if(t%mod==H){
        output(p);
        return 0;
      }
    };
    print(-1);
    return 0;
  }
  vector<vector<int>> plis={{1}};
  int i;
  rep(i,4){
    int bit,j,sz=1<<i;
    vector<vector<int>> nxtplis;
    vector<int> nxtp(sz*2);
    for(auto p:plis){
      rep(j,sz){
        nxtp[j*2]=p[j];
        nxtp[j*2+1]=sz+1;
      }
      rep(bit,1<<sz){
        rep(j,sz)if(bit>>j&1)swap(nxtp[j*2],nxtp[j*2+1]);
        nxtplis.emplace_back(nxtp);
        rep(j,sz)if(bit>>j&1)swap(nxtp[j*2],nxtp[j*2+1]);
      }
    }
    swap(plis,nxtplis);
  }
  debug(plis.size());
  for(auto p:plis){
    ll t=0;
    vector<int> v1(8),v2(8);
    rep(i,16){
      t+=powA[p[i]]*(i*2+1)+powA[17]*(i*2+2);
      int tmp=powA[p[i]]-powA[17];
      if(tmp<0)tmp+=mod;
      (i<8?v1:v2)[i&7]=tmp;
    }
    t=H-t%mod;
    if(t<0)t+=mod;
    auto s=sumlis(v1);
    for(auto x:sumlis(v2)){
      int tmp=t-x;
      if(tmp<0)tmp+=mod;
      auto itr=lower_bound(all(s),tmp);
      if(itr!=s.end()&&*itr==tmp){
        //found
        vector<int> ans;
        for(auto x:p){
          ans.emplace_back(x);
          ans.emplace_back(p.size()+1);
        }
        for(int bit=0;bit<(1<<p.size());++bit){
          for(size_t j=0;j<p.size();++j)if(bit>>j&1)swap(ans[j*2],ans[j*2+1]);
          t=0;
          rep(i,32)t+=powA[ans[i]]*(i+1);
          if(t%mod==H){
            output(ans);
            return 0;
          }
          for(size_t j=0;j<p.size();++j)if(bit>>j&1)swap(ans[j*2],ans[j*2+1]);
        }
        assert(false);
      }
    }
  };
  print(-1);
  return 0;
}