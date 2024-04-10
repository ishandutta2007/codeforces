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
    REP(i,n)cin>>a[i];
    int M=0,m=1000000;
    int Midx = 1000;
    int midx = -1;
    REP(i,n){
      M = max(M,a[i]);
      m = min(m,a[i]);
    }
    REP(i,n){
      if(a[i]==M)Midx = min(Midx,i);
      if(a[i]==m)midx = max(midx,i);
    }
    int ans = Midx + (n-1-midx);
    if(Midx > midx) ans --;
    cout<<ans<<endl;
  }



  return 0;
}