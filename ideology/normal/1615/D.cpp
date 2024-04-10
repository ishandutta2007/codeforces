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

int f[_ * 2];
int find(int x) { return f[x] == x ? x : f[x] = find(f[x]); }

int x[_], y[_], v[_];

void mer(int x, int y) {
	x = find(x); y = find(y);
	f[x] = y;
}

bool link(int x, int y) {
	mer(x, y); mer(x ^ 1, y ^ 1);
	return find(x) != find(x ^ 1);
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);

	int T; cin >> T;
	while (T--) {
		int N, M; cin >> N >> M;
		iota(f, f + N * 2, 0);
		bool flag = true;
		for (int i = 1; i != N; ++i) {
			cin >> x[i] >> y[i] >> v[i];
			if (v[i] >= 0) {
				bool f = __builtin_parity(v[i]);
				link((x[i] - 1) * 2, (y[i] - 1) * 2 + f);
			}
		}
		while (M--) {
			int u, v, f; cin >> u >> v >> f;
			flag &= link((u - 1) * 2, (v - 1) * 2 + f);
		}
		if (!flag) {
			cout << "NO\n"; continue;
		}
		cout << "YES\n";
		for (int i = 1; i != N; ++i) {
			if (v[i] == -1) {
				int a = find((x[i] - 1) * 2), b = find((y[i] - 1) * 2), c = find(b ^ 1);
				if (a == c) v[i] = 1;
				else { v[i] = 0; link(a, b); }
			}
			cout << x[i] << ' ' << y[i] << ' ' << v[i] << '\n';
		}
	}

	return 0;
}