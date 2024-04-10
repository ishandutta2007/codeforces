#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>
// #include<ext/pb_ds/tag_and_trait.hpp>
// using namespace __gnu_pbds;
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
struct unionfind{
  vec par,treesize;
  unionfind(ll N) :par(N){
    ll i;
    rep(i,N)par[i]=i;
    treesize.resize(N,1);
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
  bool unite(ll x,ll y){
    ll px=root(x);
    ll py=root(y);
    if(px!=py){
      par[px]=py;
      treesize[py]+=treesize[px];
      treesize[px]=0;
    }
    return px!=py;
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
vec diviserlist(ll N,ll K){
  ll i;
  vec res;
  for(i=1;i*i<N&&i<K;i++){
    if(N%i==0){
      res.pb(i);
      if(N/i<K)res.pb(N/i);
    }
  }
  if(i*i==N&&i<K)res.pb(i);
  vsort(res);
  return res;
}
int main(){
  // startupcpp();
  ll test;cin>>test;while(test--){
  ll i,j,N,ans=inf;
  cin>>N;
  unionfind color(N*2);
  vec v(N),ord(N,-1);
  rep(i,N){
    cin>>v[i];
    v[i]--;
  }
  rep(i,N){
    cin>>j;
    color.unite(i,N+j-1);
  }
  rep(i,N){
    if(ord[i]==-1){
      ord[i]=0;
      j=i;
      vec g(1,i);
      while(v[j]!=i){
        ord[v[j]]=ord[j]+1;
        j=v[j];
        g.pb(j);
      }
      chmin(ans,(ll)g.size());
      vec prime=diviserlist(g.size(),ans);
      for(ll x:prime){
        vec ch(g.size(),1);
        For(j,x,g.size())ch[j]=ch[j-x]&&color.parcheck(g[j-x],g[j]);
        rep(j,x)if(ch[(int)g.size()-j-1])break;
        if(j!=x){
          ans=x;
          break;
        }
      }
    }
  }
  print(ans);
}return 0;
}