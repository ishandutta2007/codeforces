#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>

using namespace std;

#define FOR(i,k,n) for(int i=(k); i<(int)n; ++i)
#define REP(i,n) FOR(i,0,n)
#define FORIT(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define INF 1000000

int main(){
  int dp[101][51][2]={};
  REP(i,101)REP(j,51)REP(l,2)dp[i][j][l] = -INF;
  dp[0][0][1] = 0;
  string s;
  int k;
  cin>>s;
  cin>>k;
  int N = s.size();
  REP(i,N){
    bool f = s[i]=='F';
    REP(n,51){
      if(f){
        dp[i+1][n][1] = dp[i][n][1] + 1;
        dp[i+1][n][0] = dp[i][n][0] - 1;
        if(n){
          dp[i+1][n][1] = max(dp[i+1][n][1],dp[i][n-1][0]);
          dp[i+1][n][0] = max(dp[i+1][n][0],dp[i][n-1][1]);
        }
      }else{
        dp[i+1][n][1] = dp[i][n][0];
        dp[i+1][n][0] = dp[i][n][1];
        if(n){
          dp[i+1][n][1] = max(dp[i+1][n][1],dp[i][n-1][1] + 1);
          dp[i+1][n][0] = max(dp[i+1][n][0],dp[i][n-1][0] - 1);
        }
      }
    }
  }
  int ans = 0;
  REP(n,k+1)REP(l,2)if(n%2==k%2)ans = max(ans,dp[N][n][l]);
  /* back */
  REP(i,101)REP(j,51)REP(l,2)dp[i][j][l] = -INF;
  dp[0][0][1] = 0;
  REP(i,N){
    bool f = s[i]=='F';
    REP(n,51){
      if(f){
        dp[i+1][n][1] = dp[i][n][1] - 1;
        dp[i+1][n][0] = dp[i][n][0] + 1;
        if(n){
          dp[i+1][n][1] = max(dp[i+1][n][1],dp[i][n-1][0]);
          dp[i+1][n][0] = max(dp[i+1][n][0],dp[i][n-1][1]);
        }
      }else{
        dp[i+1][n][1] = dp[i][n][0];
        dp[i+1][n][0] = dp[i][n][1];
        if(n){
          dp[i+1][n][1] = max(dp[i+1][n][1],dp[i][n-1][1] - 1);
          dp[i+1][n][0] = max(dp[i+1][n][0],dp[i][n-1][0] + 1);
        }
      }
    }
  }
  REP(n,k+1)REP(l,2)if(n%2==k%2)ans = max(ans,dp[N][n][l]);
  cout<<ans<<endl;
  return 0;
}