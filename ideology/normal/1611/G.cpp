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

const int _ = 1000010;

int stk[_];

int solve(vector<pair<int, int>> vec) {
	sort(vec.begin(), vec.end());
	int N = vec.size();
	int sz = 0;
	for (int i = 0; i != N; ++i) {
		int x = vec[i].second;
		int pos = lower_bound(stk, stk + sz, x, greater<int>()) - stk;
		stk[pos] = x;
		if (pos == sz) ++sz;
	}
	return sz;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);

	int T; cin >> T;
	while (T--) {
		int N, M; cin >> N >> M;
		vector<pair<int, int>> a, b;
		string s;
		for (int i = 0; i != N; ++i) {
			cin >> s;
			for (int j = 0; j != M; ++j) if (s[j] == '1') {
				if ((i ^ j) & 1) a.emplace_back(i + j, i - j);
				else b.emplace_back(i + j, i - j);
			}
		}
		cout << solve(a) + solve(b) << '\n';
	}

	return 0;
}