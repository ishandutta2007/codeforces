#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=(a),i##end=(b);i<=i##end;++i)
#define per(i,a,b) for(int i=(a),i##end=(b);i>=i##end;--i)

int n,m,A[105][105],val[1010];

int main(){
  int T;cin>>T;
  while(T--){
    cin>>n>>m;
    memset(A,0,sizeof A);
    memset(val,0,sizeof val);
    rep(i,1,n)rep(j,1,m)scanf("%d",&A[i][j]),val[i+j]^=A[i][j];
    bool flg=0;
    rep(i,2,n+m)flg|=val[i];
    puts(flg?"Ashish":"Jeel");
  }
  return 0;
}