#pragma GCC target("avx")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using datas=pair<ll,ll>;
using ddatas=pair<long double,long double>;
using tdata=pair<ll,datas>;
using vec=vector<ll>;
using mat=vector<vec>;
using pvec=vector<datas>;
using pmat=vector<pvec>;
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
#define uniq(v) vsort(v);(v).erase(unique(all(v)),(v).end())
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
constexpr ll mod=1000000007;
// constexpr ll mod=998244353;
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
template<class T,class E> ostream& operator<<(ostream& os,const map<T,E>& v){
  os<<"{";bool f=false;
  for(auto& x:v){if(f)os<<",";os<<x;f=true;}
  os<<"}";
  return os;
}
template<class T> inline bool chmax(T& a,T b){bool x=a<b;if(x)a=b;return x;}
template<class T> inline bool chmin(T& a,T b){bool x=a>b;if(x)a=b;return x;}
#ifdef DEBUG
void debugg(){cout<<endl;}
template<class T,class... Args>void debugg(const T& x,const Args&... args){cout<<" "<<x;debugg(args...);}
#define debug(...) cout<<__LINE__<<" ["<<#__VA_ARGS__<<"]:",debugg(__VA_ARGS__)
#else
#define debug(...) (void(0))
#endif

void startupcpp(){
  cin.tie(0);
  ios::sync_with_stdio(false);
}

//nxt[i][j]:min_right(x>i)s.t.(0indexedij0indexedx)
int N,K,nxt[200001][21],divi[10000001];
int main(){
  startupcpp();
  for(int i=0;i<10000001;++i)divi[i]=i;
  for(int i=2;i*i<10000001;++i){
    for(int j=i*i;j<10000001;j+=i*i)divi[j]=j/(i*i);
  }
int codeforces;cin>>codeforces;while(codeforces--){
  cin>>N>>K;
  vector<int> v(N);
  for(auto &x:v){
    cin>>x;
    x=divi[x];
  }
  {
    auto za=v;
    uniq(za);
    for(auto &x:v)x=lower_bound(all(za),x)-za.begin();
    for(int k=0;k<=K;++k){
      vector<int> mp(za.size());
      int j=0,cnt=0;
      for(int i=0;i<N;++i){
        while(j<N&&cnt<=k){
          if(mp[v[j]]&&cnt==k)break;
          if(mp[v[j++]]++)++cnt;
        }
        nxt[i][k]=j;
        if(--mp[v[i]])--cnt;
      }
    }
  }
  // dp[i][j]:ijmin
  vector<vector<int>> dp(N+1,vector<int>(K+1,mod));
  for(int i=0;i<=min(N,K);++i)dp[i][i]=0;
  for(int i=0;i<N;++i)for(int j=0;j<=K;++j){
    for(int k=0;k<=K-j;++k){
      // nxt,
      chmin(dp[nxt[i][k]][j+k],dp[i][j]+1);
    }
  }
  print(max(*min_element(all(dp[N])),1));
}
}