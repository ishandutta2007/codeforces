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
  string start,end;
  int K;
  while(cin>>start>>end>>K){
    int N = start.size();
    vector<int> dp(N+1);
    dp[0] = 1;
    ll sum = 1;
    REP(i,K){
      ll nextsum = 0;
      vector<int> nextdp(N+1);
      REP(j,N) {
        nextsum += (nextdp[j] = (sum - dp[j]) % MOD);
      }
      sum = nextsum;
      dp = nextdp;
    }
    int ans = 0;
    REP(i,N){
      if(start.substr(i) + start.substr(0,i) == end){
        ans += dp[i];
        ans %= MOD;
      }
    }
    cout<<ans<<endl;
  }
  return 0;
}