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

const int P = 1000000007;
int norm(int x) { return x >= P ? x - P : x; }
int reduce(int x) { return x < 0 ? x + P : x; }
int neg(int x) { return x ? P - x : 0; }
void add(int& x, int y) { if ((x += y - P) < 0) x += P; }
void sub(int& x, int y) { if ((x -= y) < 0) x += P; }
void fam(int& x, int y, int z) { x = (x + y * (ull)z) % P; }
int mpow(int x, unsigned k) {
	if (k == 0) return 1;
	int ret = mpow(x * (ull)x % P, k >> 1);
	if (k & 1) ret = ret * (ull)x % P;
	return ret;
}
int quo2(int x) { return ((x & 1) ? x + P : x) >> 1; }

const int _ = 2010;

char s[_], t[_];
int cnt[_ * 2], sum[_ * 2];
int tc[_ * 2], ts[_ * 2];

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);

	int T; cin >> T;
	while (T--) {
		int N; cin >> N >> (s + 1) >> (t + 1);
		memset(cnt, 0, sizeof(cnt)); memset(sum, 0, sizeof(sum));
		cnt[_] = 1;
		for (int i = 1; i <= N; ++i) {
			memset(tc, 0, sizeof(tc)); memset(ts, 0, sizeof(ts));
			for (char x = '0'; x <= '1'; ++x)
				for (char y = '0'; y <= '1'; ++y) {
					if (s[i] != '?' && s[i] != x) continue;
					if (t[i] != '?' && t[i] != y) continue;
					int offset = int(x == '1') - int(y == '1');
					if (i & 1) offset *= -1;
					for (int j = -i; j <= i; ++j) {
						add(tc[j + _], cnt[j + offset + _]);
						add(ts[j + _], sum[j + offset + _]);
					}
				}
			memcpy(cnt, tc, sizeof(tc)); memcpy(sum, ts, sizeof(ts));
			for (int j = -i; j <= i; ++j) fam(sum[j + _], cnt[j + _], j < 0 ? -j : j);
		}
		// for (int j = -N; j <= N; ++j) cerr << cnt[j + _] << " \n"[j == N];
		// for (int j = -N; j <= N; ++j) cerr << sum[j + _] << " \n"[j == N];
		cout << sum[_] << '\n';
	}

	return 0;
}