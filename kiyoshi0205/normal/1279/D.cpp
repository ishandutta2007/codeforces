#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using datas=pair<ll,ll>;
using ddatas=pair<double,double>;
using tdata=pair<ll,datas>;
using vec=vector<ll>;
using mat=vector<vec>;
using pvec=vector<datas>;
using pmat=vector<pvec>;
#define For(i,a,b) for(i=a;i<(ll)b;i++)
#define bFor(i,a,b) for(i=a;i>=(ll)b;i--)
#define rep(i,N) For(i,0,N)
#define rep1(i,N) For(i,1,N)
#define brep(i,N) bFor(i,N-1,0)
#define all(v) (v).begin(),(v).end()
#define allr(v) (v).rbegin(),(v).rend()
#define vsort(v) sort(all(v))
#define vrsort(v) sort(allr(v))
#define endl "\n"
#define pb push_back
#define print(v) cout<<v<<endl
#define printyes cout<<"Yes"<<endl
#define printno cout<<"No"<<endl
#define printYES cout<<"YES"<<endl
#define printNO cout<<"NO"<<endl
#define output(v) do{bool f=0;for(auto outi:v){cout<<(f?" ":"")<<outi;f=1;}cout<<endl;}while(0)
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

double distance(ddatas& x,ddatas& y){
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
  while(n){
    if(n&1)res=res*a%mod;
    a=a*a%mod;
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
int main(){
  ll i,j,N,M,K,ans=0;
  cin>>N;
  K=N*N%mod;
  mat v(N);
  vec inv(N);
  map<ll,ll> mp;
  rep(i,N){
    cin>>M;
    v[i].resize(M);
    inv[i]=modinv(K*M%mod);
    rep(j,M){
      cin>>v[i][j];
      mp[v[i][j]]++;
    }
  }
  rep(i,N){
    K=0;
    for(auto x:v[i]){
      K+=mp[x];
    }
    ans+=K*inv[i];
    ans%=mod;
  }
  print(ans);
}