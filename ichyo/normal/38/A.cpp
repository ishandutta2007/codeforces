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
  int n;
  int a,b;
  int d[100];
  int count=0;
  cin>>n;
  REP(i,n-1){
    cin>>d[i];
  }
  cin>>a>>b;
  for(int i=a-1;i<b-1;i++){
    count+=d[i];
  }
  cout<<count<<endl;
  return 0;
}