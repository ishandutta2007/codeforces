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
  int n,a,b;
  cin>>n>>a>>b;
  int ans = 0;
  REP(i,n){
    int mae = i;
    int usiro = n - i - 1;
    if(mae >= a&&usiro<=b)ans++;
  }
  cout<<ans<<endl;

  return 0;
}