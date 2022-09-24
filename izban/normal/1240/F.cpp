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
#include <random>

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

void print(vector<int> v) {
    for (int x : v) printf("%d\n", x);
}

const int INF = 1e9;

vector<int> solve(int n, int m, int k, vector<int> w, vector<pair<int, int>> ee) {
    struct edge {
        int u, v, id;
    };
    vector<edge> ed;
    for (int i = 0; i < (int)ee.size(); i++) {
        ed.push_back({ee[i].first, ee[i].second, i});
    }

    mt19937 rnd(5453);
    while (1) {
        shuffle(ed.begin(), ed.end(), rnd);
        vector<int> col(m);
        vector<vector<int>> cnt(n, vector<int>(k));
        for (int i = 0; i < m; i++) {
            int cval = INF;
            int ccol = -1;
            for (int c = 0; c < k; c++) {
                int val = cnt[ed[i].v][c] + cnt[ed[i].u][c];
                if (cval > val) {
                    cval = val;
                    ccol = c;
                }
            }
            cnt[ed[i].v][ccol]++;
            cnt[ed[i].u][ccol]++;
            col[ed[i].id] = ccol + 1;
        }
        bool ok = 1;
        for (int i = 0; i < n; i++) {
            ok &= *max_element(cnt[i].begin(), cnt[i].end()) - *min_element(cnt[i].begin(), cnt[i].end()) <= 2;
            if (!ok) break;
        }
        if (ok) return col;
    }
}

int main() {
#ifdef LOCAL
  freopen("in", "r", stdin);
#endif

  int n, m, k;
  while (scanf("%d%d%d", &n, &m, &k) == 3) {
      vector<int> w(n);
      for (int i = 0; i < n; i++) scanf("%d", &w[i]);
      vector<pair<int, int>> ed(m);
      for (int i = 0; i < m; i++) {
          scanf("%d%d", &ed[i].first, &ed[i].second);
          ed[i].first--;
          ed[i].second--;
      }

      print(solve(n, m, k, w, ed));
  }

  return 0;
}