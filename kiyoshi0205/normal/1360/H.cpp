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
#define print(v) cout<<v<<endl
#define printyes cout<<"Yes"<<endl
#define printno cout<<"No"<<endl
#define printYES cout<<"YES"<<endl
#define printNO cout<<"NO"<<endl
#define output(v) do{bool f=0;for(auto outi:v){cout<<(f?"":"")<<outi;f=1;}cout<<endl;}while(0)
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
void inc(string& s,map<string,bool>& mp){
  for(int i=s.size();i--;){
    if(s[i]&1){
      --s[i];
    }else{
      ++s[i];
      break;
    }
  }
  if(mp[s])inc(s,mp);
}
void dec(string& s,map<string,bool>& mp){
  for(int i=s.size();i--;){
    if(s[i]&1){
      --s[i];
      break;
    }else{
      ++s[i];
    }
  }
  if(mp[s])dec(s,mp);
}
int main(){
  startupcpp();
  int codeforces;cin>>codeforces;while(codeforces--){
  int i,N,M,cnt[2]={};
  map<string,bool> mp;
  cin>>N>>M;
  string s;
  while(N--){
    cin>>s;
    mp[s]=true;
    ++cnt[s[0]&1];
  }
  if(cnt[0]>cnt[1]){
    s[0]='0';
    rep1(i,M)s[i]='1';
    N=(cnt[0]-cnt[1]-1)>>1;
    inc(s,mp);
    while(N--)inc(s,mp);
  }else{
    s[0]='1';
    rep1(i,M)s[i]='0';
    dec(s,mp);
    N=(cnt[1]-cnt[0])>>1;
    while(N--)dec(s,mp);
  }
  print(s);
}}