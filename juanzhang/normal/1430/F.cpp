#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=(a),i##end=(b);i<=i##end;++i)
#define per(i,a,b) for(int i=(a),i##end=(b);i>=i##end;--i)

typedef long long ll;
int n,k,dp[2010];
struct node{
  int l,r,x;
}A[2010];

int main(){
  cin>>n>>k;
  rep(i,1,n){
    cin>>A[i].l>>A[i].r>>A[i].x;
  }
  ll res=0,cur=k;
  per(i,n,1){
    ll val=A[i].x+(A[i].r==A[i+1].l?dp[i+1]:0);int t=A[i].r-A[i].l+1;
    if(1ll*t*k<val){
      return puts("-1"),0;
    }
    dp[i]=max(0ll,val-1ll*k*(t-1));
  }
  rep(i,1,n){
    res+=A[i].x;
    if(cur<dp[i])res+=cur,cur=k;
    cur-=A[i].x,cur=(cur%k+k)%k;
  }
  cout<<res<<endl;
  return 0;
}