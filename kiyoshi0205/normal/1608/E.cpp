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

ll N;
//ac
//ab
ll solve1(pvec a,pvec b,pvec c){
  ll ok=0,ng=N+1;
  vsort(a);
  sort(all(b),[](datas l,datas r){return l.second<r.second;});
  while(ng-ok>1){
    ll mid=(ok+ng)/2;
    ll axmax=a[mid-1].first;
    ll i,cnt=0;
    rep(i,N){
      if(b[i].first<=axmax)continue;
      ++cnt;
      if(cnt==mid)break;
    }
    if(i==N){
      ng=mid;
      continue;
    }
    ll bymax=b[i].second;
    cnt=0;
    rep(i,N){
      if(c[i].first<=axmax||c[i].second<=bymax)continue;
      ++cnt;
      if(cnt==mid)break;
    }
    if(i==N){
      ng=mid;
      continue;
    }
    ok=mid;
  }
  return ok;
}
//abc
ll solve2(pvec a,pvec b,pvec c){
  vsort(a);
  vsort(b);
  vsort(c);
  ll ok=0,ng=N+1;
  while(ng-ok>1){
    ll mid=(ok+ng)/2;
    ll axmax=a[mid-1].first;
    ll i,cnt=0;
    rep(i,N){
      if(b[i].first<=axmax)continue;
      ++cnt;
      if(cnt==mid)break;
    }
    if(i==N){
      ng=mid;
      continue;
    }
    ll bxmax=b[i].first;
    cnt=0;
    rep(i,N){
      if(c[i].first<=bxmax)continue;
      ++cnt;
      if(cnt==mid)break;
    }
    if(i==N){
      ng=mid;
      continue;
    }
    ok=mid;
  }
  return ok;
}
int main(){
  startupcpp();
  cin>>N;
  pvec v[3];
  ll i,x,y;
  rep(i,N){
    ll c;
    cin>>x>>y>>c;
    v[c-1].emplace_back(x,y);
  }
  N/=3;
  ll ch,ans=0;
  rep(ch,2){
    rep(x,2){
      rep(y,2){
        vec p={0,1,2};
        do{
          chmax(ans,solve1(v[p[0]],v[p[1]],v[p[2]]));
          chmax(ans,solve2(v[p[0]],v[p[1]],v[p[2]]));
        }while(next_permutation(all(p)));
        rep(i,3)for(auto& x:v[i])x.second=-x.second;
      }
      rep(i,3)for(auto& x:v[i])x.first=-x.first;
    }
    rep(i,3)for(auto& x:v[i])swap(x.first,x.second);
  }
  print(ans*3);
}