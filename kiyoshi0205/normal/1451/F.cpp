#include<bits/stdc++.h>
using namespace std;
int main(){int t;cin>>t;while(t--){
  int H,W,x;
  cin>>H>>W;
  vector<int> v(H+W,0);
  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      cin>>x;
      v[i+j]^=x;
    }
  }
  if(*max_element(v.begin(),v.end()))puts("Ashish");
  else puts("Jeel");
}}