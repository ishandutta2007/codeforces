#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using vec=vector<ll>;
using mat=vector<vec>;
#define For(i,a,b) for(i=a;i<b;i++)
#define rep(i,N) For(i,0,N)
#define rep1(i,N) For(i,1,N)
#define all(v) (v).begin(),(v).end()
#define allr(v) (v).rbegin(),(v).rend()
#define vsort(v) sort(all(v))
#define vrsort(v) sort(allr(v))
#define mod 1000000007

int main(){
  ll i=1,N,cnt,f=1;
  string ss;cin>>ss;
  N=ss.size();
  if(N==1){cout<<0<<endl;return 0;}
  vector<ll> v(N);
  while(i<N&&ss[i]=='0')i++;
  if(N%2==0||i!=N)f=0;
  cnt=(N+1)/2;
  cout<<cnt-f<<endl;
  return 0;
}