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
  cin>>n;
  int c[100001] = {0};
  vector<int> a(n);
  REP(i,n){
    int tmp;
    cin>>tmp;
    a[i] = tmp;
    c[tmp]++;
  }
  bool ans = true;
  FOR(i,1,100000){
    if(c[i+1]-c[i]>0) ans = false;
  }
  if(ans){
    cout<<c[1]<<endl;
    bool f = false;
    REP(i,n){
      if(f) cout<<" ";
      else f = true;
      cout<<c[a[i]]--;
    }
    cout<<endl;
  }else{
    cout<<-1<<endl;
  }
  return 0;
}