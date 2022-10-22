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
#define uniq(v) (v).erase(unique(all(v)),(v).end())
#define endl "\n"
#define eb emplace_back
#define print(x) cout<<x<<endl
#define printyes print("Yes")
#define printno print("No")
#define printYES print("YES")
#define printNO print("NO")
#define output(v) do{bool f=0;for(auto outi:v){cout<<(f?" ":"")<<outi;f=1;}cout<<endl;}while(0)
#define matoutput(v) do{for(auto outimat:v)output(outimat);}while(0)
const ll mod=1000000007;
// const ll mod=998244353;
const ll inf=1LL<<60;
const double PI=acos(-1);
const double eps=1e-9;
template<class T,class E> ostream& operator<<(ostream& os,pair<T,E>& p){return os<<"("<<p.first<<","<<p.second<<")";}
template<class T> ostream& operator<<(ostream& os,const vector<T>& v){
  os<<"{";ll i;
  rep(i,v.size()){
    if(i)os<<",";
    os<<v[i];
  }
  os<<"}";
  return os;
}
template<class T> inline bool chmax(T& a,T b){bool x=a<b;if(x)a=b;return x;}
template<class T> inline bool chmin(T& a,T b){bool x=a>b;if(x)a=b;return x;}
#ifdef DEBUG
void debugg(){cerr<<endl;}
template<class T,class... Args>void debugg(const T& x,const Args&... args){cerr<<" "<<x;debugg(args...);}
#define debug(...) cerr<<__LINE__<<" ["<<#__VA_ARGS__<<"]:",debugg(__VA_ARGS__)
#else
#define debug(...) (void(0))
#endif

void startupcpp(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout<<fixed<<setprecision(15);
}

double distance(ddatas x,ddatas y){
  double a=x.first-y.first,b=x.second-y.second;
  return sqrt(a*a+b*b);
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
    For(i,size,n+1){
      modncrlistp[i]=modncrlistp[i-1]*i%mod;
      modncrlistm[i]=modinv(modncrlistp[i]);
    }
  }
  return modncrlistp[n]*modncrlistm[r]%mod*modncrlistm[n-r]%mod;
}

ll modpow(ll a,ll n,ll m=mod){
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
struct undounionfind{
  private:
  int maxN;
  vector<int> data;
  vector<pair<int,int>> rev;
  public:undounionfind(int N) :maxN(N),data(N,-1){}
  int root(int x){
    while(data[x]>=0)x=data[x];
    return x;
  }
  bool unite(int x,int y){
    x=root(x);
    y=root(y);
    if(x==y)return false;
    if(data[x]>data[y])swap(x,y);
    rev.emplace_back(x,data[x]);
    rev.emplace_back(y,data[y]);
    data[x]+=data[y];
    data[y]=x;
    return true;
  }
  bool unite(pair<int,int> v){
    return unite(v.first,v.second);
  }
  bool parcheck(int x,int y){
    return root(x)==root(y);
  }
  bool parcheck(pair<int,int> v){
    return parcheck(v.first,v.second);
  }
  int size(int x){
    return -data[root(x)];
  }
  void undo(int time=1){
    assert((time*=2)<=(int)rev.size());
    while(time--){
      data[rev.back().first]=rev.back().second;
      rev.pop_back();
    }
  }
  void allundo(){
    undo(rev.size()/2);
  }
  void snapshot(){
    rev.clear();
  }
  void clear(){
    data.assign(maxN,1);
  }
  vector<vector<int>> groups(){
    vector<vector<int>> res(maxN);
    for(int i=0;i<maxN;++i)res[root(i)].eb(i);
    // return res;
    vector<vector<int>> res2;
    for(vector<int> x:res){
      if(x.size())res2.eb(x);
    }
    return res2;
  }
};
ll N,M,K;
ll ans;
int main(){
  startupcpp();
  // int codeforces;cin>>codeforces;while(codeforces--){
  ll i,j;
  cin>>N>>M>>K;
  ans=K;
  vec col(N);
  rep(i,N){
    cin>>col[i];
    --col[i];
  }
  map<datas,pvec> mp;
  undounionfind dsu(N*2);
  while(M--){
    cin>>i>>j;--i;--j;
    if(col[i]==col[j]){
      dsu.unite(i+N,j);
      dsu.unite(i,j+N);
    }else{
      if(col[i]>col[j])swap(i,j);
      mp[datas(col[i],col[j])].emplace_back(i,j);
    }
  }
  dsu.snapshot();
  vec fch(K,1);
  rep(i,N)if(dsu.parcheck(i,i+N))fch[col[i]]=0;
  j=accumulate(all(fch),0);
  ans=j*(j-1)/2;
  for(auto& solve:mp){
    if(!fch[solve.first.first]||!fch[solve.first.second])continue;
    for(auto& x:solve.second){
      i=x.first;
      j=x.second;
      dsu.unite(i,j+N);
      dsu.unite(i+N,j);
      if(dsu.parcheck(i,i+N)||dsu.parcheck(j,j+N)){
        --ans;
        break;
      }
    }
    dsu.allundo();
  }
  print(ans);
// }
}