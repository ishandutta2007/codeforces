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
  string s;
  string q = "HQ9";
  cin>>s;
  REP(i,s.size()){
    char c = s[i];
    REP(j,3)if(c==q[j]){
      cout<<"YES"<<endl;
      goto END;
    }
  }
  cout<<"NO"<<endl;
END:
  return 0;
}