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
string solve(int N, int K){
  if(N < K) return "-1";
  if(K == 1){
    if(N == 1) return "a";
    else return "-1";
  }
  int L = N - (K - 2);
  string res;
  REP(i, L) res += (i % 2 == 0) ? "a" : "b";
  for(char c = 'c'; c < K +'a'; c++){
    res += string(1, c);
  }
  return res;
}

int main(){
  int N, K;
  while(cin >> N >> K){
    cout << solve(N, K) << endl;
  }
  return 0;
}