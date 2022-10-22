#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define For(i,a,b) for(i=a;i<b;i++)
#define rep(i,N) For(i,0,N)
#define allr(v) (v).rbegin(),(v).rend()
#define vrsort(v) sort(allr(v))
using datas=pair<ll,ll>;
int main(){
  ll i,N,x,ans;
  cin>>N;
  ans=N;
  vector<datas> v(N);
  rep(i,N){
    cin>>x;
    v[i]=datas(x,i+1);
  }
  vrsort(v);
  rep(i,N){
    ans+=v[i].first*i;
  }
  cout<<ans<<endl;
  rep(i,N-1){
    cout<<v[i].second<<" ";
  }
  cout<<v[N-1].second<<endl;
  return 0;
}