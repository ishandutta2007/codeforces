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

const Int MO = 1000000009;
const int L = 15;

const string CS = "ACGT";
const int E = CS.size();

int N, M;
char A[20][20];

int V;
int to[110][10], ac[110], fail[110];
int que[110], *qb, *qe;

int newNode() {
	fill(to[V], to[V] + E, -1);
	ac[V] = 0;
	fail[V] = -1;
	return V++;
}

void bfs() {
	qb = qe = que;
	*qe++ = 0;
	for (; qb != qe; ) {
		const int u = *qb++;
		for (int e = 0; e < E; ++e) {
			int &v = to[u][e];
			if (~v) {
				fail[v] = u ? to[fail[u]][e] : 0;
				// ac[v] |= ac[fail[v]];
				chmax(ac[v], ac[fail[v]]);
				*qe++ = v;
			} else {
				v = u ? to[fail[u]][e] : 0;
			}
		}
	}
}

Int dp[1010][110][20];

int main() {
	
	
	for (; ~scanf("%d%d", &N, &M); ) {
		for (int i = 0; i < M; ++i) {
			scanf("%s", A[i]);
		}
		V = 0;
		newNode();
		for (int i = 0; i < M; ++i) {
			const int sz = strlen(A[i]);
			int u = 0;
			for (int j = 0; j < sz; ++j) {
				const int e = CS.find(A[i][j]);
				if (!~to[u][e]) {
					to[u][e] = newNode();
				}
				u = to[u][e];
			}
			chmax(ac[u], sz);
		}
		bfs();
		for (int n = 0; n <= N; ++n) for (int u = 0; u < V; ++u) {
			fill(dp[n][u], dp[n][u] + L, 0);
		}
		dp[0][0][0] = 1;
		for (int n = 0; n < N; ++n) for (int u = 0; u < V; ++u) for (int l = 0; l < L; ++l) if (dp[n][u][l]) {
			for (int e = 0; e < E; ++e) {
				const int v = to[u][e];
				const int ll = (ac[v] >= l + 1) ? 0 : (l + 1);
				(dp[n + 1][v][ll] += dp[n][u][l]) %= MO;
			}
		}
		Int ans = 0;
		for (int u = 0; u < V; ++u) {
			(ans += dp[N][u][0]) %= MO;
		}
		cout << ans << endl;
	}
	
	return 0;
}