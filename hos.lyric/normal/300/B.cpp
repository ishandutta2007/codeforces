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

int uf[110];
int root(int x) { return (uf[x] < 0) ? x : (uf[x] = root(uf[x])); }
bool conn(int x, int y) {
	x = root(x); y = root(y);
	if (x == y) return 0;
	if (uf[x] > uf[y]) swap(x, y);
	uf[x] += uf[y]; uf[y] = x;
	return 1;
}

int N, M;
int A[10010], B[10010];

int len;
int usLens[110];
int us[110][110];

int main() {
	int i;
	int u, v;
	int j, k;
	
	for (; ~scanf("%d%d", &N, &M); ) {
		for (i = 0; i < M; ++i) {
			A[i] = in() - 1;
			B[i] = in() - 1;
		}
		memset(uf, ~0, N << 2);
		for (i = 0; i < M; ++i) {
			conn(A[i], B[i]);
		}
		len = 0;
		memset(usLens, 0, sizeof(usLens));
		for (u = 0; u < N; ++u) if (uf[u] < 0) {
			if (-uf[u] > 3) {
				goto failed;
			}
			if (-uf[u] < 2) {
				continue;
			}
			for (v = 0; v < N; ++v) if (root(v) == u) {
				us[len][usLens[len]++] = v;
			}
			++len;
		}
		if (len > N / 3) {
			goto failed;
		}
		for (u = 0; u < N; ++u) if (uf[u] < 0) {
			if (-uf[u] < 2) {
				for (j = 0; j < N / 3; ++j) {
					if (usLens[j] < 3) {
						us[j][usLens[j]++] = u;
						break;
					}
				}
			}
		}
		for (j = 0; j < N / 3; ++j) {
			for (k = 0; k < 3; ++k) {
				if (k) printf(" ");
				printf("%d", us[j][k] + 1);
			}
			puts("");
		}
		continue;
	failed:;
		puts("-1");
	}
	
	return 0;
}