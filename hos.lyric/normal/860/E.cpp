#include <cassert>
#include <cmath>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

using Int = long long;

template <class T1, class T2> ostream &operator<<(ostream &os, const pair<T1, T2> &a) { return os << "(" << a.first << ", " << a.second << ")"; };
template <class T> void pv(T a, T b) { for (T i = a; i != b; ++i) cerr << *i << " "; cerr << endl; }
template <class T> bool chmin(T &t, const T &f) { if (t > f) { t = f; return true; } return false; }
template <class T> bool chmax(T &t, const T &f) { if (t < f) { t = f; return true; } return false; }


int N;
vector<int> P;

vector<vector<int>> graph;
vector<vector<int>> uss;
vector<int> sigs;
vector<int> poss;

vector<int> sz, dep;
int O;
vector<int> ord, head;

void dfs0(int u, int p) {
  sz[u] = 1;
  dep[u] = (p == -1) ? 0 : (dep[p] + 1);
  for (const int v : graph[u]) {
    dfs0(v, u);
    sz[u] += sz[v];
  }
}

void dfs1(int u, int p, int h) {
  ord[u] = O++;
  head[u] = h;
  int vm = -1;
  for (const int v : graph[u]) {
    if (vm == -1 || sz[vm] < sz[v]) {
      vm = v;
    }
  }
  if (vm != -1) {
    dfs1(vm, u, h);
    for (const int v : graph[u]) {
      if (v != vm) {
        dfs1(v, u, v);
      }
    }
  }
}


int bitN;
Int bit0[500010], bit1[500010];
//	[a, b)
// void bitRangeAdd(int a, int b, Int val) {
	// for (int x = max(a, 1); x <= bitN; x += x & -x) bit0[x] -= val * a, bit1[x] += val;
	// for (int x = max(b, 1); x <= bitN; x += x & -x) bit0[x] += val * b, bit1[x] -= val;
// }
void bitRangeIncr(int a, int b) {
	for (int x = max(a, 1); x <= bitN; x += x & -x) bit0[x] -= a, bit1[x] += 1;
	for (int x = max(b, 1); x <= bitN; x += x & -x) bit0[x] += b, bit1[x] -= 1;
}
//	[0, a)
Int bitSum(int a) {
	Int sum0 = 0, sum1 = 0;
	for (int x = a; x > 0; x &= x - 1) sum0 += bit0[x], sum1 += bit1[x];
	return sum0 + sum1 * a;
}


int main() {
  for (; ~scanf("%d", &N); ) {
    P.resize(N);
    for (int u = 0; u < N; ++u) {
      scanf("%d", &P[u]);
      --P[u];
    }
// cerr<<"P = ";pv(P.begin(),P.end());
    int rt = -1;
    graph.assign(N, {});
    for (int u = 0; u < N; ++u) {
      if (P[u] == -1) {
        rt = u;
      } else {
        graph[P[u]].push_back(u);
      }
    }
    
    sz.resize(N);
    dep.resize(N);
    dfs0(rt, -1);
    O = 0;
    ord.resize(N);
    head.resize(N);
    dfs1(rt, -1, rt);
// cerr<<"ord = ";pv(ord.begin(),ord.end());
// cerr<<"head = ";pv(head.begin(),head.end());
    
    vector<vector<int>> uss(N);
    for (int u = 0; u < N; ++u) {
      uss[dep[u]].push_back(u);
    }
    
    bitN = N;
    fill(bit0, bit0 + N + 1, 0);
    fill(bit1, bit1 + N + 1, 0);
    vector<Int> ans(N);
    for (int d = 0; d < N; ++d) {
      for (const int u : uss[d]) {
        for (int v = u; v != -1; ) {
          const Int h = head[v];
          bitRangeIncr(ord[h], ord[v] + 1);
          v = P[h];
        }
      }
      for (const int u : uss[d]) {
        Int sum = 0;
        for (int v = u; v != -1; ) {
          const Int h = head[v];
          sum += bitSum(ord[v] + 1) - bitSum(ord[h]);
          v = P[h];
        }
        ans[u] = sum - d - 1;
      }
    }
    
    for (int u = 0; u < N; ++u) {
      if (u > 0) printf(" ");
      printf("%lld", ans[u]);
    }
    puts("");
  }
  return 0;
}