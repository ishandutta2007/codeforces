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
  string s;
  cin>>s;
  bool f[5] = {};
  string c = "hello";
  int t=0;
  REP(i,s.size()){
    if(t==5) break;
    if(s[i]==c[t]){
      f[t++] = true;
    }
  }
  if(f[4]) cout<<"YES"<<endl;
  else cout<<"NO"<<endl;


  return 0;
}