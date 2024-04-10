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
#define output(v) do{bool f=0;for(auto outi:v){cout<<(f?" ":"")<<outi.first;f=1;}cout<<endl;}while(0)
const ll mod=1000000007;
const ll inf=1LL<<60;
const double PI = acos(-1);
const double eps = 1e-9;
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
}
struct unionfind{
  vec par;
  unionfind(ll N) :par(N){
    ll i;
    rep(i,N)par[i]=i;
   // treesize.resize(N);
   // rep(i,N)treesize[i]=1;
  }
  ll root(ll x){
    ll r;
    if(par[x]==x)return x;
    r=root(par[x]);
    if(par[x]!=r){
    //  treesize[r]+=treesize[x];
     // treesize[x]=0;
      par[x]=r;
    }
    return r;
  }
  void unite(ll x,ll y){
    ll px=root(x);
    ll py=root(y);
    if(px!=py){
      par[px]=py;
//      treesize[py]+=treesize[px];
  //    treesize[px]=0;
    }
  }
  bool parcheck(ll x,ll y){
    ll px=root(x);
    ll py=root(y);
    return px==py;
  }
  void clear(){
    ll i;
    rep(i,(ll)par.size()){
      par[i]=i;
//      treesize[i]=1;
    }
  }
};
int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  ll i,j,N,cnt=0,ans=0,px,py;
  cin>>N;
  vec x(N),y(N),cost(N),ch(N,0),anslist;
  vector<tdata> v(N*(N+1)/2);
  pvec anslists;
  rep(i,N)cin>>x[i]>>y[i];
  rep(i,N){
    cin>>j;
    v[cnt++]=tdata(j,datas(i,i));
  }
  rep(i,N)cin>>cost[i];
  rep(i,N){
    For(j,i+1,N){
      v[cnt].first=(cost[i]+cost[j])*(labs(x[i]-x[j])+labs(y[i]-y[j]));
      v[cnt].second=datas(i,j);
      cnt++;
    }
  }
  vsort(v);
  unionfind tree(N);
  rep(i,v.size()){
    ll a=v[i].second.first;
    ll b=v[i].second.second;
    if(a==b){
      px=tree.root(a);
      if(ch[px])continue;
      ch[px]=1;
      ans+=v[i].first;
      anslist.pb(a);
    }else{
      px=tree.root(a);
      py=tree.root(b);
      if(px==py)continue;
      if(ch[px]&&ch[py])continue;
      tree.unite(px,py);
      if(ch[px]|ch[py])ch[px]=ch[py]=1;
      ans+=v[i].first;
      anslists.pb(datas(a,b));
    }
  }
  cout<<ans<<endl;
  cout<<anslist.size()<<endl;
  i=0;
  vsort(anslist);
  for(auto fi:anslist){
    if(i)cout<<" ";
    cout<<fi+1;
    i=1;
  }
  cout<<endl;
  cout<<anslists.size()<<endl;
  for(auto si:anslists){
    cout<<si.first+1<<" "<<si.second+1<<endl;
  }
  return 0;
}