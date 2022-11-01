#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
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
typedef pair<int, int> P;
static const double EPS = 1e-5;

#define FOR(i,k,n) for (int i=(k); i<(int)(n); ++i)
#define REP(i,n) FOR(i,0,n)

int main(void){
  int N;
  vector<int> h;
  set<int> n;
  int tmp;
  cin>>N;
  REP(i,N){
    cin>>tmp;
    h.push_back(tmp);
    n.insert(tmp);
  }
  sort(h.begin(),h.end());
  int max = 1;
  REP(i,1001){
    int l = upper_bound(h.begin(), h.end(), i) - lower_bound(h.begin(), h.end(), i);
    if(l>max) max = l;
  }
  cout<<max<<" "<<n.size()<<endl;
  return 0;
}