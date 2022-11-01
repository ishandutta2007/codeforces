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
  cin>>n;
  vector<int> ans;
  ans.push_back(n);
  while(n!=1){
    FOR(i,2,n+1){
      if(n % i == 0){
        n /= i;
        ans.push_back(n);
        break;
      }
    }
  }
  REP(i,ans.size()){
    cout<<ans[i];
    putchar((i==ans.size()-1)?'\n':' ');
  }
  return 0;
}