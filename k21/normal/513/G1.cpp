#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>

using namespace std;
#define DEBUG(x) cerr << '>' << #x << ':' << (x) << endl;
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define FORD(i,a,b) for(int i=(a);i>=(b);--i)
#define REP(i,a) for(int i=0; i<(a);++i)
inline bool EQ(double a, double b) {return fabs(a-b) < 1e-9;}

const int INF = 1<<29;
typedef long long ll;

int N, K;

vector<vector<int>> swapTimes(const vector<int> p, int k) {
  if (k == 0) return vector<vector<int>>(1, p);
  vector<vector<int>> ans;
  for (const vector<int>& pp : swapTimes(p, k-1)) {
    REP(b,N) FOR(e,b+1,N) {
      vector<int> ppp = pp;
      reverse(ppp.begin() + b, ppp.begin() + e);
      ans.push_back(ppp);
    }
  }
  return ans;
}

int inversions(const vector<int> p) {
  int ans = 0;
  REP(i,N) FOR(j,i+1,N-1) {
    if (p[i] > p[j]) ++ans;
  }
  return ans;
}

int main() {
  scanf("%d%d", &N, &K);

  vector<int> p;
  REP(i,N) {
    int a;
    scanf("%d", &a);
    p.push_back(a);
  }
  vector<vector<int>> s = swapTimes(p, K);
  double a = 0, b = 0;
  for (const vector<int>& q : s) {
    a += inversions(q);
    b += 1;
  }
  printf("%.15lf\n", a/b);
  
  return 0;
}