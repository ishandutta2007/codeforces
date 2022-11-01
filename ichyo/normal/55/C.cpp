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

int main(void){
  int n,m,k;
  cin>>n>>m>>k;
  vector<PII> pie;
  bool ans = false;
  REP(i,k){
    int x,y;
    cin>>x>>y;
    if(x<=5||n+1-x<=5) ans = true;
    if(y<=5||m+1-y<=5) ans = true;
  }
  if(ans) cout<<"YES"<<endl;
  else cout<<"NO"<<endl;
  return 0;

}