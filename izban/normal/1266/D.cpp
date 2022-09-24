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

  int n, m;
  while (scanf("%d%d", &n, &m) == 2) {
      struct edge {
          int u, v;
          ll w;
      };
      vector<edge> edges(m);
      for (int i = 0; i < m; i++) {
          scanf("%d%d%lld", &edges[i].u, &edges[i].v, &edges[i].w);
          edges[i].u--;
          edges[i].v--;
      }

      vector<edge> ans;

      set<int> active;
      vector<map<int, ll>> in(n), out(n);
      auto change_edge = [&](int from, int to, ll w) {
          if (w > 0) {
              in[to][from] += w;
              out[from][to] += w;

              if (out[to].size() > 0) active.insert(to);
              if (in[from].size() > 0) active.insert(from);
          } else {
              in[to][from] += w;
              if (in[to][from] == 0) {
                  in[to].erase(from);
              }
              out[from][to] += w;
              if (out[from][to] == 0) {
                  out[from].erase(to);
              }
          }
      };

      for (int i = 0; i < m; i++) {
          change_edge(edges[i].u, edges[i].v, edges[i].w);
      }

      while (!active.empty()) {
          int v = *active.begin();
          active.erase(v);

          while (!in[v].empty() && !out[v].empty()) {
              auto it1 = in[v].begin();
              auto it2 = out[v].begin();
              int l = it1->first;
              int r = it2->first;
              ll k = min(it1->second, it2->second);
              assert(k > 0);
              change_edge(l, v, -k);
              change_edge(v, r, -k);
              if (l != r) {
                  change_edge(l, r, +k);
              }
          }
      }

      for (int i = 0; i < n; i++) {
          for (auto it : out[i]) {
              ans.push_back({i + 1, it.first + 1, it.second});
          }
      }

      printf("%d\n", (int)ans.size());
      for (auto o : ans) {
          printf("%d %d %lld\n", o.u, o.v, o.w);
      }
  }

  return 0;
}