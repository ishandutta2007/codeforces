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

using ll = long long;
using ull = unsigned long long;

const int P = 1000000007;

int norm(int x) { return x >= P ? x - P : x; }
void add(int& x, int y) { if ((x += y) >= P) x -= P; }
void sub(int& x, int y) { if ((x -= y) < 0) x += P; }

int mpow(int x, int k) {
	if (k == 0) return 1;
	int ret = mpow(x * (ull)x % P, k >> 1);
	if (k & 1) ret = x * (ull)ret % P;
	return ret;
}

const int _ = 200010;

int pw[_ + 100];

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);

	pw[0] = 1; for (int i = 1; i != _ + 100; ++i) pw[i] = norm(pw[i - 1] << 1);

	int T; cin >> T;
	while (T--) {
		int N, M; cin >> N >> M;
		int os = 0;
		while (M--) {
			int l, r, x; cin >> l >> r >> x;
			os |= x;
		}
		int ans = 0;
		for (int i = 0; i != 30; ++i) {
			if (os & 1) {
				ans = (ans + pw[i + N - 1]) % P;
			}
			os >>= 1;
		}
		cout << ans << '\n';
	}

	return 0;
}