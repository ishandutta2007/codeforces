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
  int n;
  int c[3]={};
  cin>>n;
  REP(i,n){
    int tmp;
    cin>>tmp;
    c[tmp-1]++;
  }
  int max_n = 0;
  REP(i,3){
    max_n = max(max_n,c[i]);
  }
  cout<<n-max_n<<endl;
  return 0;
}