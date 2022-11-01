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
LL dfs(vector<LL> &n, vector<char> &e){
  if(n.size()==1) return n[0];
  LL ret=1e18;
  for(int i=0; i<n.size(); i++){
    for(int j = i+1; j<n.size(); j++){
      LL a = n[i], b = n[j];
      for(int k = 0; k<e.size(); k++){
        vector<LL> newn;
        vector<char> newe;
        REP(r,n.size())if(r!=i&&r!=j) newn.push_back(n[r]);
        REP(r,e.size())if(r!=k) newe.push_back(e[r]);
        if(e[k]=='+'){
          newn.push_back(a+b);
        }else{
          newn.push_back(a*b);
        }
        ret = min(ret, dfs(newn,newe) );
        break;
      }
    }
  }
  return ret;
}
          
int main(void){
  vector<LL> n(4);
  REP(i,4)cin>>n[i];
  vector<char> e(3);
  REP(i,3)cin>>e[i];
  cout<<dfs(n,e)<<endl;
  return 0;
}