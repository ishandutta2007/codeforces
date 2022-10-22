#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using vec=vector<ll>;
using mat=vector<vec>;
using datas=pair<ll,ll>;
using pvec=vector<datas>;
#define For(i,a,b) for(i=a;i<(ll)b;i++)
#define rep(i,N) For(i,0,N)
#define rep1(i,N) For(i,1,N)
#define all(v) (v).begin(),(v).end()
#define vsort(v) sort(all(v))
#define output(v) do{bool f=0;for(auto outi:v){cout<<(f?" ":"")<<outi;f=1;}cout<<endl;}while(0)
const ll inf=1LL<<60;
template<class T> inline bool chmax(T& a,T b){bool x=a<b;if(x)a=b;return x;} 
template<class T> inline bool chmin(T& a,T b){bool x=a>b;if(x)a=b;return x;} 

int main(){
  ll T;
  cin>>T;
while(T--){
  ll i,N,f=2;
  cin>>N;
  vec a(N),b(N);
  rep(i,N)cin>>a[i];
  rep(i,N){
    cin>>b[i];
    b[i]-=a[i];
  }
  b.erase(unique(all(b)),b.end());
  rep(i,b.size()){
    if(b[i]!=0){
      f--;
      if(b[i]<0)f--;
    }
  }
  if(f>0){
    cout<<"YES"<<endl;
  }else{
    cout<<"NO"<<endl;
  }
} return 0;
}