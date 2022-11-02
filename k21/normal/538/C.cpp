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

int N, M;
vector<pair<int, int>> H;

int consider(pair<int, int> p1, pair<int, int> p2) {
  int t = p2.first - p1.first;
  int hd = p2.second - p1.second;
  if (abs(hd) > t) {
    return -1;
  }
  int l = t - abs(hd);
  int mh = max(p1.second, p2.second);
  return mh + l / 2;
}

int main() {
  scanf("%d%d", &N, &M);
  REP(i,M) {
    int d, h;
    scanf("%d%d", &d, &h);
    H.push_back({d-1, h});
  }
  int best = max(H[0].second + H[0].first, H[M-1].second + N - 1 - H[M-1].first);
  REP(i,M-1) {
    int t = consider(H[i], H[i+1]);
    if (t < 0) {
      printf("IMPOSSIBLE\n");
      return 0;
    }
    best = max(best, t);
  }
  printf("%d\n", best);
  return 0;
}