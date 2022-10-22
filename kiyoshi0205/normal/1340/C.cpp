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
const int inf=1<<30;
template<class T> inline bool chmin(T& a,T b){bool x=a>b;if(x)a=b;return x;} 
using P=pair<int,int>;
int main(){
  // int codeforces;cin>>codeforces;while(codeforces--){
  int i,j=0,k,f,N,M,A,B,ans=-1;
  scanf("%d %d",&N,&M);
  vector<int> v(M),sv(M-1);
  rep(i,M)scanf("%d",&v[i]);
  vsort(v);
  rep(i,M-1)sv[i]=v[i+1]-v[i];
  scanf("%d %d",&A,&B);
  vector<int> dist(M*A,inf);
  deque<P> que;
  que.eb(0,0);
  while(!que.empty()){
    P x=que.front();que.pop_front();
    if(!chmin(dist[x.second],x.first))continue;
    i=x.second/A;
    j=x.second%A;
    if(i&&j+sv[i-1]<=A){
      f=j+sv[i-1]==A;
      if(dist[k=(i-1-f)*A+j+sv[i-1]]==inf){
        // que.push(P(x.first+f,k));
        if(f)que.eb(x.first+1,k);
        else que.emplace_front(x.first,k);
      }
    }
    if(i<M-1&&j+sv[i]<=A){
      f=j+sv[i]==A;
      if(dist[k=(i+1-f)*A+j+sv[i]]==inf){
        // que.push(P(x.first+f,k));
        if(f)que.eb(x.first+1,k);
        else que.emplace_front(x.first,k);
      }
    }
  }
  j=k=inf;
  rep(i,A){
    if(chmin(k,dist[i+A*(M-1)]))j=i;
  }
  if(k!=inf){
    ans=k*(A+B)+j;
    if(!j)ans-=B;
  }
  printf("%d\n",ans);
}