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
vector<int> rotate(vector<int> vec){
  vector<int> ret;
  REP(i,3){
    ret.push_back(vec[i+1]);
  }
  ret.push_back(vec[0]);
  return ret;
}
int main(void){
  int n;
  set<vector<int> > ans;
  string in;
  cin>>n;
  while(n--){
    vector<int> pi;
    cin>>in;
    REP(i,2){
      int tmp = in[i]-'0';
      pi.push_back(tmp);
    }
    cin>>in;
    REP(i,2){
      int tmp = in[1-i]-'0';
      pi.push_back(tmp);
    }
    if(n)cin>>in;
    bool f = true;
    REP(i,4){
      if(ans.find(pi)!=ans.end()){
        f=false;
        break;
      }
      pi = rotate(pi);
    }
    if(f){
      ans.insert(pi);
    }
  }
  cout<<(int)ans.size()<<endl;
  return 0;
}