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
  string a,b;
  cin>>a>>b;
  int m=0,n=0;
  REP(i,a.size()){
    if(a[i]=='4'&&b[i]=='7')m++;
    else if(a[i]=='7'&&b[i]=='4')n++;
  }
  cout<<max(m,n)<<endl;

  return 0;
}