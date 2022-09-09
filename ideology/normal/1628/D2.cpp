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

const int _ = 2000010;

int fac[_], ifac[_];

void pre(int N) {
	fac[0] = 1; for (int i = 1; i <= N; ++i) fac[i] = fac[i - 1] * (ull)i % P;
	ifac[N] = mpow(fac[N], P - 2);
	for (int i = N; i; --i) ifac[i - 1] = ifac[i] * (ull)i % P;
}

int bin(int N, int M) {
	if (M < 0 || M > N) return 0;
	return fac[N] * (ull)ifac[M] % P * ifac[N - M] % P;
}

int ask(int N, int M) {
	int ret = 0;
	for (int i = 0; i <= M; ++i)
		add(ret, bin(N, i));
	return ret;
}

int cal(int N, int M) {
	int ret = 0;
	fam(ret, M + 1, ask(N + 1, M));
	fam(ret, P - (N + 1), ask(N, M - 1));
	return ret * (ull)mpow(2, P - 1 - N) % P;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	pre(1000005);
	int T; cin >> T;
	while (T--) {
		int N, M, K; cin >> N >> M >> K;
		cout << (cal(N - 1, M - 1) * (ull)K % P) << '\n';
		// cout << (f[N][M] * (ull)K % P) << '\n';
	}

	return 0;
}