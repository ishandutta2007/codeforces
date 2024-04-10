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
  ll i,N,l,r,m=1,M=1,mcnt=0,Mcnt=0;
  cin>>N>>l>>r;
  rep1(i,l)M*=2;
  rep(i,N){
    Mcnt+=M;
    M=max(M/2,(ll)1);
    mcnt+=m;
    if(i<r-1){
      m*=2;
    }
    //cout<<Mcnt<<endl;
  }
  cout<<Mcnt<<" "<<mcnt<<endl;
  return 0;
}