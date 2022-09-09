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

// int iabs(int x) { return x < 0 ? -x : x; }
// int sgn(int x) { return x < 0 ? -1 : 1; }

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);

	int T; cin >> T;
	while (T--) {
		int n, a, b; cin >> n >> a >> b;
		if (a > b) {
			if (a == n / 2 + 1 && b == n / 2) {
				for (int i = n; i; --i) cout << i << ' '; cout << '\n';
			} else cout << "-1\n";
		} else if (b <= n / 2 || a > n / 2) {
			cout << "-1\n";
		} else {
			vector<int> p(n); int l = 0, r = n;
			p[l++] = a; p[--r] = b;
			for (int i = 1; i < a; ++i) p[--r] = i;
			for (int i = b + 1; i <= n; ++i) p[l++] = i;
			for (int i = a + 1; i < b; ++i) if (l < n / 2) p[l++] = i;
			else p[--r] = i;
			for (int i = 1; i <= n; ++i) cout << p[i - 1] << ' '; cout << '\n';
		}
	}

	return 0;
}