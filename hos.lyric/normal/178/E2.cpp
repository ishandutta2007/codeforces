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

const int R = 4;
const int S = 9;

int uf[4000010];
int root(int x) { return (uf[x] < 0) ? x : (uf[x] = root(uf[x])); }
bool conn(int x, int y) {
	x = root(x); y = root(y);
	if (x == y) return 0;
	if (uf[x] > uf[y]) swap(x, y);
	uf[x] += uf[y]; uf[y] = x;
	return 1;
}

int N;
inline int _(int x, int y) { return x * N + y; }

int A[2010][2010];
int B[2010][2010];
int C[2010][2010];
vector<pint> ps[4000010];

int main() {
	int x, y;
	int dx, dy;
	int r;
	
	for (; ~scanf("%d", &N); ) {
		for (x = 0; x < N; ++x) for (y = 0; y < N; ++y) {
			A[x][y] = in();
		}
		for (x = 0; x < N; ++x) for (y = 0; y < N; ++y) {
			B[x + 1][y + 1] = B[x + 1][y] + B[x][y + 1] - B[x][y] + A[x][y];
		}
		for (x = 0; x + R <= N; ++x) for (y = 0; y + R <= N; ++y) {
			C[x][y] = B[x + R][y + R] - B[x + R][y] - B[x][y + R] + B[x][y];
		}
		memset(uf, ~0, sizeof(uf));
		for (x = 1; x + R < N; ++x) for (y = 0; y + R < N; ++y) {
			for (dx = -1; dx <= +1; ++dx) for (dy = -1; dy <= +1; ++dy) {
				if (C[x + dx][y + dy] < S) goto failed;
			}
			for (dx = -1; dx <= +1; ++dx) for (dy = -1; dy <= +1; ++dy) if (dx * dx + dy * dy == 1) {
				conn(_(x, y), _(x + dx, y + dy));
			}
		failed:;
		}
		for (r = 0; r < N * N; ++r) {
			ps[r].clear();
		}
		for (x = 0; x + R <= N; ++x) for (y = 0; y + R <= N; ++y) if (C[x][y] > S) {
			r = root(_(x, y));
			ps[r].push_back(mp(x, y));
		}
		int ansC = 0, ansS = 0;
		for (r = 0; r < N * N; ++r) if (!ps[r].empty()) {
			int sz = ps[r].size(), i, j;
			if (sz < 30) continue;
			double ox = 0, oy = 0;
			for (i = 0; i < sz; ++i) {
				x = ps[r][i].first;
				y = ps[r][i].second;
				ox += x;
				oy += y;
			}
			ox /= sz;
			oy /= sz;
			double rads[10] = {};
			for (i = 0; i < sz; ++i) {
				x = ps[r][i].first;
				y = ps[r][i].second;
				double tmp = (x - ox) * (x - ox) + (y - oy) * (y - oy);
				for (j = 0; j < 10; ++j) {
					if (rads[j] < tmp) {
						swap(rads[j], tmp);
					}
				}
			}
			double rad = rads[0];
			double ratio = sz / rad;
// cerr<<ratio<<endl;
assert(ratio>2.8||ratio<2.6);
			(ratio > 2.7) ? ++ansC : ++ansS;
		}
		printf("%d %d\n", ansC, ansS);
	}
	
	return 0;
}