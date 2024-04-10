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

int main(){
  int n,m,c,d;
  int p[11],q[11],r[11],s[11];
  while(cin>>n>>m>>c>>d){
    REP(i,m){
      cin>>p[i]>>q[i]>>r[i]>>s[i];
    }
    int dp[1001]={};
    REP(i,1001-c){
      dp[i+c] = max(dp[i+c],dp[i]+d);
    }
    REP(i,m){
      REP(t,p[i]/q[i]){
        for(int k = 1000-r[i]; k>=0; k--){
          dp[k+r[i]] = max(dp[k+r[i]],dp[k]+s[i]);
        }
      }
    }
    cout<<dp[n]<<endl;
  }
  return 0;
}