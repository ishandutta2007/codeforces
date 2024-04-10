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


const int MAXN = 110000;
int N, K;
vector<pair<ll, ll>> points;
vector<int> vorder;
vector<int> horder;
set<int> dropped;

ll dropLeft(int n) {
  int ii = 0;
  while (true) {
    int i = horder[ii++];
    if (dropped.count(i)) continue;
    if (!n) return points[i].first;
    dropped.insert(i);
    --n;
  }
}

ll dropRight(int n) {
  int ii = horder.size() - 1;
  while (true) {
    int i = horder[ii--];
    if (dropped.count(i)) continue;
    if (!n) return points[i].first;
    dropped.insert(i);
    --n;
  }
}

ll dropTop(int n) {
  int ii = 0;
  while (true) {
    int i = vorder[ii++];
    if (dropped.count(i)) continue;
    if (!n) return points[i].second;
    dropped.insert(i);
    --n;
  }
}

ll dropBot(int n) {
  int ii = vorder.size() - 1;
  while (true) {
    int i = vorder[ii--];
    if (dropped.count(i)) continue;
    if (!n) return points[i].second;
    dropped.insert(i);
    --n;
  }
}

int main() {
  scanf("%d%d", &N, &K);
  REP(i,N) {
    int X1, Y1, X2, Y2;
    scanf("%d%d%d%d", &X1, &Y1, &X2, &Y2);
    points.emplace_back(X1 + X2, Y1 + Y2);
    vorder.push_back(i);
    horder.push_back(i);
  }
  sort(vorder.begin(), vorder.end(), [](int i1, int i2) {
        return points[i1].second < points[i2].second;
      });
  sort(horder.begin(), horder.end(), [](int i1, int i2) {
        return points[i1].first < points[i2].first;
      });
  ll best = 1000000000LL * 1000000000LL;

  REP(left, K+1) REP(right, K+1-left) REP(top, K+1-left-right) {
    int bot = K - left - right - top;
    ll minX = dropLeft(left);
    ll maxX = dropRight(right);
    ll minY = dropTop(top);
    ll maxY = dropBot(bot);
    ll dX = max(1LL, (maxX - minX + 1) / 2);
    ll dY = max(1LL, (maxY - minY + 1) / 2);
    best = min(best, dX * dY);
    dropped.clear();
  }

  cout << best << endl;

  return 0;
}