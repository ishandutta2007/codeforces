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
string fs = "><+-.,[]";

int main(){
  int ans = 0;
  string input;
  cin>>input;
  REP(i,input.size()){
    REP(j,fs.size()){
      if(input[i] == fs[j]){
        ans = (ans * 16 + 8 + j)%1000003;
      }
    }
  }
  cout<<ans<<endl;
  return 0;
}