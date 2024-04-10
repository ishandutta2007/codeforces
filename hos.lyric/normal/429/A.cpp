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

int N;
int m, ptr[100010], nxt[200010], zu[200010];
int A[100010], B[100010];

int ansLen;
int ans[100010];

void dfs(int u, int p, int x0, int x1) {
	const int tmp = A[u] ^ B[u] ^ x0;
	if (tmp != 0) {
		ans[ansLen++] = u;
		x0 ^= 1;
	}
	for (int i = ptr[u]; ~i; i = nxt[i]) {
		const int v = zu[i];
		if (v != p) {
			dfs(v, u, x1, x0);
		}
	}
}

int main() {
	
	
	for (; ~scanf("%d", &N); ) {
		m = 0;
		fill_n(ptr, N, -1);
		for (int i = 0; i < N - 1; ++i) {
			const int u = in() - 1;
			const int v = in() - 1;
			nxt[m] = ptr[u]; ptr[u] = m; zu[m] = v; ++m;
			nxt[m] = ptr[v]; ptr[v] = m; zu[m] = u; ++m;
		}
		for (int u = 0; u < N; ++u) {
			A[u] = in();
		}
		for (int u = 0; u < N; ++u) {
			B[u] = in();
		}
		ansLen = 0;
		dfs(0, -1, 0, 0);
		sort(ans, ans + ansLen);
		printf("%d\n", ansLen);
		for (int j = 0; j < ansLen; ++j) {
			printf("%d\n", ans[j] + 1);
		}
break;
	}
	
	return 0;
}