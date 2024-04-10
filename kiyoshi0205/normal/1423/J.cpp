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
#define endl "\n"
#define eb emplace_back
#define print(x) cout<<x<<endl
#define printyes print("Yes")
#define printno print("No")
#define printYES print("YES")
#define printNO print("NO")
#define output(v) do{bool f=0;for(auto outi:v){cout<<(f?" ":"")<<outi;f=1;}cout<<endl;}while(0)
#define matoutput(v) do{for(auto outimat:v)output(outimat);}while(0)
constexpr ll mod=1000000007;
// const ll mod=998244353;
const ll inf=1LL<<60;
const double PI=acos(-1);
const double eps=1e-9;
template<class T,class E> ostream& operator<<(ostream& os,pair<T,E>& p){return os<<"{"<<p.first<<","<<p.second<<"}";}
template<class T> inline bool chmax(T& a,T b){bool x=a<b;if(x)a=b;return x;}
template<class T> inline bool chmin(T& a,T b){bool x=a>b;if(x)a=b;return x;}

void startupcpp(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout<<fixed<<setprecision(15);
}

ll N;
int dp[61][8];
int main(){
  startupcpp();
int codeforces;cin>>codeforces;while(codeforces--){
  ll N;int i,j;
  cin>>N;
  rep(i,61)rep(j,8)dp[i][j]=0;
  dp[0][0]=1;
  rep(i,60){
    if(N>>i&1){
      dp[i+1][0]+=dp[i][0];
      if(dp[i+1][0]>=mod)dp[i+1][0]-=mod;
      dp[i+1][1]+=dp[i][0];
      if(dp[i+1][1]>=mod)dp[i+1][1]-=mod;
      dp[i+1][2]+=dp[i][0];
      if(dp[i+1][2]>=mod)dp[i+1][2]-=mod;
      dp[i+1][3]+=dp[i][0];
      if(dp[i+1][3]>=mod)dp[i+1][3]-=mod;
      dp[i+1][0]+=dp[i][1];
      if(dp[i+1][0]>=mod)dp[i+1][0]-=mod;
      dp[i+1][1]+=dp[i][1];
      if(dp[i+1][1]>=mod)dp[i+1][1]-=mod;
      dp[i+1][2]+=dp[i][1];
      if(dp[i+1][2]>=mod)dp[i+1][2]-=mod;
      dp[i+1][3]+=dp[i][1];
      if(dp[i+1][3]>=mod)dp[i+1][3]-=mod;
      dp[i+1][1]+=dp[i][2];
      if(dp[i+1][1]>=mod)dp[i+1][1]-=mod;
      dp[i+1][2]+=dp[i][2];
      if(dp[i+1][2]>=mod)dp[i+1][2]-=mod;
      dp[i+1][3]+=dp[i][2];
      if(dp[i+1][3]>=mod)dp[i+1][3]-=mod;
      dp[i+1][4]+=dp[i][2];
      if(dp[i+1][4]>=mod)dp[i+1][4]-=mod;
      dp[i+1][1]+=dp[i][3];
      if(dp[i+1][1]>=mod)dp[i+1][1]-=mod;
      dp[i+1][2]+=dp[i][3];
      if(dp[i+1][2]>=mod)dp[i+1][2]-=mod;
      dp[i+1][3]+=dp[i][3];
      if(dp[i+1][3]>=mod)dp[i+1][3]-=mod;
      dp[i+1][4]+=dp[i][3];
      if(dp[i+1][4]>=mod)dp[i+1][4]-=mod;
      dp[i+1][2]+=dp[i][4];
      if(dp[i+1][2]>=mod)dp[i+1][2]-=mod;
      dp[i+1][3]+=dp[i][4];
      if(dp[i+1][3]>=mod)dp[i+1][3]-=mod;
      dp[i+1][4]+=dp[i][4];
      if(dp[i+1][4]>=mod)dp[i+1][4]-=mod;
      dp[i+1][5]+=dp[i][4];
      if(dp[i+1][5]>=mod)dp[i+1][5]-=mod;
      dp[i+1][2]+=dp[i][5];
      if(dp[i+1][2]>=mod)dp[i+1][2]-=mod;
      dp[i+1][3]+=dp[i][5];
      if(dp[i+1][3]>=mod)dp[i+1][3]-=mod;
      dp[i+1][4]+=dp[i][5];
      if(dp[i+1][4]>=mod)dp[i+1][4]-=mod;
      dp[i+1][5]+=dp[i][5];
      if(dp[i+1][5]>=mod)dp[i+1][5]-=mod;
      dp[i+1][3]+=dp[i][6];
      if(dp[i+1][3]>=mod)dp[i+1][3]-=mod;
      dp[i+1][4]+=dp[i][6];
      if(dp[i+1][4]>=mod)dp[i+1][4]-=mod;
      dp[i+1][5]+=dp[i][6];
      if(dp[i+1][5]>=mod)dp[i+1][5]-=mod;
      dp[i+1][6]+=dp[i][6];
      if(dp[i+1][6]>=mod)dp[i+1][6]-=mod;
      dp[i+1][3]+=dp[i][7];
      if(dp[i+1][3]>=mod)dp[i+1][3]-=mod;
      dp[i+1][4]+=dp[i][7];
      if(dp[i+1][4]>=mod)dp[i+1][4]-=mod;
      dp[i+1][5]+=dp[i][7];
      if(dp[i+1][5]>=mod)dp[i+1][5]-=mod;
      dp[i+1][6]+=dp[i][7];
      if(dp[i+1][6]>=mod)dp[i+1][6]-=mod;
    }else{
      dp[i+1][0]+=dp[i][0];
      if(dp[i+1][0]>=mod)dp[i+1][0]-=mod;
      dp[i+1][1]+=dp[i][0];
      if(dp[i+1][1]>=mod)dp[i+1][1]-=mod;
      dp[i+1][2]+=dp[i][0];
      if(dp[i+1][2]>=mod)dp[i+1][2]-=mod;
      dp[i+1][3]+=dp[i][0];
      if(dp[i+1][3]>=mod)dp[i+1][3]-=mod;
      dp[i+1][1]+=dp[i][1];
      if(dp[i+1][1]>=mod)dp[i+1][1]-=mod;
      dp[i+1][2]+=dp[i][1];
      if(dp[i+1][2]>=mod)dp[i+1][2]-=mod;
      dp[i+1][3]+=dp[i][1];
      if(dp[i+1][3]>=mod)dp[i+1][3]-=mod;
      dp[i+1][4]+=dp[i][1];
      if(dp[i+1][4]>=mod)dp[i+1][4]-=mod;
      dp[i+1][1]+=dp[i][2];
      if(dp[i+1][1]>=mod)dp[i+1][1]-=mod;
      dp[i+1][2]+=dp[i][2];
      if(dp[i+1][2]>=mod)dp[i+1][2]-=mod;
      dp[i+1][3]+=dp[i][2];
      if(dp[i+1][3]>=mod)dp[i+1][3]-=mod;
      dp[i+1][4]+=dp[i][2];
      if(dp[i+1][4]>=mod)dp[i+1][4]-=mod;
      dp[i+1][2]+=dp[i][3];
      if(dp[i+1][2]>=mod)dp[i+1][2]-=mod;
      dp[i+1][3]+=dp[i][3];
      if(dp[i+1][3]>=mod)dp[i+1][3]-=mod;
      dp[i+1][4]+=dp[i][3];
      if(dp[i+1][4]>=mod)dp[i+1][4]-=mod;
      dp[i+1][5]+=dp[i][3];
      if(dp[i+1][5]>=mod)dp[i+1][5]-=mod;
      dp[i+1][2]+=dp[i][4];
      if(dp[i+1][2]>=mod)dp[i+1][2]-=mod;
      dp[i+1][3]+=dp[i][4];
      if(dp[i+1][3]>=mod)dp[i+1][3]-=mod;
      dp[i+1][4]+=dp[i][4];
      if(dp[i+1][4]>=mod)dp[i+1][4]-=mod;
      dp[i+1][5]+=dp[i][4];
      if(dp[i+1][5]>=mod)dp[i+1][5]-=mod;
      dp[i+1][3]+=dp[i][5];
      if(dp[i+1][3]>=mod)dp[i+1][3]-=mod;
      dp[i+1][4]+=dp[i][5];
      if(dp[i+1][4]>=mod)dp[i+1][4]-=mod;
      dp[i+1][5]+=dp[i][5];
      if(dp[i+1][5]>=mod)dp[i+1][5]-=mod;
      dp[i+1][6]+=dp[i][5];
      if(dp[i+1][6]>=mod)dp[i+1][6]-=mod;
      dp[i+1][3]+=dp[i][6];
      if(dp[i+1][3]>=mod)dp[i+1][3]-=mod;
      dp[i+1][4]+=dp[i][6];
      if(dp[i+1][4]>=mod)dp[i+1][4]-=mod;
      dp[i+1][5]+=dp[i][6];
      if(dp[i+1][5]>=mod)dp[i+1][5]-=mod;
      dp[i+1][6]+=dp[i][6];
      if(dp[i+1][6]>=mod)dp[i+1][6]-=mod;
      dp[i+1][4]+=dp[i][7];
      if(dp[i+1][4]>=mod)dp[i+1][4]-=mod;
      dp[i+1][5]+=dp[i][7];
      if(dp[i+1][5]>=mod)dp[i+1][5]-=mod;
      dp[i+1][6]+=dp[i][7];
      if(dp[i+1][6]>=mod)dp[i+1][6]-=mod;
      dp[i+1][7]+=dp[i][7];
      if(dp[i+1][7]>=mod)dp[i+1][7]-=mod;
    }
  }
  print(dp[60][0]);
}
}