#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <utility>
#include <numeric>
#include <algorithm>
#include <bitset>
#include <complex>
#include <unordered_set>
#include <unordered_map>

using namespace std;

typedef unsigned uint;
typedef long long Int;
typedef vector<int> vint;
typedef pair<int,int> pint;
#define mp make_pair

template<typename T> void pv(T a, T b) { for (T i = a; i != b; ++i) cout << *i << " "; cout << endl; }
template<typename T> void chmin(T &t, const T &f) { if (t > f) t = f; }
template<typename T> void chmax(T &t, const T &f) { if (t < f) t = f; }
int in() { int x; scanf("%d", &x); return x; }

namespace MF {
	#define MAXN 100010
	#define MAXM 100010
	#define wint int
	const wint wEPS = 0;
	const wint wINF = 1001001001;
	int n, m, ptr[MAXN], next[MAXM], zu[MAXM];
	wint capa[MAXM], tof;
	int lev[MAXN], see[MAXN], que[MAXN], *qb, *qe;
	void init(int _n) {
		n = _n; m = 0; memset(ptr, ~0, n * 4);
	}
	void ae(int u, int v, wint w0, wint w1 = 0) {
		next[m] = ptr[u]; ptr[u] = m; zu[m] = v; capa[m] = w0; ++m;
		next[m] = ptr[v]; ptr[v] = m; zu[m] = u; capa[m] = w1; ++m;
	}
	wint augment(int src, int ink, wint flo) {
		if (src == ink) return flo;
		wint f;
		for (int &i = see[src]; ~i; i = next[i]) if (capa[i] > wEPS && lev[src] < lev[zu[i]]) {
			if ((f = augment(zu[i], ink, min(flo, capa[i]))) > wEPS) {
				capa[i] -= f; capa[i ^ 1] += f; return f;
			}
		}
		return 0;
	}
	bool solve(int src, int ink, wint flo = wINF) {
		wint f;
		int i, u, v;
		for (tof = 0; tof + wEPS < flo; ) {
			qb = qe = que;
			memset(lev, ~0, n * 4);
			for (lev[*qe++ = src] = 0, see[src] = ptr[src]; qb != qe; ) {
				for (i = ptr[u = *qb++]; ~i; i = next[i]) if (capa[i] > wEPS && !~lev[v = zu[i]]) {
					lev[*qe++ = v] = lev[u] + 1; see[v] = ptr[v];
					if (v == ink) goto au;
				}
			}
			return 0;
		au:	for (; (f = augment(src, ink, flo - tof)) > wEPS; tof += f);
		}
		return 1;
	}
}


const int D = 3005;

int N, V;
int A[3010], B[3010];

int main() {
	
	
	for (; ~scanf("%d%d", &N, &V); ) {
		for (int i = 0; i < N; ++i) {
			A[i] = in();
			B[i] = in();
		}
		MF::init(2 + D + N);
		for (int d = 0; d < D; ++d) {
			MF::ae(0, 2 + d, V);
		}
		for (int i = 0; i < N; ++i) {
			MF::ae(2 + D + i, 1, B[i]);
		}
		for (int i = 0; i < N; ++i) {
			MF::ae(2 + A[i]    , 2 + D + i, V);
			MF::ae(2 + A[i] + 1, 2 + D + i, V);
		}
		MF::solve(0, 1);
		printf("%d\n", MF::tof);
	}
	
	return 0;
}