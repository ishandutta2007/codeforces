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

int N;
int MAXPOW = 8;
vector<int> coef;
vector<int> ans;

int main() {
  scanf("%d", &N);
  int p = 1;
  REP(i,MAXPOW) {
    p *= 10;
  }
  REP(i,MAXPOW) {
    p /= 10;
    int c = 0;
    while (N >= p) {
      N -= p;
      ++c;
    }
    coef.push_back(c);
  }
  bool done = false;
  while (!done) {
    int out = 0;
    int p = 1;
    REP(i,MAXPOW) {
      p *= 10;
    }
    REP(i,MAXPOW) {
      p /= 10;
      if (coef[i] > 0) {
        --coef[i];
        out += p;
      }
    }
    if (out == 0) {
      done = true;
    } else {
      ans.push_back(out);
    }
  }
  printf("%d\n", (int)ans.size());
  REP(i,(int)ans.size()) {
    printf("%d%c", ans[i], i == (int)ans.size() - 1 ? '\n' : ' ');
  }
  return 0;
}