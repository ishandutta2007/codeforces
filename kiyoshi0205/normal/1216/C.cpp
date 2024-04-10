#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define For(i,a,b) for(i=a;i<b;i++)
#define rep(i,N) For(i,0,N)
using datas=pair<ll,ll>;

int main(){
  ll i,ans=1;
  vector<datas> v(6);
  rep(i,6){
    cin>>v[i].first>>v[i].second;
  }
  if(v[2].first<=v[0].first&&v[2].second<=v[0].second&&v[1].first<=v[3].first&&v[1].second<=v[3].second)ans=0;
  if(v[4].first<=v[0].first&&v[4].second<=v[0].second&&v[1].first<=v[5].first&&v[1].second<=v[5].second)ans=0;

  if(v[2].second<=v[0].second&&v[1].second<=v[3].second&&v[4].second<=v[0].second&&v[1].second<=v[5].second){
    ans=0;
    For(i,v[0].first*2,v[1].first*2+1){
      if((v[2].first*2<=i&&i<=v[3].first*2)||(v[4].first*2<=i&&i<=v[5].first*2))continue;
      ans=1;
      break;
    }
  }
  if(v[2].first<=v[0].first&&v[1].first<=v[3].first&&v[4].first<=v[0].first&&v[1].first<=v[5].first){
    ans=0;
    For(i,v[0].second*2,v[1].second*2+1){
      if((v[2].second*2<=i&&i<=v[3].second*2)||(v[4].second*2<=i&&i<=v[5].second*2))continue;
      ans=1;
      break;
    }
  }
  if(ans){
    cout<<"YES"<<endl;
  }else{
    cout<<"NO"<<endl;
  }
  return 0;
}