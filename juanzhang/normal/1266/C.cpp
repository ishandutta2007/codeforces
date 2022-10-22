#include<bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=(a),i##end=(b);i<=i##end;++i)
#define per(i,a,b) for(int i=(a),i##end=(b);i>=i##end;--i)

int A[505][505];

int main(){
  int n,m;cin>>n>>m;
  if(n==1&&m==1){
    return puts("0"),0;
  }
  bool flg=0;
  if(n>m){
    swap(n,m);
    flg=1;
  }
  rep(i,1,n)rep(j,1,m)A[i][j]=i*(n+j);
  set<int>S;
  rep(i,1,n){
    int x=0;
    rep(j,1,m)x=__gcd(x,A[i][j]);
    S.insert(x);
  }
  rep(i,1,m){
    int x=0;
    rep(j,1,n)x=__gcd(x,A[j][i]);
    S.insert(x);
  }
//  cout<<S.size()<<' '<<n+m<<endl;
  if(!flg){
    rep(i,1,n)rep(j,1,m)printf("%d%c",A[i][j],"\n "[j<m]);
  }else{
    rep(i,1,m)rep(j,1,n)printf("%d%c",A[j][i],"\n "[j<n]);
  }
  return 0;
}