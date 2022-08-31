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
	const int LIM_N = 100010;
	const int LIM_M = 100010;
	typedef Int wint;
	const wint wEPS = 0;
	const wint wINF = 1001001001001001001LL;
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
}


constexpr Int BIG = 1001001001LL;

int N, M, K, Q;
vector<int> A, B, C;
vector<vector<int>> W;

int main() {
  for (; ~scanf("%d%d%d%d", &N, &M, &K, &Q); ) {
    A.resize(M);
    B.resize(M);
    C.resize(M);
    for (int i = 0; i < M; ++i) {
      scanf("%d%d%d", &A[i], &B[i], &C[i]);
      --A[i];
      --B[i];
    }
    W.assign(Q, vector<int>(K));
    for (int q = 0; q < Q; ++q) {
      for (int i = 0; i < K; ++i) {
        scanf("%d", &W[q][i]);
      }
    }
    
    vector<Int> flows(1 << K);
    for (int p = 0; p < 1 << K; ++p) {
      MF::init(N);
      for (int i = 0; i < K; ++i) {
        if (p & 1 << i) {
          MF::ae(A[i], B[i], BIG);
        }
      }
      for (int i = K; i < M; ++i) {
        MF::ae(A[i], B[i], C[i]);
      }
      MF::solve(0, N - 1);
      flows[p] = MF::tof;
    }
    
    for (int q = 0; q < Q; ++q) {
      vector<Int> sums(1 << K, 0);
      for (int i = 0; i < K; ++i) {
        for (int p = 0; p < 1 << i; ++p) {
          sums[p | 1 << i] = sums[p] + W[q][i];
        }
      }
      Int ans = BIG;
      for (int p = 0; p < 1 << K; ++p) {
        chmin(ans, flows[p] + sums[((1 << K) - 1) ^ p]);
      }
      printf("%lld\n", ans);
    }
  }
  
  return 0;
}