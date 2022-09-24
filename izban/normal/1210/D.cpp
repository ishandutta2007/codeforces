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
#include <numeric>

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

vector<ll> fast(int n, vector<pair<int, int>> eed, vector<int> vv) {
    struct edge {
        int u, v;
        int pos_in, pos_out;
    };
    vector<edge> ed;
    for (auto o : eed) {
        if (o.first > o.second) swap(o.first, o.second);
        ed.push_back({o.first, o.second, -1, -1});
    }

    ll bad = 0;
    vector<int> val(n);
    iota(val.begin(), val.end(), 0);
    vector<vector<int>> in(n), out(n);

    auto add = [&](int id) {
        int u = ed[id].u;
        int v = ed[id].v;
        if (val[u] > val[v]) swap(u, v);

        ed[id].pos_in = in[u].size();
        ed[id].pos_out = out[v].size();
        in[u].push_back(id);
        out[v].push_back(id);

        bad += out[u].size();
        bad += in[v].size();
    };

    auto del = [&](int id) {
        int u = ed[id].u;
        int v = ed[id].v;
        if (val[u] > val[v]) swap(u, v);

        bad -= out[u].size();
        bad -= in[v].size();

        swap(in[u].back(), in[u][ed[id].pos_in]);
        ed[in[u][ed[id].pos_in]].pos_in = ed[id].pos_in;
        ed[id].pos_in = -1;
        in[u].pop_back();


        swap(out[v].back(), out[v][ed[id].pos_out]);
        ed[out[v][ed[id].pos_out]].pos_out = ed[id].pos_out;
        ed[id].pos_out = -1;
        out[v].pop_back();
    };

    for (int i = 0; i < (int)ed.size(); i++) {
        add(i);
    }

    vector<ll> ans;
    ans.push_back(bad);

    int cc = n;
    for (auto v : vv) {
        auto ids = in[v];
        for (int id : ids) del(id);
        val[v] = cc++;
        for (int id : ids) add(id);
        ans.push_back(bad);
    }
    return ans;
}

void print(vector<ll> v) {
    for (auto x : v) printf("%lld\n", x);
}

int main() {
#ifdef LOCAL
  freopen("in", "r", stdin);
#endif

  int n, m;
  bool first =1 ;
  while (scanf("%d%d", &n, &m) == 2) {
      if (!first) printf("\n");
      else first = 0;
      vector<pair<int, int>> ed(m);
      for (int i = 0; i < m; i++) {
          scanf("%d%d", &ed[i].first, &ed[i].second);
          ed[i].first--;
          ed[i].second--;
      }
      int q;
      scanf("%d", &q);
      vector<int> v(q);
      for (int i =0; i< q; i++) {
          scanf("%d", &v[i]);
          v[i]--;
      }

      print(fast(n, ed, v));
  }

  return 0;
}