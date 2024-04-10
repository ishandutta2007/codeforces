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
#define endl "\n"
#define eb emplace_back
#define print(v) cout<<v<<endl
#define printyes cout<<"Yes"<<endl
#define printno cout<<"No"<<endl
#define printYES cout<<"YES"<<endl
#define printNO cout<<"NO"<<endl
#define output(v) do{bool f=0;for(auto outi:v){cout<<(f?" ":"")<<outi;f=1;}cout<<endl;}while(0)
#define matoutput(v) do{for(auto outimat:v)output(outimat);}while(0)
const ll mod=1000000007;
// const ll mod=998244353;
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
struct LazySegmentTree{
  private:
  using func=function<ll(ll,ll)>;
  func f,g;
  ll N=1,E;
  vec node,lazy;
  vector<bool> vis;
  public:LazySegmentTree(vec& v,func F,func G,ll Ie):f(F),g(G),E(Ie){
    ll i=v.size();
    while(i){
      N<<=1;i>>=1;
    }
    node.resize(N*2-1,E);
    lazy.resize(N*2-1);
    vis.resize(N*2-1,false);
    rep(i,v.size()){
      node[N+i-1]=v[i];
    }
    brep(i,N-1){
      node[i]=f(node[i*2+1],node[i*2+2]);
    }
  }
  private:void eval(ll x){
    if(!vis[x])return;
    node[x]=g(node[x],lazy[x]);
    vis[x]=false;
    if(x<N-1){
      if(vis[2*x+1])lazy[2*x+1]=g(lazy[2*x+1],lazy[x]);
      else{
        lazy[2*x+1]=lazy[x];
        vis[2*x+1]=true;
      }
      if(vis[2*x+2])lazy[2*x+2]=g(lazy[2*x+2],lazy[x]);
      else{
        lazy[2*x+2]=lazy[x];
        vis[2*x+2]=true;
      }
    }
  }
  void update(ll a,ll b,ll x,ll now,ll l,ll r){
    eval(now);
    if((b<=l)|(r<=a))return;
    if((a<=l)&(r<=b)){
      vis[now]=true;lazy[now]=x;
      eval(now);
    }else{
      update(a,b,x,now*2+1,l,(l+r)>>1);
      update(a,b,x,now*2+2,(l+r)>>1,r);
      node[now]=f(node[now*2+1],node[now*2+2]);
    }
  }
  //do g(p,x). p is all[a,b);
  public:void update(ll a,ll b,ll x){
    if(a<b)update(a,b,x,0,0,N);
  }
  private:ll call(ll a,ll b,ll now,ll l,ll r){
    eval(now);
    if((b<=l)|(r<=a))return E;
    if((a<=l)&(r<=b))return node[now];
    return f(call(a,b,now*2+1,l,(l+r)>>1),call(a,b,now*2+2,(l+r)>>1,r));
  }
  //get f(I) I=[a,b);
  public:ll get(ll a,ll b){
    return call(a,b,0,0,N);
  }
};
int main(){
  startupcpp();
  int codeforces;cin>>codeforces;while(codeforces--){
  ll i,N,M,a,b,c,u,v,ans=inf;
  cin>>N>>M>>a>>b>>c;
  --a;--b;--c;
  vec da(N,inf),db(N,inf),dc(N,inf),cost(M+1,0);
  rep(i,M)cin>>cost[i+1];
  vsort(cost);
  rep1(i,M+1){
    cost[i]+=cost[i-1];
  }
  mat g(N);
  rep(i,M){
    cin>>u>>v;
    --u;--v;
    g[v].eb(u);
    g[u].eb(v);
  }
  queue<datas> que;
  que.push(datas(0,a));
  while(!que.empty()){
    datas x=que.front();que.pop();
    if(!chmin(da[x.second],x.first))continue;
    for(auto next:g[x.second])que.push(datas(x.first+1,next));
  }
  que.push(datas(0,b));
  while(!que.empty()){
    datas x=que.front();que.pop();
    if(!chmin(db[x.second],x.first))continue;
    for(auto next:g[x.second])que.push(datas(x.first+1,next));
  }
  que.push(datas(0,c));
  while(!que.empty()){
    datas x=que.front();que.pop();
    if(!chmin(dc[x.second],x.first))continue;
    for(auto next:g[x.second])que.push(datas(x.first+1,next));
  }
  rep(i,N){
    if(da[i]+db[i]+dc[i]>M)continue;
    chmin(ans,cost[da[i]+db[i]+dc[i]]+cost[db[i]]);
  }
  print(ans);
 }return 0;
}