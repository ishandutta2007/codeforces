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
  int N,K;
  cin>>N>>K;
  int C;
  cin>>C;
  vector<int> hol(C+2);
  hol[0] = 0;
  hol[C+1] = N+1;
  REP(i,C)cin>>hol[i+1];
  int ans = 0;
  REP(i,C+1){
    int d = hol[i+1]-hol[i];
    ans += (d-EPS)/K;
  }
  cout<<ans+hol.size()-2<<endl;
  return 0;
}