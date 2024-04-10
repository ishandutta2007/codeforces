#include<bits/stdc++.h>
using namespace std;
int N,K;
int sol(vector<int> v,int c){
  int res=0;
  for(int i=0;i<N;++i){
    if(v[i]!=c){
      ++res;
      for(int j=0;j<K;++j)v[i+j]=c;
    }
  }
  return res;
}
int main(){
  int t;cin>>t;
  while(t--){
    int ans=1e8;
    cin>>N>>K;
    vector<int> v(N);
    for(auto& x:v)cin>>x;
    v.resize(N+K);
    for(int i=1;i<=100;++i)ans=min(ans,sol(v,i));
    cout<<ans<<endl;
  }
}