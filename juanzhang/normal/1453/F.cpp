#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=(a),i##end=(b);i<=i##end;++i)
#define per(i,a,b) for(int i=(a),i##end=(b);i>=i##end;--i)

const int maxn=3010;
void chkmin(int&x,int y){if(x>y)x=y;}
int n,A[maxn],dp[maxn][maxn],val[maxn][maxn],tag[maxn][maxn];

int main(){
  int T;cin>>T;
  while(T--){
    cin>>n;
    rep(i,1,n){
      scanf("%d",A+i);
      rep(j,1,n)dp[i][j]=tag[i][j]=1e9;
      per(j,i-1,1)val[i][j]=val[i][j+1]+(j+A[j]>=i);
    }
    rep(i,1,n-1)if(i+A[i]==n)dp[n][i]=val[n][i+1];
    per(i,n-1,1){
      rep(j,i+1,n)if(i+A[i]>=j){
        dp[j][i]=min(dp[j][i],tag[j][i+A[i]]+val[j][i+1]);
      }
      rep(j,i+1,n)chkmin(tag[i][j-1],dp[j][i]);
      per(j,n-1,1)chkmin(tag[i][j],tag[i][j+1]);
    }
    int as=1e9;
    rep(i,1,n)as=min(as,dp[i][1]);
    cout<<as<<endl;
  }
  return 0;
}