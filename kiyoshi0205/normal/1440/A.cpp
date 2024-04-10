#include<bits/stdc++.h>
using namespace std;
int main(){
  int t;cin>>t;
  while(t--){
    int c[2],A,B,ch;
    string s;
    cin>>A>>A>>B>>ch>>s;
    int ans=0;
    c[0]=min(A,B+ch);
    c[1]=min(B,A+ch);
    for(auto x:s)ans+=c[x&1];
    cout<<ans<<endl;
  }
}