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

const int P = 998244353;

int norm(int x) { return x >= P ? x - P : x; }
void add(int& x, int y) { if ((x += y) >= P) x -= P; }
void sub(int& x, int y) { if ((x -= y) < 0) x += P; }

int mpow(int x, int k) {
	if (k == 0) return 1;
	int ret = mpow(x * (ull)x % P, k >> 1);
	if (k & 1) ret = x * (ull)ret % P;
	return ret;
}

const int _ = 20;

int a[_];

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);

	int T; cin >> T;
	while (T--) {
		int N; cin >> N;
		ll p = 1;
		for (int i = 1; i <= N; ++i) {
			cin >> a[i];
			while (a[i] % 2 == 0) {
				a[i] /= 2;
				p *= 2;
			}
		}

		ll ans = 0, sum = accumulate(a + 1, a + N + 1, 0);
		for (int i = 1; i <= N; ++i) ans = max(ans, sum - a[i] + a[i] * p);
		cout << ans << '\n';
	}

	return 0;
}