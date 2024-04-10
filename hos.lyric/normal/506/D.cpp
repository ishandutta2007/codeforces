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
#include <cstdint>
#include <unordered_set>
#include <unordered_map>

using namespace std;

typedef long long Int;
typedef vector<int> vint;
typedef pair<int, int> pint;
#define mp make_pair

template <typename T1, typename T2> ostream &operator<<(ostream &os, const pair<T1, T2> &a) { return os << "(" << a.first << ", " << a.second << ")"; };
template <typename T> void pv(T a, T b) { for (T i = a; i != b; ++i) cout << *i << " "; cout << endl; }
template <typename T> void chmin(T &t, const T &f) { if (t > f) t = f; }
template <typename T> void chmax(T &t, const T &f) { if (t < f) t = f; }
int in() { int x; scanf("%d", &x); return x; }

const int LIM = 100000;
const int L = 300;

int uf[LIM + 10];
int root(int u) {
	return (uf[u] < 0) ? u : (uf[u] = root(uf[u]));
}
bool conn(int u, int v) {
	u = root(u);
	v = root(v);
	if (u == v) return false;
	if (uf[u] > uf[v]) swap(u, v);
	uf[u] += uf[v];
	uf[v] = u;
	return true;
}

int N, M;
pair<int, pint> edges[LIM + 10];

int Q;
int QU[LIM + 10], QV[LIM + 10];
int ans[LIM + 10];

int usLen;
int us[LIM + 10];

int smallsLen;
Int smalls[16000010];

int main() {
	
	
	for (; ~scanf("%d%d", &N, &M); ) {
		for (int i = 0; i < M; ++i) {
			edges[i].second.first = in() - 1;
			edges[i].second.second = in() - 1;
			edges[i].first = in();
		}
		Q = in();
		for (int q = 0; q < Q; ++q) {
			QU[q] = in() - 1;
			QV[q] = in() - 1;
			if (QU[q] > QV[q]) {
				swap(QU[q], QV[q]);
			}
		}
		fill(ans, ans + Q, 0);
		
		sort(edges, edges + M);
		smallsLen = 0;
		for (int i = 0, j; i < M; i = j) {
			for (j = i; j < M && edges[i].first == edges[j].first; ++j);
			if (j - i >= L) {
				fill(uf, uf + N, -1);
				for (int k = i; k < j; ++k) {
					conn(edges[k].second.first, edges[k].second.second);
				}
				for (int q = 0; q < Q; ++q) {
					if (root(QU[q]) == root(QV[q])) {
						++ans[q];
					}
				}
			} else {
				usLen = 0;
				for (int k = i; k < j; ++k) {
					us[usLen++] = edges[k].second.first;
					us[usLen++] = edges[k].second.second;
				}
				sort(us, us + usLen);
				usLen = unique(us, us + usLen) - us;
				fill(uf, uf + usLen, -1);
				for (int k = i; k < j; ++k) {
					conn(
						lower_bound(us, us + usLen, edges[k].second.first) - us, 
						lower_bound(us, us + usLen, edges[k].second.second) - us
					);
				}
				for (int x = 0; x < usLen; ++x) {
					const int rx = root(x);
					for (int y = x + 1; y < usLen; ++y) {
						const int ry = root(y);
						if (rx == ry) {
							int u = us[x];
							int v = us[y];
							if (u > v) {
								swap(u, v);
							}
							smalls[smallsLen++] = (Int)u * N + v;
						}
					}
				}
			}
		}
		sort(smalls, smalls + smallsLen);
		for (int q = 0; q < Q; ++q) {
			const auto res = equal_range(smalls, smalls + smallsLen, (Int)QU[q] * N + QV[q]);
			ans[q] += res.second - res.first;
			printf("%d\n", ans[q]);
		}
	}
	
	return 0;
}