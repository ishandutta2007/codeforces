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
  while(cin>>n){
    vector<int> a(n);
    vector<int> b(n);
    REP(i,n)cin>>a[i];
    REP(i,n){
      if(a[i]<=n){
        b[a[i]-1] = 1;
      }
    }
    int ans = n;
    REP(i,n)ans -= b[i];
    cout<<ans<<endl;
  }
  return 0;
}