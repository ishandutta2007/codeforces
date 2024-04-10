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

const int P = 1000000007;

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

// f[i][j] = (f[i - 1][j - 1] + f[i - 1][j]) / 2
// f[i][j] = max_x { min {f[i - 1][j - 1] + x, f[i - 1][j] - x} }

const int _ = 2010;

int f[_][_];

void pre(int N) {
	for (int i = 1; i <= N; ++i) {
		f[i][i] = i;
		for (int j = 1; j < i; ++j) {
			f[i][j] = norm(f[i - 1][j] + f[i - 1][j - 1]);
			if (f[i][j] & 1) f[i][j] += P;
			f[i][j] /= 2;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	pre(2000);
	int T; cin >> T;
	while (T--) {
		int N, M, K; cin >> N >> M >> K;
		cout << (f[N][M] * (ull)K % P) << '\n';
	}

	return 0;
}