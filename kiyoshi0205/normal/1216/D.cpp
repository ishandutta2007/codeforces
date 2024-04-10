#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using vec=vector<ll>;
#define For(i,a,b) for(i=a;i<b;i++)
#define rep(i,N) For(i,0,N)
#define rep1(i,N) For(i,1,N)
#define allr(v) (v).rbegin(),(v).rend()
#define vrsort(v) sort(allr(v))

ll gcd(ll a,ll b){if(!b)return a;return (a%b==0)?b:gcd(b,a%b);}

int main(){
  ll i,N,x,ans=0,swd=0,mxs;
  cin>>N;
  vec v(N);
  rep(i,N)cin>>v[i];
  vrsort(v);
  mxs=v[0];
  if(v[N-1]==mxs){
    cout<<"0 0"<<endl;
    return 0;
  }
  rep1(i,N){
    x=mxs-v[i];
    ans+=x;
    swd=gcd(x,swd);
  }
  cout<<ans/swd<<" "<<swd<<endl;
  return 0;
}