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
  string s;
  cin>>n>>s;
  bool lucky = true;
  REP(i,n)if(s[i]!='4'&&s[i]!='7') lucky = false;
  int a = 0;
  int b = 0;
  REP(i,n/2){
    a += s[i]-'0';
    b += s[n/2+i]-'0';
  }
  if(lucky&&a==b)cout<<"YES"<<endl;
  else cout<<"NO"<<endl;

  return 0;
}