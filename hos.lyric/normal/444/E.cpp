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
	const int LIM_N = 6005;
	const int LIM_M = 10000005;
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
}


int uf[3010];
int root(int u) {
	return (uf[u] < 0) ? u : (uf[u] = root(uf[u]));
}
void conn(int u, int v) {
	u = root(u);
	v = root(v);
	if (u == v) return;
	if (uf[u] > uf[v]) swap(u, v);
	uf[u] += uf[v];
	uf[v] = u;
}

int N;
int A[3010], B[3010], C[3010];
int X[3010];

int numCompos;
int us[3010];
int ids[3010];
int sumX[3010];

bool check(int threshold) {
	fill(uf, uf + N, -1);
	for (int i = 0; i < N - 1; ++i) {
		if (C[i] < threshold) {
			conn(A[i], B[i]);
		}
	}
// cout<<"threshold = "<<threshold<<endl;
// cout<<"uf : ";pv(uf,uf+N);
	numCompos = 0;
	for (int u = 0; u < N; ++u) if (uf[u] < 0) {
		us[numCompos] = u;
		ids[u] = numCompos++;
	}
	fill(sumX, sumX + numCompos, 0);
	for (int u = 0; u < N; ++u) {
		chmin(sumX[ids[root(u)]] += X[u], N);
	}
// cout<<"-uf.us : ";for(int a=0;a<numCompos;++a)cout<<-uf[us[a]]<<" ";cout<<endl;
// cout<<"sumX : ";pv(sumX,sumX+numCompos);
	MF::init(2 + numCompos + numCompos);
	for (int a = 0; a < numCompos; ++a) {
		MF::ae(0, 2 + a, -uf[us[a]]);
		MF::ae(2 + numCompos + a, 1, sumX[a]);
	}
	for (int a = 0; a < numCompos; ++a) for (int b = 0; b < numCompos; ++b) if (a != b) {
		MF::ae(2 + a, 2 + numCompos + b, -uf[us[a]]);
	}
	const bool res = MF::solve(0, 1, N);
// cout<<res<<" "<<MF::tof<<endl;
	return res;
}

int csLen;
int cs[3010];

int main() {
	
	
	for (; ~scanf("%d", &N); ) {
		for (int i = 0; i < N - 1; ++i) {
			A[i] = in() - 1;
			B[i] = in() - 1;
			C[i] = in();
		}
		for (int u = 0; u < N; ++u) {
			X[u] = in();
		}
		
		copy(C, C + N - 1, cs);
		sort(cs, cs + N - 1);
		csLen = unique(cs, cs + N - 1) - cs;
		
		int lo = 0, ho = csLen;
		for (; lo + 1 < ho; ) {
			const int mo = (lo + ho) / 2;
			(check(cs[mo]) ? lo : ho) = mo;
		}
		printf("%d\n", cs[lo]);
	}
	
	return 0;
}