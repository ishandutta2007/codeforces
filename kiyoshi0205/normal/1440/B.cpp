#include<bits/stdc++.h>
using namespace std;
int N,K;
int main(){
  int t;cin>>t;
  while(t--){
    cin>>N>>K;
    vector<int> v(N*K);
    for(auto& x:v)cin>>x;
    reverse(v.begin(),v.end());
    long long ans=0;
    int i,k=N-(N-1)/2;
    i=-1;
    for(int t=0;t<K;++t)ans+=v[i+=k];
    cout<<ans<<endl;
  }
}