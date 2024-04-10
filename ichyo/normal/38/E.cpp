#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <fstream>
#include <complex>
#include <stack>
#include <queue>

using namespace std;
typedef long long LL;
typedef pair<int, int> P;
static const double EPS = 1e-5;

#define FOR(i,k,n) for (int i=(k); i<(int)(n); ++i)
#define REP(i,n) FOR(i,0,n)
long long dp[3001][3001];
long long mi[3001];
int main(void){
  int n;
  cin>>n;
  //int x[3001],c[3001];
  vector< pair<long long, long long> > input;
  REP(i,n){
    long long a,b;
    cin>>a>>b;
    input.push_back(pair<long long,long long>(a,b));
  }
  sort(input.begin(), input.end());
  REP(i,3001) mi[i]=100000000000000000;
  dp[0][0] = (long long)input[0].second;
  mi[0] = (long long)input[0].second;
  FOR(i,1,n){
    FOR(j,0,i){
      dp[i][j] = (long long)dp[i-1][j] + (long long)abs((long long)input[i].first-input[j].first);
      mi[i] = (long long)min(mi[i], dp[i][j]);
      //printf("dp[%d][%d] %lld\n",i,j,dp[i][j]);
      //cout<<dp[2][2]<<endl;
      //cout<<(long long)abs((long long)input[i].first-input[j].first)<<endl;
    }
    dp[i][i] = (long long)mi[i-1] + (long long)input[i].second;
    //printf("dp[%d][%d] %lld\n",i,i,dp[i][i]);
    mi[i] = (long long)min(mi[i], dp[i][i]);
  }
  cout<<mi[n-1]<<endl;
  return 0;
}