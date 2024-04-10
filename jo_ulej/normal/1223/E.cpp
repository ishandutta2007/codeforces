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

const int MAX_N = (int)5e5 + 777;
vector<pair<int, int64>> tree[MAX_N];

int64 dp[MAX_N][2];
int n, k;

void dfs(int v, int prev) {
	for(auto& ed: tree[v]) {
		int u = ed.first;

		if(u != prev)
			dfs(u, v);
	}

	dp[v][1] = 0;

	for(auto& ed: tree[v]) {
		int u = ed.first;

		if(u != prev) {
			dp[v][1] += std::max(dp[u][0], dp[u][1]);
		}
	}

	dp[v][0] = dp[v][1];
	vector<int64> diff;

	for(auto& ed: tree[v]) {
		int u = ed.first;
		int64 w = ed.second;

		if(u != prev) {
			diff.push_back(dp[u][1] - dp[u][0] + w);
		}
	}

	sort(diff.rbegin(), diff.rend());

	for(int i = 0; i < len(diff) && i < k; ++i) {
		if(diff[i] <= 0)
			break;

		dp[v][0] += diff[i];

		if(i < k - 1)
			dp[v][1] += diff[i];
	}
}

void solve() {
	int64 answ = 0;
	cin >> n >> k;

	for(int i = 0; i < n; ++i) {
		tree[i].clear();
	}

	for(int i = 0; i < n - 1; ++i) {
		int v, u;
		int64 weight;
		cin >> v >> u >> weight;
		--v, --u;

		tree[v].emplace_back(u, weight);
		tree[u].emplace_back(v, weight);
	}

	dfs(0, NIL);

/*#ifdef __LOCAL

	for(int v = 0; v < n; ++v) {
		cout << v + 1 << ' ' << dp[v][0] << ' ' << dp[v][1] << '\n';
	}

#endif*/

	answ = std::max(dp[0][0], dp[0][1]);
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