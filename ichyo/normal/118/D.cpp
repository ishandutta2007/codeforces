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
#define FOREQ(i,k,n) for(int i=(k); i<=(int)n; ++i)
#define MOD 100000000

int main(){
  int n1,n2,k1,k2;
  cin>>n1>>n2>>k1>>k2;
  int dp[102][102][2][11]={};
  dp[1][0][0][0] = 1;
  dp[0][1][1][0] = 1;
  FOR(i,0,n1+1)FOR(j,0,n2+1)REP(k,10){
    dp[i+1][j][0][0] += dp[i][j][1][k];
    dp[i][j+1][1][0] += dp[i][j][0][k];
    if(k+2 <= k1)dp[i+1][j][0][k+1] += dp[i][j][0][k];
    if(k+2 <= k2)dp[i][j+1][1][k+1] += dp[i][j][1][k];
    dp[i+1][j][0][0] %= MOD;
    dp[i][j+1][1][0] %= MOD;
    dp[i+1][j][0][k+1] %= MOD;
    dp[i][j+1][1][k+1] %= MOD;
  }
  int ans = 0;
  REP(i,2)REP(j,10)ans = (ans+dp[n1][n2][i][j])%MOD;
  cout<<ans<<endl;
  return 0;
}