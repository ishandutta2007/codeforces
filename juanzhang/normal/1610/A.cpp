#include<bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=(a),i##end=(b);i<=i##end;++i)
#define per(i,a,b) for(int i=(a),i##end=(b);i>=i##end;--i)

int main(){
  int T;
  cin>>T;
  while(T--){
    int n,m;
    cin>>n>>m;
    cout<<(n==1&&m==1?0:min(n,m)==1?1:2)<<endl;
  }
  return 0;
}