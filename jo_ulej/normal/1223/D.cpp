#include <iostream>
#include <iomanip>
#include <random>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <numeric>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <sstream>
#include <bitset>
#include <cassert>
#include <fstream>
#include <queue>

#define len(X) ((int)(X).size())

#ifdef __LOCAL
	#define DBG(X) cout << #X << "=" << (X) << '\n';
#else
	#define DBG(X)
#endif

using std::cin;
using std::cout;
using std::vector;
using std::string;
using std::pair;
using std::swap;
using std::sort;
using std::lower_bound;
using std::unique;

using int64 = long long int;
using pii   = pair<int, int>;
using pii64 = pair<int64, int64>;

const int NIL = -1;
const int INF = (int)2e9;
const int64 INF64 = (int64)2e18;

void init_IO() {
	std::ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
}

const int MAX_N = (int)3e5 + 777;

int L[MAX_N], R[MAX_N], dp[MAX_N], n;

void solve() {
	cin >> n;
	vector<int> a(n);

	for(auto& x: a) {
		cin >> x;
	}

	auto b = a;
	sort(b.begin(), b.end());
	b.erase(unique(b.begin(), b.end()), b.end());

	for(auto& x: a) {
		x = lower_bound(b.begin(), b.end(), x) - b.begin();
	}

	for(int i = 0; i < n; ++i) {
		L[i] = NIL;
		R[i] = NIL;
		dp[i] = 1;
	}

	for(int i = 0; i < n; ++i) {
		if(L[a[i]] == NIL)
			L[a[i]] = i;

		R[a[i]] = i;
	}

	int m = len(b);
	int answ = m;

	for(int i = 1; i < m; ++i) {
		if(R[i - 1] < L[i]) {
			dp[i] = std::max(dp[i], dp[i - 1] + 1);
		}
	}

	for(int i = 0; i < m; ++i) {
		answ = std::min(answ, m - dp[i]);
	}

	cout << answ << '\n';
}

int main() {
	init_IO();

	int T;
	cin >> T;

	while(T--)
		solve();

	return 0;
}