#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define For(i,a,b) for(i=a;i<b;i++)
#define rep(i,N) For(i,0,N)

int main(){
  ll i,N,ans=0;
  cin>>N;
  string s;cin>>s;
  rep(i,N){
    if(s[i]==s[i+1]){
      ans++;
      s[i]=((s[i]=='a')?'b':'a');
    }
    i++;
  }
  cout<<ans<<endl<<s<<endl;
  return 0;
}