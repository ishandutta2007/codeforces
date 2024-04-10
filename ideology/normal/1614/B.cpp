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

pair<int, int> a[_];
int x[_];

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);

	int T; cin >> T;
	while (T--) {
		int N; cin >> N;
		for (int i = 1; i <= N; ++i) { cin >> a[i].first; a[i].second = i; }
		sort(a + 1, a + N + 1, greater<pair<int, int>>());
		ll T = 0;
		for (int i = 1; i <= N; ++i) {
			int dis = (i + 1) / 2;
			T += dis * (ll)a[i].first;
			if (i & 1) dis *= -1;
			x[a[i].second] = dis;
		}
		cout << T * 2 << '\n';
		for (int i = 0; i <= N; ++i) cout << x[i] << " \n"[i == N];
	}

	return 0;
}