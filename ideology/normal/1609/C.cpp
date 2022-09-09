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

const int _ = 200010;

bool vis[1000010];
vector<int> vec[_];

void pre(int N) {
	for (int x = 2; x <= N; ++x)
		if (!vis[x])
			for (int y = x + x; y <= N; y += x) vis[y] = true;
}

ll solve(const vector<int>& vec) {
	ll ret = 0;
	int N = vec.size();
	if (N == 0) return 0;
	int lst = 0, cnt = 0;
	for (int i = 0; i != N; ++i) {
		cnt += vec[i];
		while (cnt > 1) {
			cnt -= vec[lst++];
		}
		ret += i - lst;
	}
	// cout << ret << '\n';
	lst = 0; cnt = 0;
	for (int i = 0; i != N; ++i) {
		cnt += vec[i];
		while (cnt > 0) {
			cnt -= vec[lst++];
		}
		if (i >= lst) ret -= i - lst;
	}
	// for (int i = 0; i != N; ++i) cout << vec[i] <<" \n"[i == N - 1];
	// cout << ret << '\n';
	return ret;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);

	pre(1e6);

	int T; cin >> T;
	while (T--) {
		int N, e; cin >> N >> e;
		ll ans = 0;
		for (int i = 1; i <= N; ++i) {
			int ai; cin >> ai;
			if (vis[ai]) {
				ans += solve(vec[i % e]);
				vec[i % e].clear();
			} else vec[i % e].push_back(ai != 1);
		}
		for (int i = 0; i != e; ++i) {
			ans += solve(vec[i]);
			vec[i].clear();
		}
		cout << ans << '\n';
	}

	return 0;
}