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
#include <set>
#include <map>
#include <utility>
#include <numeric>
#include <algorithm>
#include <bitset>
#include <complex>

using namespace std;

typedef unsigned uint;
typedef long long Int;
typedef vector<int> vint;
typedef pair<int,int> pint;
#define mp make_pair

template<class T> void pv(T a, T b) { for (T i = a; i != b; ++i) cout << *i << " "; cout << endl; }
template<class T> void chmin(T &t, T f) { if (t > f) t = f; }
template<class T> void chmax(T &t, T f) { if (t < f) t = f; }
int in() { int x; scanf("%d", &x); return x; }

namespace MCF {
	#define MAXN 100010
	#define MAXM 100010
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
	bool spRep(int src, int ink, wint flo = wINF) {
		wint f;
		cint c, cc;
		int i, u, v;
		memset(pot, 0, n * sizeof(cint));
	//*
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
			for (q.push(mp(d[src] = 0, src)); !q.empty(); ) {
				c = q.top().first; u = q.top().second; q.pop();
				if (vis[u]++) continue;
				for (i = ptr[u]; ~i; i = next[i]) if (capa[i] > wEPS) {
					cc = c + cost[i] + pot[u] - pot[v = zu[i]];
					if (d[v] > cc) { q.push(mp(d[v] = cc, v)); pree[v] = i; }
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

int N, K;
int S[1010], T[1010], C[1010];

int xsLen;
int xs[2010];
int ms[2010];

int main() {
	int i, u, v;
	
	for (; ~scanf("%d%d", &N, &K); ) {
		for (i = 0; i < N; ++i) {
			S[i] = in();
			T[i] = S[i] + in();
			C[i] = in();
		}
		xsLen = 0;
		for (i = 0; i < N; ++i) {
			xs[xsLen++] = S[i];
			xs[xsLen++] = T[i];
		}
		sort(xs, xs + xsLen);
		xsLen = unique(xs, xs + xsLen) - xs;
		MCF::init(xsLen);
		for (u = 0; u < xsLen - 1; ++u) {
			MCF::ae(u, u + 1, K, 0);
		}
		for (i = 0; i < N; ++i) {
			u = lower_bound(xs, xs + xsLen, S[i]) - xs;
			v = lower_bound(xs, xs + xsLen, T[i]) - xs;
			ms[i] = MCF::m;
			MCF::ae(u, v, 1, -C[i]);
		}
		MCF::spRep(0, xsLen - 1, K);
		for (i = 0; i < N; ++i) {
			if (i) printf(" ");
			printf("%d", !MCF::capa[ms[i]] ? 1 : 0);
		}
		puts("");
	}
	
	return 0;
}