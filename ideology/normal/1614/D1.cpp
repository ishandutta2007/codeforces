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

const int _ = 20000010;

int pc;
bool vis[_];
int pr[_ / 10];

int cnt[_];

void sieve(int N) {
	for (int x = 2; x <= N; ++x) {
		if (!vis[x]) {
			pr[++pc] = x;
		}
		for (int i = 1; pr[i] <= N / x; ++i) {
			vis[x * pr[i]] = true;
			if (x % pr[i] == 0) break;
		}
	}
	pr[pc + 1] = N + 1;
}

ll opt[_];

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);

	int N, M = 1; cin >> N;
	while (N--) { int ai; cin >> ai; ++cnt[ai]; M = max(M, ai); }
	sieve(M);
	for (int i = 1; i <= pc; ++i) for (int j = M / pr[i]; j; --j) cnt[j] += cnt[j * pr[i]];
	for (int i = M; i; --i) {
		opt[i] = cnt[i] * (ll)i;
		for (int j = 1; pr[j] <= M / i; ++j)
			opt[i] = max(opt[i], opt[i * pr[j]] + (cnt[i] - cnt[i * pr[j]]) * (ll)i);
	}
	cout << opt[1] << '\n';

	return 0;
}