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
		ll k, x; cin >> k >> x;
		auto cal = [&](ll v) {
			if (v <= k)
				return v * (v + 1) / 2;
			return k * (k + 1) / 2 + (v - k) * (k * 2 - v + k - 1) / 2;
		};
		ll low = 1, high = k * 2 - 1;
		while (low < high) {
			ll mid = (low + high) / 2;
			if (cal(mid) < x) low = mid + 1;
			else high = mid;
		}
		cout << low << '\n';
	}

	return 0;
}