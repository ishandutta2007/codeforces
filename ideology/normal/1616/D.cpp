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
#include <unordered_set>
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

const int _ = 50010;

ll a[_];
int dp[_], pre[_];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int T; cin >> T;
	while (T--) {
		int N; cin >> N;
		for (int i = 1; i <= N; ++i) cin >> a[i];
		int x; cin >> x;
		for (int i = 1; i <= N; ++i) {
			a[i] -= x;
			pre[i] = i - 1;
			if (i >= 2 && a[i] + a[i - 1] >= 0) {
				pre[i] = i - 2;
				if (i >= 3 && a[i] + a[i - 1] + a[i - 2] >= 0
					&& a[i - 1] + a[i - 2] >= 0) pre[i] = pre[i - 1];
			}
		}
		priority_queue<pair<int, int>> Q;
		Q.emplace(0, 0);
		for (int i = 1; i <= N + 1; ++i) {
			while (Q.top().second < pre[i - 1]) Q.pop();
			dp[i] = -Q.top().first + 1;
			Q.emplace(-dp[i], i);
		}
		cout << N + 1 - dp[N + 1] << '\n';
	}

	return 0;
}