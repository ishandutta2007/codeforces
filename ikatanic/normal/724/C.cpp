#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <map>
#include <set>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

typedef long long llint;

const int MAX = 100100;

llint qans[MAX];
int qx[MAX], qy[MAX];
map<int, set<pair<int, int>>> qd;
map<int, set<pair<int, int>>> qs;

int main(void) {
  int n, m, k;
  scanf("%d %d %d", &n, &m, &k);
  REP(i, k) {
    scanf("%d %d", &qx[i], &qy[i]);
    qd[qx[i]-qy[i]].insert({qx[i], i});
    qs[qx[i]+qy[i]].insert({qx[i], i});
    qans[i] = -1;
  }

  int d = 0;
  int x = 0, y = 0;
  llint t = 0;
  while (true) {
    if (d == 0) {
      int px = n - x;
      int py = m - y;

      int k = min(px, py);
      
      // x .. x + k
      if (qd.count(x-y)) {
        auto& S = qd[x-y];
        while (true) {
          auto it = S.lower_bound({x, -1});
          if (it == S.end() || it->first > x + k) break;
          qans[it->second] = t + it->first - x;
          qs[qx[it->second]+qy[it->second]].erase(*it);

          S.erase(it);
        }
      }

      x += k;
      y += k;
      t += k;
      if (x == n && y == m) break;
      else if (x == n) d = 1;
      else if (y == m) d = 3;
      else assert(false);
    } else if (d == 1) {
      int px = x;
      int py = m - y;

      int k = min(px, py);

      // x - k .. x
      if (qs.count(x+y)) {
        auto& S = qs[x+y];
        while (true) {
          auto it = S.lower_bound({x - k, -1});
          if (it == S.end() || it->first > x) break;
          qans[it->second] = t + (x - it->first);
          qd[qx[it->second]-qy[it->second]].erase(*it);

          S.erase(it);
        }
      }

      x -= k;
      y += k;
      t += k;
      if (x == 0 && y == m) break;
      else if (x == 0) d = 0;
      else if (y == m) d = 2;
      else assert(false);
    } else if (d == 2) {
      int px = x;
      int py = y;

      int k = min(px, py);

      // x - k .. x
      if (qd.count(x-y)) {
        auto& S = qd[x-y];
        while (true) {
          auto it = S.lower_bound({x - k, -1});
          if (it == S.end() || it->first > x) break;
          qans[it->second] = t + (x - it->first);
           qs[qx[it->second]+qy[it->second]].erase(*it);

          S.erase(it);
        }
      }

      x -= k;
      y -= k;
      t += k;
      if (x == 0 && y == 0) break;
      else if (x == 0) d = 3;
      else if (y == 0) d = 1;
      else assert(false);
    } else if (d == 3) {
      int px = n - x;
      int py = y;

      int k = min(px, py);

      // x .. x + k
      if (qs.count(x+y)) {
        auto& S = qs[x+y];
        while (true) {
          auto it = S.lower_bound({x, -1});
          if (it == S.end() || it->first > x + k) break;
          qans[it->second] = t + it->first - x;
          qd[qx[it->second]-qy[it->second]].erase(*it);

          S.erase(it);
        }
      }

      x += k;
      y -= k;
      t += k;
      if (x == n && y == 0) break;
      else if (x == n) d = 2;
      else if (y == 0) d = 0;
      else assert(false);
    }
  }
    

  REP(i, k) printf("%lld\n", qans[i]);
  return 0;
}