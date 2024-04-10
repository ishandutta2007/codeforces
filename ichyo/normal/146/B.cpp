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
string mask(int n){
  stringstream ss;
  ss<<n;
  string s = ss.str();
  string ret ;
  REP(i,s.size()){
    if(s[i]=='4'||s[i]=='7'){
      ret += s[i];
    }
  }
  return ret;
}

int main(){
  int a;
  string b;
  cin>>a>>b;
  for(int i = a+1; ;i++){
    if(mask(i)==b){
      cout<<i<<endl;
      goto END;
    }
  }
END:
  return 0;
}