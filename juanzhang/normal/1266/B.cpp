#include<bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=(a),i##end=(b);i<=i##end;++i)
#define per(i,a,b) for(int i=(a),i##end=(b);i>=i##end;--i)

int main(){
  int T;cin>>T;rep(i,1,T){
    long long x;cin>>x;
    bool asf=0;
    rep(i,1,6){
      long long t=(x-21+i);
      if(t>=0&&t%14==0){
        asf=1;
      }
    }
    puts(asf?"YES":"NO");
  }
  return 0;
}