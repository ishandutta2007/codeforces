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

const int MAX_N = (int)1e5 + 777;
const int MAX_M = 21;
const int DP_SZ = (1 << MAX_M) + 228;

int64 cnt[MAX_M][MAX_M];
int n, m;
string str;

int64 dp[DP_SZ];

void solve() {
	cin >> n >> m >> str;

	for(int i = 0; i < n - 1; ++i) {
		int c = str[i] - 'a';
		int d = str[i + 1] - 'a';

		++cnt[c][d];
	}

	dp[0] = 0;

	for(int i = 1; i < DP_SZ; ++i) {
		dp[i] = INF64;
	}

	for(int msk = 0; msk < (1 << m); ++msk) {
		int sz = 0;
	
		for(int j = 0; j < m; ++j) {
			sz += (msk >> j) & 1;
		}

		int64 local = dp[msk];
	
		for(int c = 0; c < m; ++c) {
			for(int d = 0; d < m; ++d) {
				int has_c = (msk >> c) & 1;
				int has_d = (msk >> d) & 1;

				if(has_c && !has_d)
					local += cnt[c][d] + cnt[d][c];
			}
		}

		for(int j = 0; j < m; ++j) {
			int msk2 = msk | (1 << j);
			dp[msk2] = std::min(dp[msk2], local);
		}
	}

	cout << dp[(1 << m) - 1] << '\n';
}

int main() {
	init_IO();
	solve();

	return 0;
}