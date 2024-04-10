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
#define output(v) do{bool f=0;for(auto outi:v){cout<<(f?" ":"")<<outi;f=1;}cout<<endl;}while(0)
const ll mod=1000000007;
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
void judgement(int a){
  if(a){
    cout<<"Yes"<<endl;
  }else{
    cout<<"No"<<endl;
  }
  if(a){
    cout<<"YES"<<endl;
  }else{
    cout<<"NO"<<endl;
  }
}

int main(){
  ll i,j,k,N,cnt=1;
  cin>>N;
  pvec v(N);
  vec dp(N,0),group(N);
  rep(i,N){
    cin>>v[i].first;
    v[i].second=i;
  }
  vsort(v);
  dp[0]=dp[1]=inf;
  dp[2]=v[2].first-v[0].first;
  if(N>3)dp[3]=v[3].first-v[0].first;
  if(N>4)dp[4]=v[4].first-v[0].first;
  For(i,5,N){
    dp[i]=min({dp[i-3]+v[i].first-v[i-2].first,dp[i-4]+v[i].first-v[i-3].first,dp[i-5]+v[i].first-v[i-4].first});
  }
  cout<<dp[N-1]<<" ";
  i=N-1;
  while(i>=5){
    brep(j,3){
      if(dp[i]==dp[i-5+j]+v[i].first-v[i-4+j].first){
        rep(k,5-j)group[v[i-k].second]=cnt;
        cnt++;
        i-=5-j;
        break;
      }
    }
  }
//  cout<<i<<endl;
  while(i>=0){
    group[v[i].second]=cnt;
    i--;
  }
  cout<<cnt<<endl;
  //output(dp);
  output(group);
}