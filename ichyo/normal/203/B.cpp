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
  int n, m;
  while(cin>>n>>m){
    int count[1010][1010] = {};
    REP(i, 1010)REP(j, 1010)count[i][j] = INF;
    REP(i, m){
      int x, y; cin>>x>>y;
      count[y][x] = i + 1;
    }
    int ans = INF;
    REP(y, n)REP(x, n){
      int maxx = 0;
      REP(i, 3)REP(j, 3) maxx = max(maxx, count[y+i][x+j]);
      ans = min(ans, maxx);
    }
    if(ans >= INF) ans = -1;
    cout<<ans<<endl;
  }


  return 0;
}