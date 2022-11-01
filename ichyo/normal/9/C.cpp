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
int tob(int n){
  int b = 0;
  stack<int> stk;
  while(n){
    stk.push(n%2);
    n/=2;
  }
  while(!stk.empty()){
    b = b*10 + stk.top(); stk.pop();
  }
  stringstream ss;
  ss<<b;
  return atoi(ss.str().c_str());
}

int main(){
  int n;
  cin>>n;
  FOR(ans,2,1024){
    int bnum = tob(ans);
    if(bnum > n){
      cout<<ans-1<<endl;
      break;
    }
  }
  return 0;
}