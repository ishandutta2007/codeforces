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
  int n,l,a[100];
  cin>>n>>l;
  REP(i,n){
    cin>>a[i];
  }
  int summ = 0;
  FOR(k,l,101){
    int sum=0;
    REP(i,n){
      if(a[i]>=k){
        sum+=a[i]/k * k;
      }
    }
    summ = max(summ,sum);
  }
  cout<<summ<<endl;
  return 0;
}