#include <cmath>
#include <cstring>

#include <algorithm>
#include <chrono>
#include <stack>
#include <bitset>
#include <numeric>
#include <iostream>
#include <vector>
#include <random>
#include <string>
#include <set>
#include <queue>
#include <map>
#include <unordered_map>

typedef unsigned long long ull;

using namespace std;

const int P = 998244353;

int norm(int x) { return x >= P ? x - P : x; }
int reduce(int x) { return x < 0 ? x + P : x; }
int neg(int x) { return x ? P - x : 0; }
void add(int& x, int y) { if ((x += y - P) < 0) x += P; }
void sub(int& x, int y) { if ((x -= y) < 0) x += P; }
void fam(int& x, int y, int z) { x = (x + y * (ull)z) % P; }
int mpow(int x, unsigned k) {
	if (k == 0) return 1;
	int ret = mpow(x * (ull)x % P, k >> 1);
	if (k & 1) ret = ret * (ull)x % P;
	return ret;
}

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int _ = 1005;

bool vis[_][_];
unsigned a[_][_];

unsigned calc(int N) {
	unsigned ret = 0;
	for (int i = 1; i < N; i += 4) {
		if (i) { vis[0][i - 1] ^= 1; ret ^= a[0][i]; }
		vis[0][i + 1] ^= 1;
		vis[1][i] ^= 1;
	}
	for (int i = 1; i < N; ++i)
		for (int j = (i ^ 1) & 1; j < N; j += 2) {
			if (!vis[i - 1][j]) {
				ret ^= a[i][j];
				vis[i - 1][j] ^= 1;
				if (j) vis[i][j - 1] ^= 1;
				vis[i][j + 1] ^= 1;
				vis[i + 1][j] ^= 1;
			}
		}
	// for (int i = 0; i != N; ++i){
	// 	for (int j = 0; j != N; ++j)
	// 		cerr << vis[i][j];
	// 		cerr << '\n';
	// }
	// bool fl = true;
	// for (int i = 1; i < N; i += 2) fl &= vis[N - 1][i];
	// cerr << "CALC\n";
	// assert(fl);
	for (int i = 0; i <= N; ++i) memset(vis[i], 0, sizeof(bool) * (N + 1));
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int T; cin >> T;
	while (T--) {
		int N; cin >> N;
		for (int i = 0; i != N; ++i)
			for (int j = 0; j != N; ++j)
				cin >> a[i][j];
		unsigned ans = calc(N);
		for (int i = 0; i != N; ++i)
			reverse(a[i], a[i] + N);
		ans ^= calc(N);
		cout << ans << '\n';
	}

	return 0;
}