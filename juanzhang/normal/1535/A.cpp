#include<bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=(a),i##end=(b);i<=i##end;++i)
#define per(i,a,b) for(int i=(a),i##end=(b);i>=i##end;--i)

int main(){
  int T;cin>>T;while(T--){
    int a[4],b[4];
    rep(i,0,3)cin>>a[i],b[i]=a[i];
    sort(b,b+4);
    int x=max(a[0],a[1]),y=max(a[2],a[3]);
    if(x<y)swap(x,y);
    puts(b[2]==y&&b[3]==x?"YES":"NO");
  }
  return 0;
}