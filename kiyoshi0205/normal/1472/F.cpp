#include<bits/stdc++.h>
using namespace std;
bool solve(){
  int N;
  cin>>N>>N;
  vector<pair<int,int>> v(N);
  for(auto& x:v){
    cin>>x.second>>x.first;
    (x.second+=x.first)&=1;
  }
  if(N&1)return false;
  sort(v.begin(),v.end());
  v.emplace_back(-1,0);
  for(int i=1;i<N;i+=2){
    if(v[i].second==v[i-1].second||v[i].first==v[i+1].first)return false;
  }
  return true;
}
int main(){
  int T;
  cin>>T;
  while(T--){
    if(solve())puts("YES");
    else puts("NO");
  }
}