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

const int _ = 100010;

char s[_];

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);

	int N, Q; cin >> N >> Q >> (s + 1);
	auto calc = [&](int i) {
		if (i <= 1 || i >= N) return 0;
		return (s[i - 1] == 'a' && s[i] == 'b' && s[i + 1] == 'c') ? 1 : 0;
	};
	int ans = 0;
	for (int i = 1; i <= N; ++i) ans += calc(i);
	while (Q--) {
		int pos; char c; cin >> pos >> c;
		ans -= calc(pos - 1); ans -= calc(pos); ans -= calc(pos + 1);
		s[pos] = c;
		ans += calc(pos - 1); ans += calc(pos); ans += calc(pos + 1);
		cout << ans << '\n';
	}

	return 0;
}