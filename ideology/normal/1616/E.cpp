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

const int _ = 100010;

int N;
char s[_], t[_];
vector<int> pot[26];

int fw[_];

void ch(int k, int x) {
	for (; k <= N; k += k & -k) fw[k] += x;
}
int qry(int k) {
	int ret = 0;
	for (; k; k &= k - 1) ret += fw[k];
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int T; cin >> T;
	while (T--) {
		cin >> N >> (s + 1) >> (t + 1);
		fill(fw + 1, fw + N + 1, 0);
		for (int i = 1; i <= N; ++i) fw[i] = i & -i;
		ll ans = 1e18, cur = 0;
		for (int i = 0; i != 26; ++i) pot[i].clear();
		for (int i = N; i; --i) pot[s[i] - 'a'].push_back(i);
		for (int i = 1; i <= N; ++i) {
			int best = N + 1;
			for (int j = 0; j != t[i] - 'a'; ++j) if (!pot[j].empty()) {
				if (best > pot[j].back()) {
					best = pot[j].back();
				}
			}
			if (best <= N) ans = min(ans, cur + qry(best - 1));
			if (pot[t[i] - 'a'].empty()) break;
			int bak = pot[t[i] - 'a'].back(); pot[t[i] - 'a'].pop_back();
			ch(bak, -1); cur += qry(bak);
		}
		if (ans >= 1e18) ans = -1;
		cout << ans << '\n';
	}

	return 0;
}