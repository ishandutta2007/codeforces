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
#include <cassert>
//C++11
#if __cplusplus == 201103L
#include <tuple>
#endif

using namespace std;

#define FOR(i,k,n) for(int i=(k); i<(int)n; ++i)
#define REP(i,n) FOR(i,0,n)
#define FORIT(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)

template<class T> void debug(T begin, T end){ for(T i = begin; i != end; ++i) cout<<*i<<" "; cout<<endl; }

typedef long long ll;
const int INF = 100000000;
const double EPS = 1e-8;
const int MOD = 1000000007;

int main(){
  int N;
  while(cin>>N && N){
    int dp[26][26] = {};
    REP(i, N){
      string s;
      cin>>s;
      int from = s[0] - 'a';;
      int to = s[s.size() - 1] - 'a';
      REP(j, 26)if(dp[j][from] > 0 || j == from){
        dp[j][to] = max(dp[j][to], dp[j][from] + (int)s.size());
      }
    }
    int ans = 0;
    REP(i, 26)ans = max(ans, dp[i][i]);
    cout<<ans<<endl;
  }
  return 0;
}