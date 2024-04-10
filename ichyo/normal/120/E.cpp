#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <fstream>

using namespace std;

#define FOR(i,k,n) for(int i=(k); i<(int)n; ++i)
#define REP(i,n) FOR(i,0,n)
#define FORIT(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)

int main(){
  ofstream ofs("output.txt");
  ifstream ifs("input.txt");
  int T;
  ifs>>T;
  while(T--){
    int n;
    ifs>>n;
    ofs<<(n+1)%2<<endl;
  }
  return 0;
}