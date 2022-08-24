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


namespace MF {
	const int LIM_N = 5001001;
	const int LIM_M = 5001001;
	typedef int wint;
	const wint wEPS = 0;
	const wint wINF = 1001001001;
	int n, m, ptr[LIM_N], nxt[LIM_M * 2], zu[LIM_M * 2];
	wint capa[LIM_M * 2], tof;
	int lev[LIM_N], see[LIM_N], que[LIM_N], *qb, *qe;
	void init(int _n) {
		n = _n; m = 0; fill(ptr, ptr + n, -1);
	}
	void ae(int u, int v, wint w0, wint w1 = 0) {
		nxt[m] = ptr[u]; ptr[u] = m; zu[m] = v; capa[m] = w0; ++m;
		nxt[m] = ptr[v]; ptr[v] = m; zu[m] = u; capa[m] = w1; ++m;
	}
	wint augment(int src, int ink, wint flo) {
		if (src == ink) return flo;
		for (int &i = see[src]; ~i; i = nxt[i]) if (capa[i] > wEPS && lev[src] < lev[zu[i]]) {
			const wint f = augment(zu[i], ink, min(flo, capa[i]));
			if (f > wEPS) {
				capa[i] -= f; capa[i ^ 1] += f; return f;
			}
		}
		return 0;
	}
	bool solve(int src, int ink, wint flo = wINF) {
		for (tof = 0; tof + wEPS < flo; ) {
			qb = qe = que; fill(lev, lev + n, -1);
			for (lev[*qe++ = src] = 0, see[src] = ptr[src]; qb != qe; ) {
				const int u = *qb++;
				for (int i = ptr[u]; ~i; i = nxt[i]) if (capa[i] > wEPS) {
					const int v = zu[i];
					if (lev[v] == -1) {
						lev[*qe++ = v] = lev[u] + 1; see[v] = ptr[v];
						if (v == ink) goto au;
					}
				}
			}
			return false;
		au:	for (wint f; (f = augment(src, ink, flo - tof)) > wEPS; tof += f);
		}
		return true;
	}

  bool vis[LIM_N];
  void dfs(int u) {
    if (!vis[u]) {
      vis[u] = true;
      for (int i = ptr[u]; ~i; i = nxt[i]) {
        if (capa[i] > wEPS) {
          dfs(zu[i]);
        }
      }
    }
  }
}


constexpr int E = 15;

int N, M;
vector<int> A, B;
vector<int> X, Y;

vector<vector<int>> G;
vector<vector<int>> par;
vector<int> pari;
vector<int> dep;

void dfs(int u, int p, int pi) {
  par[0][u] = p;
  pari[u] = pi;
  dep[u] = (p == -1) ? 0 : (dep[p] + 1);
  for (const int i : G[u]) {
    const int v = A[i] ^ B[i] ^ u;
    if (v != p) {
      dfs(v, u, i);
    }
  }
}

int main() {
  for (; ~scanf("%d%d", &N, &M); ) {
    A.resize(N - 1);
    B.resize(N - 1);
    for (int i = 0; i < N - 1; ++i) {
      scanf("%d%d", &A[i], &B[i]);
      --A[i];
      --B[i];
    }
    X.resize(M);
    Y.resize(M);
    for (int j = 0; j < M; ++j) {
      scanf("%d%d", &X[j], &Y[j]);
      --X[j];
      --Y[j];
    }
    
    G.assign(N, {});
    for (int i = 0; i < N - 1; ++i) {
      G[A[i]].push_back(i);
      G[B[i]].push_back(i);
    }
    par.assign(E, vector<int>(N, -1));
    pari.assign(N, -1);
    dep.assign(N, -1);
    dfs(0, -1, -1);
    
    int V = 2 + M;
    vector<vector<int>> ids(E, vector<int>(N, -1));
    for (int u = 0; u < N; ++u) {
      if (par[0][u] != -1) {
        ids[0][u] = V++;
      }
    }
    for (int e = 1; e < E; ++e) {
      for (int u = 0; u < N; ++u) {
        if (par[e - 1][u] != -1) {
          par[e][u] = par[e - 1][par[e - 1][u]];
          if (par[e][u] != -1) {
            ids[e][u] = V++;
          }
        }
      }
    }
    
    MF::init(V);
    for (int j = 0; j < M; ++j) {
      MF::ae(0, 2 + j, 1);
    }
    for (int j = 0; j < M; ++j) {
      int u = X[j], v = Y[j];
      for (int e = E - 1; e >= 0; --e) {
        if (dep[u] - (1 << e) >= dep[v]) {
          MF::ae(2 + j, ids[e][u], 1);
          u = par[e][u];
        }
        if (dep[v] - (1 << e) >= dep[u]) {
          MF::ae(2 + j, ids[e][v], 1);
          v = par[e][v];
        }
      }
      for (int e = E - 1; e >= 0; --e) {
        if (par[e][u] != par[e][v]) {
          MF::ae(2 + j, ids[e][u], 1);
          u = par[e][u];
          MF::ae(2 + j, ids[e][v], 1);
          v = par[e][v];
        }
      }
      if (u != v) {
        MF::ae(2 + j, ids[0][u], 1);
        u = par[0][u];
        MF::ae(2 + j, ids[0][v], 1);
        v = par[0][v];
      }
    }
    for (int e = E - 1; e > 0; --e) {
      for (int u = 0; u < N; ++u) {
        if (par[e][u] != -1) {
          MF::ae(ids[e][u], ids[e - 1][u], MF::wINF);
          MF::ae(ids[e][u], ids[e - 1][par[e - 1][u]], MF::wINF);
        }
      }
    }
    for (int u = 0; u < N; ++u) {
      if (par[0][u] != -1) {
        MF::ae(ids[0][u], 1, 1);
      }
    }
    MF::solve(0, 1);
    
    fill(MF::vis, MF::vis + V, false);
    MF::dfs(0);
    vector<int> ansJs, ansIs;
    for (int j = 0; j < M; ++j) {
      if (!MF::vis[2 + j]) {
        ansJs.push_back(j);
      }
    }
    for (int u = 0; u < N; ++u) {
      if (par[0][u] != -1) {
        if (MF::vis[ids[0][u]]) {
          ansIs.push_back(pari[u]);
        }
      }
    }
    
    printf("%d\n", MF::tof);
    printf("%d", (int)ansJs.size());
    for (const int j : ansJs) printf(" %d", j + 1);
    puts("");
    printf("%d", (int)ansIs.size());
    for (const int i : ansIs) printf(" %d", i + 1);
    puts("");
  }
  return 0;
}