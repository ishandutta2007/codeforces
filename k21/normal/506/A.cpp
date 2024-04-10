#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <list>
#include <map>
#include <unordered_map>
#include <unordered_set>
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
typedef unsigned int inttype;

int N, D;
inttype gems[60101];
inttype remgems[60101];
vector<pair<inttype, inttype>> sc[60101];
inttype best = 0;

void consider(inttype at, inttype d, inttype v) {
  if (d > 3) {
    at += d;
    sc[at-1].push_back({d-1, v});
    sc[at].push_back({d, v});
    sc[at+1].push_back({d+1, v});
    best = max(best, v);
  } else if (d > 2) {
    best = max(best, v + remgems[at+2]);
  } else {
    best = max(best, v + remgems[at+1]);
  }
}

int main() {
  scanf("%d%d", &N, &D);
  REP(i,N) {
    int pi;
    scanf("%d", &pi);
    ++gems[pi];
  }
  FORD(i,30000,0) {
    remgems[i] = remgems[i+1] + gems[i];
  }

  sc[D].push_back({D, 0});

  REP(i,30001) {
    inttype vv = gems[i];
    inttype lastd = 0;
    inttype bs = 0;
    for (const auto& p : sc[i]) {
      inttype d = p.first;
      inttype v = p.second + vv;

      if (lastd == 0) {
        lastd = d;
        bs = v;
      } else if (d == lastd) {
        bs = max(bs, v);
      } else {
        consider(i, lastd, bs);
        lastd = d;
        bs = v;
      }
    }
    if (lastd != 0) consider(i, lastd, bs);
  }

  printf("%d\n", best);

  return 0;
}