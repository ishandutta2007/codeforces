#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <cstdio>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

typedef long long llint;

const int MAX = 500500;
const int mod = 1e9 + 7;

inline int add(int a, int b) {
  return a+b >= mod ? a+b-mod : a+b;
}

inline int sub(int a, int b) {
  return a >= b ? a-b : a-b+mod;
}

inline int mul(int a, int b) {
  return llint(a)*b % mod;
}

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

char a[MAX];
int n, x, y;
vector<pair<vector<int>, int>> ch;

int solve(int h, int w, vector<int> d) {

  int ans = 0;
  vector<int> nd = d;
  
  int i = 0;
  while (i < (int)ch.size()) {
    if (h == 0 || w == 0) break;

    int lo = i, hi = (int)ch.size() - 1;
    while (lo < hi) {
      int mid = (lo + hi) / 2;

      bool ok = true;
      REP(k, 4) ok &= (ch[mid].first[k] - (i > 0 ? ch[i-1].first[k] : 0)) <= d[k];

      if (ok) lo = mid + 1; else
        hi = mid;
    }
    
    if (lo - 1 >= i) {
      REP(k, 4) d[k] -= (ch[lo-1].first[k] - (i > 0 ? ch[i-1].first[k] : 0));
    }
    
    if (lo < (int)ch.size()) {
      int p = -1;
      REP(k, 4) {
        int diff = ch[lo].first[k] - (lo > 0 ? ch[lo-1].first[k] : 0);
        if (diff == 1) { p = k; break; }
      }
      assert(p != -1);

      if (d[p] > 0) d[p]--;
      else {
        nd[p]++;
        if (p % 2) {
          ans = add(ans, mul(h, ch[lo].second + 1));
          w--;
        } else {
          ans = add(ans, mul(w, ch[lo].second + 1));
          h--;
        }
      }
    }

    i = lo + 1;
  }

  if (h == 0 || w == 0) return ans;
  if (x == 0 && y == 0) return -1;
  ans = add(ans, mul(mul(w, h), n));

  if (x > 0) nd[2] -= x;
  if (x < 0) nd[0] += x;
  if (y > 0) nd[1] -= y;
  if (y < 0) nd[3] += y;

  ans = add(ans, solve(h, w, nd));
  return ans;
}

int main(void) {
  int h, w;
  scanf("%d %d %d", &n, &h, &w);
  scanf("%s", a);
  REP(i, n) {
    if (a[i] == 'U') a[i] = 0;
    else if (a[i] == 'R') a[i] = 1;
    else if (a[i] == 'D') a[i] = 2;
    else a[i] = 3;
  }

  x = 0, y = 0;
  int minx = 0, maxx = 0;
  int miny = 0, maxy = 0;

  vector<int> d = {0, 0, 0, 0};
  REP(i, n) {
    x += dx[a[i]], y += dy[a[i]];
    if (x < minx) {
      d[0]++;
      ch.push_back({d, i}), minx = x;
    }
    if (y > maxy) {
      d[1]++;
      ch.push_back({d, i}), maxy = y;
    }
    if (x > maxx) {
      d[2]++;
      ch.push_back({d, i}), maxx = x;
    }
    if (y < miny) {
      d[3]++;
      ch.push_back({d, i}), miny = y;
    }
  }

  printf("%d\n", solve(h, w, {0, 0, 0, 0}));
  return 0;
}