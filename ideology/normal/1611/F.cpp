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

int a[_], ans[_];
ll sum[_];

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);

	int T; cin >> T;
	while (T--) {
		int N; ll s; cin >> N >> s;
		for (int i = 1; i <= N; ++i) cin >> a[i];
		// sum[r] + s < sum[l - 1]
		priority_queue<pair<ll, int>> Q;
		for (int i = 1; i <= N; ++i) {
			sum[i] = sum[i - 1] + a[i];
			Q.emplace(sum[i - 1], i);
			while (!Q.empty() && Q.top().first > sum[i] + s) {
				ans[Q.top().second] = i - 1; Q.pop();
			}
		}
		while (!Q.empty()) { ans[Q.top().second] = N; Q.pop(); }
		for (int i = 1; i <= N; ++i) ans[i] = ans[i] - i;
		int pos = max_element(ans + 1, ans + N + 1) - ans;
		if (ans[pos] < 0) cout << "-1\n";
		else cout << pos << ' ' << ans[pos] + pos << '\n';
	}

	return 0;
}