#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cctype>
 
#include <algorithm>
#include <random>
#include <bitset>
#include <queue>
#include <stack>
#include <functional>
#include <unordered_set>
#include <set>
#include <map>
#include <vector>
#include <chrono>
#include <iostream>
#include <limits>
#include <numeric>

using namespace std;

using ull = unsigned long long;
using ll = long long;

// const int P = 998244353;

// int norm(int x) { return x >= P ? x - P : x; }
// int reduce(int x) { return x < 0 ? x + P : x; }
// int neg(int x) { return x ? P - x : 0; }
// void add(int& x, int y) { if ((x += y - P) < 0) x += P; }
// void sub(int& x, int y) { if ((x -= y) < 0) x += P; }
// void fam(int& x, int y, int z) { x = (x + y * (ull)z) % P; }
// int mpow(int x, unsigned k) {
// 	if (k == 0) return 1;
// 	int ret = mpow(x * (ull)x % P, k >> 1);
// 	if (k & 1) ret = ret * (ull)x % P;
// 	return ret;
// }
// int quo2(int x) { return ((x & 1) ? x + P : x) >> 1; }

const int _ = 260;

int G[70][70];
int c[_], vec[_], ans[_];
int bas[_][_];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int T; cin >> T;
	while (T--) {
		int N, M; cin >> N >> M;
		memset(G, 0, sizeof(G));
		for (int i = 1; i <= M; ++i) {
			int u, v;
			cin >> u >> v >> c[i];
			G[u][v] = G[v][u] = i;
		}
		memset(bas, 0, sizeof(bas));
		auto ins = [&]() {
			for (int i = 1; i <= M + 1; ++i)
				if (vec[i]) {
					if (bas[i][i]) {
						int c = 3 - vec[i];
						for (int j = i; j <= M + 1; ++j)
							vec[j] = (vec[j] + c * bas[i][j]) % 3;
						continue;
					}
					int c = vec[i];
					for (int j = i; j <= M + 1; ++j) bas[i][j] = vec[j] * c % 3;
					break;
				}
		};
		for (int i = 1; i <= M; ++i) if (c[i] != -1) {
			memset(vec, 0, sizeof(vec));
			vec[i] = 1; vec[M + 1] = (c[i] - 1);
			ins();
		}
		for (int i = 1; i <= N; ++i)
			for (int j = 1; j < i; ++j)
				for (int k = 1; k < j; ++k) if (G[i][j] && G[j][k] && G[k][i]) {
					memset(vec, 0, sizeof(vec));
					vec[G[i][j]] = 1; vec[G[j][k]] = 1; vec[G[k][i]] = 1;
					ins();
				}
		if (bas[M + 1][M + 1]) { cout << "-1\n"; break; }
		for (int i = M; i; --i) {
			if (!bas[i][i]) continue;
			ans[i] = bas[i][M + 1];
			for (int j = i + 1; j <= M; ++j)
				ans[i] = (ans[i] + (3 - bas[i][j]) * ans[j]) % 3;
		}
		for (int i = 1; i <= M; ++i) cout << ans[i] + 1 << " \n"[i == M];
	}

	return 0;
}