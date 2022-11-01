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
static const double EPS = 1e-8;

#define FOR(i,k,n) for (int i=(k); i<(int)(n); ++i)
#define REP(i,n) FOR(i,0,n)

int main(void){
  int n;
  cin>>n;
  double lower=1,upper=1e8;
  REP(i,n){
    int sta;
    cin>>sta;
    lower = max((double)sta*(n+1)/(i+1),lower);
    upper = min((double)(sta+1)*(n+1)/(i+1),upper);
  }
  if((int)(lower)==(int)(upper-EPS)){
    cout<<"unique"<<endl;
    cout<<(int)(lower)<<endl;
  }else{
    cout<<"not unique"<<endl;
  }
  return 0;
}