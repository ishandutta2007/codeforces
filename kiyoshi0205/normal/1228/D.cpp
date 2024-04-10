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
#define For(i,a,b) for(i=a;i<b;i++)
#define bFor(i,a,b) for(i=a;i>=b;i--)
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
template<class T> inline bool chmax(T& a,T b){bool x=a<b;if(x)a=b;return x;} 
template<class T> inline bool chmin(T& a,T b){bool x=a>b;if(x)a=b;return x;} 

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

set<ll> primefactorization(ll N){
  ll i=2;
  set<ll> res;
  while(i*i<=N){
    while(!(N%i)){
      res.insert(i);
      N/=i;
    }
    i++;
  }
  if(N-1)res.insert(N);
  return res;
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

struct unionfind{
  vec par,treesize;
  unionfind(ll N) :par(N){
    ll i;
    rep(i,N)par[i]=i;
    treesize.resize(N);
    rep(i,N)treesize[i]=1;
  }
  ll root(ll x){
    ll r;
    if(par[x]==x)return x;
    r=root(par[x]);
    if(par[x]!=r){
      treesize[r]+=treesize[x];
      treesize[x]=0;
      par[x]=r;
    }
    return r;
  }
  void unite(ll x,ll y){
    ll px=root(x);
    ll py=root(y);
    if(px!=py){
      par[px]=py;
      treesize[py]+=treesize[px];
      treesize[px]=0;
    }
  }
  bool parcheck(ll x,ll y){
    ll px=root(x);
    ll py=root(y);
    return px==py;
  }
  ll size(ll x){
    ll px=root(x);
    return treesize[px];
  }
  void clear(){
    ll i;
    rep(i,(ll)par.size()){
      par[i]=i;
      treesize[i]=1;
    }
  }
};

int main(){
  ll i,N,M,a,b,cnt=0,scnt=0,tcnt=0;
  cin>>N>>M;
  unionfind tree(N+3);
  vec h(N,0),ans(N,0),ch(N,0);
  mat v(N);
  rep(i,M){
    cin>>a>>b;
    a--;b--;
    v[a].pb(b);
    v[b].pb(a);
    h[a]++;h[b]++;
  }
  set<ll> se;
  rep(i,N)se.insert(h[i]);
  auto itr=se.lower_bound(0);
  if(se.size()>3||!((ll)(*itr))){
    cout<<-1<<endl;
    return 0;
  }
  for(auto i:v[0]){
    ch[i]=1;
    cnt++;
  }
  cnt=N-cnt;
  rep(i,N){
    ans[i]=ch[i]^1;
    ch[i]=0;
    if(ans[i])tree.unite(i,N);
  }
  i=0;
  while(i<N&&ans[i])i++;
  for(auto j:v[i]){
    ch[j]=1;
  }
  rep(i,N){
    if(ans[i]){
      if(!ch[i]){
        cout<<-1<<endl;
        return 0;
      }
    }else{
      if(ch[i]){
        ans[i]=2;
        tree.unite(i,N+1);
        scnt++;
      }else{
        ans[i]=3;
        tree.unite(i,N+2);
        tcnt++;
      }
    }
  }
  if(cnt*scnt*tcnt==0){
    cout<<-1<<endl;
    return 0;
  }
  rep(i,N){
    for(auto j:v[i]){
      if(tree.parcheck(i,j)){
        cout<<-1<<endl;
        return 0;
      }
    }
  }
  M+=cnt*(cnt-1)/2+scnt*(scnt-1)/2+tcnt*(tcnt-1)/2;
  if(M!=N*(N-1)/2){
    cout<<-1<<endl;
    return 0;
  }
  output(ans);
  return 0;
}