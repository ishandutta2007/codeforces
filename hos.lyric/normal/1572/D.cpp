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

namespace MCF {
	#define MAXN 100'010
	#define MAXM 100'010
	#define wint int
	#define cint int
	const wint wEPS = 0;
	const wint wINF = 1001001001;
	const cint cEPS = 0;
	const cint cINF = 1001001001;
	int n, m, ptr[MAXN], next[MAXM], zu[MAXM];
	wint capa[MAXM], tof;
	cint cost[MAXM], toc, d[MAXN], pot[MAXN];
	int vis[MAXN], pree[MAXN];
	void init(int _n) {
		n = _n; m = 0; memset(ptr, ~0, n << 2);
	}
	void ae(int u, int v, wint w, cint c) {
		next[m] = ptr[u]; ptr[u] = m; zu[m] = v; capa[m] = w; cost[m] = +c; ++m;
		next[m] = ptr[v]; ptr[v] = m; zu[m] = u; capa[m] = 0; cost[m] = -c; ++m;
	}
	bool solve(int src, int ink, wint flo = wINF) {
		wint f;
		cint c, cc;
		int i, u, v;
		memset(pot, 0, n * sizeof(cint));
	/*
		for (bool cont = 1; cont; ) {
			cont = 0;
			for (u = 0; u < n; ++u) for (i = ptr[u]; ~i; i = next[i]) if (capa[i] > wEPS) {
				if (pot[zu[i]] > pot[u] + cost[i] + cEPS) {
					pot[zu[i]] = pot[u] + cost[i]; cont = 1;
				}
			}
		}
	//*/
		for (toc = 0, tof = 0; tof + wEPS < flo; ) {
			typedef pair<cint,int> node;
			priority_queue< node,vector<node>,greater<node> > q;
			for (u = 0; u < n; ++u) { d[u] = cINF; vis[u] = 0; }
			for (q.push(make_pair(d[src] = 0, src)); !q.empty(); ) {
				c = q.top().first; u = q.top().second; q.pop();
				if (vis[u]++) continue;
				for (i = ptr[u]; ~i; i = next[i]) if (capa[i] > wEPS) {
					cc = c + cost[i] + pot[u] - pot[v = zu[i]];
					if (d[v] > cc) { q.push(make_pair(d[v] = cc, v)); pree[v] = i; }
				}
			}
			if (!vis[ink]) return 0;
			f = flo - tof;
			for (v = ink; v != src; v = zu[i ^ 1]) { i = pree[v]; chmin(f, capa[i]); }
			for (v = ink; v != src; v = zu[i ^ 1]) { i = pree[v]; capa[i] -= f; capa[i ^ 1] += f; }
			tof += f;
			toc += f * (d[ink] - pot[src] + pot[ink]);
			for (u = 0; u < n; ++u) pot[u] += d[u];
		}
		return 1;
	}
}


unsigned xrand() {
  static unsigned x = 314159265, y = 358979323, z = 846264338, w = 327950288;
  unsigned t = x ^ x << 11; x = y; y = z; z = w; return w = w ^ w >> 19 ^ t ^ t >> 8;
}


constexpr int MAX_N = 20;
constexpr int LIM_E = 20'000;

int N, K;
int A[1 << MAX_N];

bool side[1 << MAX_N];
int esLen;
pair<int, pair<int, int>> es[MAX_N << (MAX_N - 1)];

int V;
int ids[1 << MAX_N];

int main() {
  for (; ~scanf("%d%d", &N, &K); ) {
if(N<0){
N=-N;
for(int u=0;u<1<<N;++u)A[u]=xrand()%1'000'001;
}else{
    for (int u = 0; u < 1 << N; ++u) {
      scanf("%d", &A[u]);
    }
}
    
    const int maxA = *max_element(A, A + (1 << N));
    for (int u = 0; u < 1 << N; ++u) {
      A[u] = maxA - A[u];
    }
    
    esLen = 0;
    for (int u = 0; u < 1 << N; ++u) {
      side[u] = __builtin_parity(u);
      if (!side[u]) {
        for (int j = 0; j < N; ++j) {
          const int v = u ^ 1 << j;
          es[esLen++] = make_pair(A[u] + A[v], make_pair(u, v));
        }
      }
    }
    const int E = min(esLen, LIM_E);
    partial_sort(es, es + E, es + esLen);
// cerr<<"es = ";pv(es,es+E);
    
    V = 0;
    fill(ids, ids + (1 << N), -1);
    for (int i = 0; i < E; ++i) {
      const int u = es[i].second.first;
      const int v = es[i].second.second;
      if (!~ids[u]) ids[u] = V++;
      if (!~ids[v]) ids[v] = V++;
    }
    
    MCF::init(V + 2);
    for (int u = 0; u < 1 << N; ++u) {
      if (~ids[u]) {
        if (!side[u]) {
          MCF::ae(V, ids[u], 1, A[u]);
        } else {
          MCF::ae(ids[u], V + 1, 1, A[u]);
        }
      }
    }
    for (int i = 0; i < E; ++i) {
      const int u = es[i].second.first;
      const int v = es[i].second.second;
      MCF::ae(ids[u], ids[v], 1, 0);
    }
    MCF::solve(V, V + 1, K);
    const int ans = 2 * MCF::tof * maxA - MCF::toc;
    printf("%d\n", ans);
  }
  return 0;
}