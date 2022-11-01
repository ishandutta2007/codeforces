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
int rvs(int n){
  int ret = 0;
  REP(i,8){
    ret = ret * 2 + n%2;
    n /= 2;
  }
  return ret;
}

int main(){
  string s;
  getline(cin,s);
  REP(i,s.size()){
    int prv = 0;
    int idans = 0;
    if(i) prv = rvs(s[i-1]);
    REP(chk,256){
      if((prv-chk+256)%256 == rvs(s[i])){
        idans = chk;
        break;
      }
    }
    cout<<idans<<endl;
  }
  return 0;
}