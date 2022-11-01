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
  int n,k;
  cin>>n>>k;
  vector<int> a(n);
  REP(i,n)cin>>a[i];
  int ans = 0;
  while(true){
    bool end = true;
    REP(i,n)if(a[i]<k) end = false;
    if(end) break;
    REP(i,n){
      if(i!=n-1&&a[i]==a[i+1]) continue;
      a[i]++;
    }
    ans++;
  }
  cout<<ans<<endl;
  return 0;
}