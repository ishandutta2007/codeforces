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

int N, K;
vector<int> G[_];
int dep[_];

int cnt;
int good[_];

int dfs(int u) {
	int pref = u;
	for (int v : G[u]) if (!dep[v]) {
		dep[v] = dep[u] + 1;
		int ret = dfs(v);
		if (dep[ret] > dep[pref]) swap(pref, ret);
		good[++cnt] = dep[ret] - dep[u];
		// cerr << "push " << dep[ret] << " - " << dep[u] << '\n';
	}
	return pref;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);

	cin >> N >> K;
	for (int rep = 1; rep != N; ++rep) {
		int u, v; cin >> u >> v;
		G[u].push_back(v); G[v].push_back(u);
	}
	dep[1] = 1;
	{
		int ret = dfs(1);
		good[++cnt] = dep[ret];
	}
	sort(good + 1, good + N + 1, greater<int>());
	// for (int i = 1; i <= N; ++i) cerr << good[i] << '\n';

	ll ans = numeric_limits<ll>::min();
	int rest = N;
	for (int r = 0; r <= K; ++r) {
		if (r) rest -= good[r];
		int low = 0, high = rest;
		auto eval = [&](int b) { return (N - r - b) * ll(r - b); };
		while (low < high) {
			int mid = (low + high) / 2;
			if (eval(mid) < eval(mid + 1)) high = mid;
			else low = mid + 1;
		}
		// cerr << r << ": rest = " << rest << ", " << low << ", " << eval(low) << '\n';
		ans = max(ans, eval(low));
	}
	cout << ans << '\n';

	return 0;
}