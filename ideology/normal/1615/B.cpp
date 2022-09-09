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

const int _ = 200010;

int sum[20][_];

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);

	for (int i = 0; i != 20; ++i) {
		for (int j = 1; j != _; ++j) sum[i][j] = sum[i][j - 1] + !((j >> i) & 1);
	}

	int T; cin >> T;
	while (T--) {
		int l, r; cin >> l >> r;
		int ans = r - l + 1;
		for (int i = 0; i != 20; ++i) {
			ans = min(ans, sum[i][r] - sum[i][l - 1]);
		}
		cout << ans << '\n';
	}

	return 0;
}