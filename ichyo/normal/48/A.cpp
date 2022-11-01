#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <cstring>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <fstream>
#include <complex>
#include <stack>
#include <queue>

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
static const double EPS = 1e-5;

#define FOR(i,k,n) for (int i=(k); i<(int)(n); ++i)
#define REP(i,n) FOR(i,0,n)
string t[3] = {"rock","scissors","paper"};
string ans[3] = {"F","M","S"};
int main(void){
  string te[3];
  int c[3] = {0};
  REP(i,3)cin>>te[i];
  REP(i,3){
    REP(j,3){
      if(te[i] == t[j]){
        c[j]++;
      }
    }
  }
  bool f= false;
  REP(i,3)if(c[i]==2) f =true;
  if(f){
    int win,lose;
    REP(i,3){
      if(c[i]==2) lose = i;
      if(c[i]==1) win = i;
    }
    if((win+1)%3==lose){
      REP(i,3){
        if(te[i] == t[win]){
          cout<<ans[i]<<endl;
        }
      }
    }else{
      cout<<"?"<<endl;
    }
  }else {
    cout<<"?"<<endl;
  }
  return 0;
}