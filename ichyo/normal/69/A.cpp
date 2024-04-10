#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
typedef complex<double> P;
static const double EPS = 1e-8;

#define FOR(i,k,n) for (int i=(k); i<(int)(n); ++i)
#define REP(i,n) FOR(i,0,n)

int main(void){
  int n;
  cin>>n;
  int x[3];
  REP(i,3)x[i]=0;
  REP(i,n){
    REP(j,3){
      int tmp;
      cin>>tmp;
      x[j] += tmp;
    }
  }
  bool ans = true;
  REP(i,3)if(x[i])ans=false;
  if(ans) cout<<"YES"<<endl;
  else cout<<"NO"<<endl;
  return 0;
}