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

const int _ = 100010;


int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);

	int T; cin >> T;
	while (T--) {
		int n; string s, t; cin >> n >> s >> t;
		// int dif = 0;
		// for (int i = 0; i != n; ++i) dif += s[i] != t[i];
		// int ans = 1 << 29;
		// if (dif % 2 == 0) ans = dif;
		// if ((n - dif) % 2 == 1) ans = min(ans, n - dif);
		// if ((count(s.begin(), s.end(), '1') == 0 ||
		//      count(t.begin(), t.end(), '1') == 0) && s != t) ans = -1;
		// if (ans == 1 << 29) ans = -1;
		// cout << ans << '\n';
		if (s == t) {
			cout << "0\n"; continue;
		}
		if (count(s.begin(), s.end(), '1') == 0 || count(t.begin(), t.end(), '1') == 0) {
			cout << "-1\n"; continue;
		}
		int a = count(s.begin(), s.end(), '0'), b = count(t.begin(), t.end(), '0');
		if (a != b && a + b != n - 1) {
			cout << "-1\n"; continue;
		}
		int dif = 0, ans = 1 << 29;
		for (int i = 0; i != n; ++i) dif += s[i] != t[i];
		if (a == b) ans = dif;
		if (a + b == n - 1) ans = min(ans, n - dif);
		if (ans == 1 << 29) ans = -1;
		cout << ans << '\n';
	}

	return 0;
}