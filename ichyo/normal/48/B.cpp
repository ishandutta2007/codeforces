#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <cstring>
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
typedef pair<int, int> PII;
static const double EPS = 1e-5;

#define FOR(i,k,n) for (int i=(k); i<(int)(n); ++i)
#define REP(i,n) FOR(i,0,n)
int grid[51][51];
int main(void){
  int n,m;
  cin>>n>>m;
  REP(y,n)REP(x,m)cin>>grid[y][x];
  int a,b;
  cin>>a>>b;
  int ans = INT_MAX;
  REP(y,n-a+1)REP(x,m-b+1){
    int tmp=0;
    REP(dy,a)REP(dx,b){
      if(grid[y+dy][x+dx]) tmp++;
      if(tmp>ans) break;
    }
    ans = min(ans,tmp);
  }
  REP(y,n-b+1)REP(x,m-a+1){
    int tmp=0;
    REP(dy,b)REP(dx,a){
      if(grid[y+dy][x+dx]) tmp++;
      if(tmp>ans) break;
    }
    ans = min(ans,tmp);
  }
  cout<<ans<<endl;
  return 0;
}