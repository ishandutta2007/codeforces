#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=(a),i##end=(b);i<=i##end;++i)
#define per(i,a,b) for(int i=(a),i##end=(b);i>=i##end;--i)

typedef vector<int>vi;

const int P=998244353;
int n,k,pw2[1<<18];

int solve(vi A,vi B,int k,int lev){
  if(A.empty()||B.empty()||lev==-1)return pw2[A.size()+B.size()];
  vi a[2],b[2];
  for(int x:A)a[x>>lev&1].push_back(x);
  for(int x:B)b[x>>lev&1].push_back(x);
  if(~k>>lev&1)return((1ll*pw2[A.size()]-pw2[a[0].size()]-pw2[a[1].size()]+1+pw2[B.size()]-pw2[b[0].size()]-pw2[b[1].size()])+solve(a[0],b[0],k,lev-1)+solve(a[1],b[1],k,lev-1))%P;
  return 1ll*solve(a[0],b[1],k,lev-1)*solve(a[1],b[0],k,lev-1)%P;
}
int solve(vi A,int k,int lev){
  if(A.empty()||lev==-1)return pw2[A.size()];
  vi a[2];
  for(int x:A)a[x>>lev&1].push_back(x);
  if(~k>>lev&1)return(P-1ll+solve(a[0],k,lev-1)+solve(a[1],k,lev-1))%P;
  return solve(a[0],a[1],k,lev);
}

int main(){
  ios::sync_with_stdio(0);
  cin>>n>>k;
  vi A(n);
  pw2[0]=1;rep(i,1,n)cin>>A[i-1],pw2[i]=2*pw2[i-1]%P;
  cout<<(solve(A,k,29)+P-1)%P<<endl;
  return 0;
}