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

int b[_], q[_], ans[_];

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);

	int T; cin >> T;
	while (T--) {
		int N; cin >> N;
		for (int i = 1; i <= N; ++i) cin >> b[i];
		for (int i = 1; i <= N; ++i) { int p; cin >> p; q[p] = i; }
		bool fl = true;
		for (int i = 1; i <= N; ++i) if (i != b[i] && q[i] < q[b[i]]) fl = false;
		if (!fl) cout << "-1\n";
		else for (int i = 1; i <= N; ++i) cout << (q[i] - q[b[i]]) << " \n"[i == N];
	}

	return 0;
}