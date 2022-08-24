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

int uf[3010];
int root(int u) {
	return (uf[u] < 0) ? u : (uf[u] = root(uf[u]));
}
bool conn(int u, int v) {
	u = root(u);
	v = root(v);
	if (u == v) return 0;
	if (uf[u] > uf[v]) swap(u, v);
	uf[u] += uf[v];
	uf[v] = u;
	return 1;
}

int N, M;
int P[3010];

int ansLen;
pint ans[3010];

int main() {
	
	
	for (; ~scanf("%d", &N); ) {
		for (int u = 0; u < N; ++u) {
			P[u] = in() - 1;
		}
		M = N - in();
		ansLen = 0;
		for (; ; ) {
			fill_n(uf, N, -1);
			for (int u = 0; u < N; ++u) {
				conn(u, P[u]);
			}
			int numCompos = 0;
			for (int u = 0; u < N; ++u) {
				if (uf[u] < 0) {
					++numCompos;
				}
			}
// cout<<numCompos<<" "<<M<<endl;
			int u = -1, v = -1;
			if (numCompos < M) {
				for (u = 0; u < N; ++u) {
					if (-uf[root(u)] > 1) {
						break;
					}
				}
				assert(u < N);
				for (v = u + 1; v < N; ++v) {
					if (root(u) == root(v)) {
						break;
					}
				}
				assert(v < N);
			} else if (numCompos > M) {
				u = 0;
				for (v = u + 1; v < N; ++v) {
					if (root(u) != root(v)) {
						break;
					}
				}
				assert(v < N);
			} else {
				break;
			}
			ans[ansLen++] = mp(u, v);
			swap(P[u], P[v]);
		}
		printf("%d\n", ansLen);
		for (int i = 0; i < ansLen; ++i) {
			if (i) printf(" ");
			printf("%d %d", ans[i].first + 1, ans[i].second + 1);
		}
		puts("");
	}
	
	return 0;
}