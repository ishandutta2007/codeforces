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

int main(void){
  string html;
  string in;
  while(getline(cin,in)) html+=in;
  stack<int> stk;
  int now=-1;
  vector<int> ans;
  for(int i=0; i<(int)html.size(); i++){
    if(html.substr(i,7)=="<table>"){
      if(now>-1) stk.push(now);
      now = 0;
    }else if(html.substr(i,8)=="</table>"){
      ans.push_back(now);
      if(stk.empty()) now = -1;
      else{
        now = stk.top();
        stk.pop();
      }
    }else if(html.substr(i,4)=="<td>"){
      now++;
    }
  }
  sort(ans.begin(),ans.end());
  REP(i,ans.size()){
    if(i) cout<<" ";
    cout<<ans[i];
  }
  cout<<endl;
  return 0;
}