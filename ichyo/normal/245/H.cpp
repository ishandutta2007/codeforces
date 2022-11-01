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

#define FOR(i,k,n) for(int i=(k); i<(int)(n); ++i)
#define REP(i,n) FOR(i,0,n)
#define FORIT(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)

template<class T> void debug(T begin, T end){ for(T i = begin; i != end; ++i) cerr<<*i<<" "; cerr<<endl; }
inline bool valid(int x, int y, int W, int H){ return (x >= 0 && y >= 0 && x < W && y < H); }

typedef long long ll;
const int INF = 100000000;
const double EPS = 1e-8;
const int MOD = 1000000007;
int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
int dp[5000][5000] = {};

int main(){
  string s;
  cin>>s;
  const int N = s.size();
  vector<int> v[5000];
  for(int m = 0; m < N; m++){
    for(int d = 0; m + d < N && m - d >= 0; d++){
      if(s[m + d] != s[m - d]) break;
      v[m + d].push_back(m - d);
    }
  }
  for(int m = 1; m < N; m++){
    for(int d = 0; m - d - 1 >= 0 && m + d < N; d++){
      if(s[m + d] != s[m - d - 1]) break;
      v[m + d].push_back(m - d - 1);
    }
  }
  REP(i, N) sort(v[i].begin(), v[i].end());
  for(int i = 0; i < N; i++){
    for(int j = i; j < N; j++){
      if(j > i) dp[i][j] += dp[i][j - 1];
      dp[i][j] += (v[j].size() - (lower_bound(v[j].begin(), v[j].end(), i) - v[j].begin()));
    }
  }
  int Q; cin>>Q;
  while(Q--){
    int l, r;
    scanf("%d %d", &l, &r);
    l--; r--;
    cout<<dp[l][r]<<endl;
  }
  return 0;
}