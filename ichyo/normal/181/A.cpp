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
  int y,x;
  while(cin>>y>>x){
    vector<string> grid(y);
    REP(i,y)cin>>grid[i];
    int c[101] = {};
    int c2[101] = {};
    REP(i,y)REP(j,x)if(grid[i][j]=='*'){
      c[i+1]++;
      c2[j+1]++;
    }
    int ans1,ans2;
    REP(i,101)if(c[i]==1)ans1 = i;
    REP(i,101)if(c2[i]==1)ans2 = i;
    printf("%d %d\n",ans1,ans2);
  }
  return 0;
}