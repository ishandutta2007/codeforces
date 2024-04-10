#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>

using namespace std;

#define FOR(i,k,n) for(int i=(k); i<(int)n; ++i)
#define REP(i,n) FOR(i,0,n)
#define FORIT(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)

int main(){
  int n;
  int a[100];
  cin>>n;
  REP(i,n)cin>>a[i];
  int sum = 0;
  int odd = 0;
  REP(i,n)sum += a[i];
  REP(i,n)if(a[i]%2)odd++;
  if(sum % 2)cout<<odd<<endl;
  else cout<<n-odd<<endl;

  return 0;
}