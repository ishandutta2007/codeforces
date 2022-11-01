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
  int a,b,c,d,e;
  while(cin>>a>>b>>c>>d>>e){
    int ans = e;
    for(int i = e; i >= 1; i--){
      if(i%a!=0 && i%b!=0 && i%c!=0 && i%d!=0)ans--;
    }
    cout<<ans<<endl;
  }

  return 0;
}