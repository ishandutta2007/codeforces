#pragma GCC optimize("Ofast")
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
#define For(i,a,b) for(i=a;i<(ll)b;i++)
#define bFor(i,b,a) for(i=b-1;i>=(ll)a;i--)
#define rep(i,N) For(i,0,N)
#define rep1(i,N) For(i,1,N)
#define brep(i,N) bFor(i,N,0)
#define all(v) (v).begin(),(v).end()
#define allr(v) (v).rbegin(),(v).rend()
#define vsort(v) sort(all(v))
#define vrsort(v) sort(allr(v))
#define endl "\n"
#define pb push_back
#define eb emplace_back
#define print(v) cout<<v<<endl
#define printyes cout<<"Yes"<<endl
#define printno cout<<"No"<<endl
#define printYES cout<<"YES"<<endl
#define printNO cout<<"NO"<<endl
#define output(v) do{bool f=0;for(auto outi:v){cout<<(f?" ":"")<<outi;f=1;}cout<<endl;}while(0)
// const ll mod=1000000007;
const ll mod=998244353;
const ll inf=1LL<<60;
const double PI = acos(-1);
const double eps = 1e-9;
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

ll modinv(ll a) {
  ll b=mod,u=1,v=0,t;
  while(b){
    t=a/b;
    a-=t*b; swap(a,b);
    u-=t*v; swap(u,v);
  }
  return (u+mod)%mod;
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

ll modpow(ll a,ll n){
  ll res=1;
  while(n>0){
    if(n&1)res=res*a;
    a=a*a;
    n>>=1;
  }
  return res;
}

ll gcd(ll a,ll b){if(!b)return a;return (a%b==0)?b:gcd(b,a%b);}
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
pvec primefactorization(ll N){
  ll i=2;
  pvec res;
  while(i*i<=N){
    if(!(N%i)){
      res.eb(i,1);
      N/=i;
      while(!(N%i)){
        ++res[(int)res.size()-1].second;
        N/=i;
      }
    }
    i++;
  }
  if(N!=1)res.eb(N,1);
  return res;
}
ll counting(pvec v){
  ll res=1;
  for(auto x:v)res*=modpow(x.first,x.second);
  return res;
}
map<ll,ll> vis;
map<ll,pvec> mp;
void start(pvec v){
  ll i,res=counting(v);
  if(vis[res]++)return;
  mp[res]=v;
  rep(i,v.size()){
    if(v[i].second){
      --v[i].second;
      start(v);
      ++v[i].second;
    }
  }
}
int main(){
  startupcpp();
  // maxN=890488576177200;
  ll i,N,K,Q,a,b,c,cnt,ans;
  cin>>N>>Q;
  pvec v=primefactorization(N);
  K=v.size();
  start(v);
  while(Q--){
    cin>>a>>b;
    c=gcd(a,b);
    pvec pra=mp[a],prb=mp[b],prc=mp[c];
    ans=1;
    cnt=0;
    rep(i,K){
      if(pra[i].second>prc[i].second)cnt+=pra[i].second-prc[i].second;
    }
    rep(i,K){
      (ans*=modncr(cnt,pra[i].second-prc[i].second))%=mod;
      cnt-=pra[i].second-prc[i].second;
    }
    cnt=0;
    rep(i,K){
      if(prb[i].second>prc[i].second)cnt+=prb[i].second-prc[i].second;
    }
    rep(i,K){
      (ans*=modncr(cnt,prb[i].second-prc[i].second))%=mod;
      cnt-=prb[i].second-prc[i].second;
    }
    print(ans);
  }
}