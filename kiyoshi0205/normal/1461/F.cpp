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

string solve(vec& v){
  string ans;
  if(v.size()==1){
    ans+=v[0]+'0';
    return ans;
  }
  int i=0,N=v.size();
  while(i<N&&v[i]==1){
    ++i;
    ans+="1+";
  }
  if(i==N){
    ans.pop_back();
    return ans;
  }
  if(i){
    int j=0;
    while(i+j<N){
      v[j]=v[i+j];++j;
    }
    while(i--)v.pop_back();
    return ans+solve(v);
  }
  while(v[N-i-1]==1){
    ans+="+1";
    ++i;
    v.pop_back();
  }
  if(i)return solve(v)+ans;
  int M=accumulate(all(v),1,[&](int a,int b){return min(a*b,2*N);});
  if(M==N*2){
    rep(i,N){
      ans+=v[i]+'0';
      ans+='*';
    }
    ans.pop_back();
    return ans;
  }
  pvec notone;
  rep(i,N)if(v[i]!=1)notone.emplace_back(i,v[i]);
  assert(notone.size()>1);
  int maxval=0,maxbit=0,bit;
  rep(bit,1<<(notone.size()-1)){
    int nowsum=0,nowprod=notone[0].second;
    rep(i,notone.size()-1){
      if(bit>>i&1)nowprod*=notone[i+1].second;
      else{
        nowsum+=nowprod+notone[i+1].first-notone[i].first-1;
        nowprod=notone[i+1].second;
      }
    }
    nowsum+=nowprod;
    if(chmax(maxval,nowsum))maxbit=bit;
  }
  int ch=0;
  ans+=v[0]+'0';
  rep1(i,N){
    ans+="+*"[maxbit>>ch&1];
    if(v[i]!=1)++ch;
    ans+=v[i]+'0';
  }
  return ans;
}
int main(){
  startupcpp();
  ll i,N;
  cin>>N;
  vec v(N);
  rep(i,N)cin>>v[i];
  string s;
  cin>>s;
  if(s.size()==1){
    s+='\n';
    rep(i,N)cout<<v[i]<<s[i==N-1];
    return 0;
  }
  if(s.size()==2&&s[0]!='*'&&s[1]!='*'){
    rep(i,N)cout<<v[i]<<"+\n"[i==N-1];
    return 0;
  }
  string ans;
  if(s.size()==2&&s[0]!='+'&&s[1]!='+'){
    rep(i,N){
      ans+=v[i]+'0';
      ans+='*';
    }
    ans.pop_back();
    ll j=min_element(all(v))-v.begin();
    if(!v[j]&&j)ans[j*2-1]='-';
    print(ans);
    return 0;
  }
  //use +,*
  vec ch;
  rep(i,N){
    if(v[i])ch.emplace_back(v[i]);
    else{
      if(ans.size())ans+='+';
      if(ch.size()){
        ans+=solve(ch);
        ans+='+';
        ch.clear();
      }
      ans+='0';
    }
  }
  if(ch.size()){
    if(ans.size())ans+='+';
    ans+=solve(ch);
  }
  print(ans);
}