#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
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
typedef pair<int, int> P;
static const double EPS = 1e-5;

#define FOR(i,k,n) for (int i=(k); i<(int)(n); ++i)
#define REP(i,n) FOR(i,0,n)

int main(void){
  int n,b,m=0;
  cin>>n>>b;
  vector<int> a;
  REP(i,n){
    int tmp;
    cin>>tmp;
   a.push_back(tmp);
  }
  /*
  REP(i,n){
    if(i==n-1){
      b += m*a[i];
      cout<<b<<endl;
    }else if(m==0&&a[i]<=a[i+1]){
      m = b/a[i];
      b %= a[i];
    }else if(m!=0&&a[i]>=a[i+1]){
      b += m*a[i];
      m = 0;
    }
  }
  */
  int result = b;
  REP(i,n)
    FOR(j,i+1,n){
      result = max(result,(b/a[i])*a[j] + b%a[i]);
    }
  cout<<result<<endl;
  return 0;
}