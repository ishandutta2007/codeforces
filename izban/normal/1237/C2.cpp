#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <cstring>
#include <string>
#include <cmath>
#include <cassert>
#include <ctime>
#include <algorithm>
#include <sstream>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <cstdlib>
#include <cstdio>
#include <iterator>
#include <functional>
#include <bitset>

#ifdef LOCAL
#define eprintf(...) fprintf(stderr,__VA_ARGS__)
clock_t __my_start_clock = clock();
#else
#define eprintf(...)
#endif

#define TIMESTAMP(x) eprintf("["#x"] Time : %.3lf s.\n", (clock() - __my_start_clock)*1.0/CLOCKS_PER_SEC)
#define TIMESTAMPf(x,...) eprintf("[" x "] Time : %.3lf s.\n", __VA_ARGS__, (clock() - __my_start_clock)*1.0/CLOCKS_PER_SEC)

#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")\n";
#define db3(x, y, z) cerr << "(" << #x << ", " << #y << ", " << #z << ") = (" << x << ", " << y << ", " << z << ")\n"
#define dbv(a) cerr << #a << " = "; for (auto xxxx: a) cerr << xxxx << " "; cerr << endl


using namespace std;

#ifdef LOCAL
static struct __timestamper {
  string what;
  __timestamper(const char* what) : what(what){};
  __timestamper(const string& what) : what(what){};
  ~__timestamper(){
    TIMESTAMPf("%s", what.data());
	}
} __TIMESTAMPER("end");
#else 
struct __timestamper {};
#endif

typedef long long ll;
typedef long double ld;

int main() {
#ifdef LOCAL
  freopen("in", "r", stdin);
#endif

  int n;
  while (scanf("%d", &n) == 1) {
      struct pt {
          vector<int> x;
          int id;

          pt() {
              id = -1;
          }
      };

      vector<pt> a(n);
      for (int i = 0; i < n; i++) {
          a[i].x.resize(3);
          scanf("%d%d%d", &a[i].x[0], &a[i].x[1], &a[i].x[2]);
          a[i].id = i;
      }

      vector<pair<int, int>> ans;
      function<pt(vector<pt>, int)> rec = [&](vector<pt> a, int lvl) {
          sort(a.begin(), a.end(), [&](const pt &p1, const pt &p2) {
              return p1.x[lvl] < p2.x[lvl];
          });
          if (lvl == 2) {
              for (int i = 0; i + 1< (int)a.size(); i += 2) {
                  ans.emplace_back(a[i].id, a[i + 1].id);
              }
              if (a.size() % 2 == 1) return a.back();
              return pt();
          }
          map<int, vector<pt>> mp;
          for (auto p : a) mp[p.x[lvl]].push_back(p);

          vector<pt> tmp;
          for (auto it : mp) {
              auto nw = rec(it.second, lvl + 1);
              if (nw.id != -1) {
                  tmp.push_back(nw);
              }
          }
          for (int i =0; i + 1 < (int)tmp.size(); i += 2) {
              ans.emplace_back(tmp[i].id, tmp[i + 1].id);
          }
          if (tmp.size() % 2 == 1) return tmp.back();
          return pt();
      };
      rec(a, 0);
      for (auto o : ans) printf("%d %d\n", o.first + 1, o.second + 1);
  }

  return 0;
}