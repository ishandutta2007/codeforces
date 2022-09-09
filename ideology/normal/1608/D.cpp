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
#include <set>
#include <map>
#include <vector>
#include <chrono>
#include <iostream>
#include <limits>
#include <numeric>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

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
int quo2(int x) { return ((x & 1) ? x + P : x) >> 1; }

const int _ = 100010;

int fac[_], ifac[_];
char s[_][2];

int binom(int N, int M) {
	if (M < 0 || M > N) return 0;
	return fac[N] * (ull)ifac[M] % P * ifac[N - M] % P;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);

	int N; cin >> N;

	fac[0] = 1; for (int i = 1; i <= N; ++i) fac[i] = fac[i - 1] * (ull)i % P;
	ifac[N] = mpow(fac[N], P - 2); for (int i = N; i; --i) ifac[i - 1] = ifac[i] * (ull)i % P;

	int d1 = 0, d2 = 0, in = 0, out = 0;
	int f0 = 1, f1 = 1, f2 = 1;
	for (int i = 0; i != N; ++i) {
		cin >> s[i];
		if (s[i][1] == 'B') s[i][1] = 'W';
		else if (s[i][1] == 'W') s[i][1] = 'B';
		if (s[i][1] == 'B') --d1;
		else if (s[i][1] == 'W') --d2;
		else ++out;
		if (s[i][0] == 'B') ++d1;
		else if (s[i][0] == 'W') ++d2;
		else ++in;
		int x = s[i][0] != 'W' && s[i][1] != 'W';
		int y = s[i][0] != 'B' && s[i][1] != 'B';
		f0 = f0 * (ull)x % P;
		f1 = f1 * (ull)y % P;
		f2 = f2 * (ull)(x + y) % P;
	}
	int ans = 0;
	for (int i = 0; i <= in; ++i) {
		ans = (ans + binom(in, i) * (ull)binom(out, d1 + i)) % P;
	}
	add(ans, f0); add(ans, f1); sub(ans, f2);
	cout << ans << '\n';

	return 0;
}