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
int main(){
  startupcpp();
  int codeforces;cin>>codeforces;while(codeforces--){
  ll i,j,H,W,N,cnt=0;
  string s;
  cin>>H>>W;
  N=H*W;
  vec bw(N),h(N,0),g(N);
  mat rg(N);
  rep(i,H){
    cin>>s;
    rep(j,W)bw[i*W+j]=s[j]=='0';
  }
  rep(i,H){
    cin>>s;
    rep(j,W){
      if(s[j]=='U'){
        g[i*W+j]=(i-1)*W+j;
        rg[(i-1)*W+j].eb(i*W+j);
        ++h[(i-1)*W+j];
      }else if(s[j]=='R'){
        g[i*W+j]=i*W+j+1;
        rg[i*W+j+1].eb(i*W+j);
        ++h[i*W+j+1];
      }else if(s[j]=='D'){
        g[i*W+j]=(i+1)*W+j;
        rg[(i+1)*W+j].eb(i*W+j);
        ++h[(i+1)*W+j];
      }else{
        g[i*W+j]=i*W+j-1;
        rg[i*W+j-1].eb(i*W+j);
        ++h[i*W+j-1];
      }
    }
  }
  queue<datas> que;
  rep(i,N){
    if(!h[i]){
      que.push(datas(i,0));
    }
  }
  while(!que.empty()){
    datas x=que.front();que.pop();
    ++cnt;
    ll next=g[x.first];
    --h[next];
    if(!h[next])que.push(datas(next,0));
  }
  cout<<N-cnt<<" ";
  cnt=0;
  rep(i,N)if(h[i]>0){
    vec loop(1,bw[i]);
    j=g[i];
    while(j!=i){
      loop.eb(bw[j]);
      j=g[j];
    }
    for(ll next:rg[i])que.push(datas(loop.size()-1,next));
    while(!que.empty()){
      datas x=que.front();que.pop();
      h[x.second]=0;
      if(x.second==i)continue;
      loop[x.first%loop.size()]|=bw[x.second];
      for(ll next:rg[x.second])que.push(datas(x.first+loop.size()-1,next));      
    }
    cnt+=accumulate(all(loop),0LL);
  }
  print(cnt);
}}