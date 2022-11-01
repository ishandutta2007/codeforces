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
  bool check[1000]={0};
  int n;
  cin>>n;
  int i= 0;
  REP(k,100000){
    check[i] = true;
    i = (i+k)%n;
  }
  bool ans = true;
  REP(j,n){
    if(check[j]==false){
      ans = false;
      break;
    }
  }
  if(ans) cout<<"YES"<<endl;
  else cout<<"NO"<<endl;
     
  return 0;
}