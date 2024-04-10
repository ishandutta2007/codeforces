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
  int a,b,c,d;
  cin>>a>>b>>c>>d;
  bool ans = false;
  if(d>=a-1&&d<=2*(a+1)) ans = true;
  if(c>=b-1&&c<=2*(b+1)) ans = true;
  if(ans) cout<<"YES"<<endl;
  else cout<<"NO"<<endl;
  return 0;
}