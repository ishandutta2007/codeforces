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

const int _ = 1010;

int f[_], sz[_];
int a[_];

int find(int x) { return f[x] == x ? x : f[x] = find(f[x]); }

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);

	int N, d; cin >> N >> d;
	iota(f + 1, f + N + 1, 1); fill(sz + 1, sz + N + 1, 1);
	int ext = 0;
	while (d--) {
		int x, y; cin >> x >> y;
		x = find(x); y = find(y);
		if (x == y) ++ext;
		else {
			sz[x] += sz[y]; f[y] = x;
		}
		int cnt = 0;
		for (int i = 1; i <= N; ++i) if (f[i] == i) a[++cnt] = sz[i];
		int ans;
		if (ext >= cnt) ans = N - 1;
		else {
			nth_element(a + 1, a + ext + 1, a + cnt + 1, greater<int>());
			ans = accumulate(a + 1, a + ext + 2, 0) - 1;
		}
		cout << ans << '\n';
	}

	return 0;
}