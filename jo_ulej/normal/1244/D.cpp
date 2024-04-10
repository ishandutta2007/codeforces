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
using std::abs;

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

template<typename T>
std::ostream& operator<<(std::ostream& os, const vector<T>& vec) {
	os << '[';
	int fst = 1;

	for(auto& elem: vec) {
		if(fst == 0) {
			os << ' ';
		}

		os << elem;
		fst = 0;
	}

	os << ']';
	return os;
}

const int MAX_N = (int)1e5 + 777;
const int COLORS = 3;

vector<int> g[MAX_N];
int64 cost[COLORS][MAX_N], needed[COLORS][COLORS];
int which[COLORS], best_which[COLORS];
int depth[MAX_N], n, deg[MAX_N];

void dfs(int v, int parent) {
	for(auto& u: g[v]) {
		if(u != parent) {
			depth[u] = (depth[v] + 1) % COLORS;
			dfs(u, v);
		}
	}
}

void solve() {
	cin >> n;

	for(int c = 0; c < COLORS; ++c) {
		for(int v = 0; v < n; ++v) {
			cin >> cost[c][v];
		}
	}

	for(int i = 0; i < n - 1; ++i) {
		int v, u;
		cin >> v >> u;
		--v, --u;

		g[v].push_back(u);
		g[u].push_back(v);

		++deg[v];
		++deg[u];
	}

	for(int v = 0; v < n; ++v) {
		if(deg[v] > 2) {
			cout << "-1\n";
			return;
		}
	}

	for(int v = 0; v < n; ++v) {
		if(deg[v] == 1) {
			dfs(v, NIL);
			break;
		}
	}

	for(int v = 0; v < n; ++v) {
		for(int c = 0; c < COLORS; ++c) {
			needed[c][depth[v]] += cost[c][v];
		}
	}

	int64 answ = INF64;

	for(which[0] = 0; which[0] < COLORS; ++which[0]) {
		for(which[1] = 0; which[1] < COLORS; ++which[1]) {
			for(which[2] = 0; which[2] < COLORS; ++which[2]) {
				if(which[0] == which[1] || which[0] == which[2] || which[1] == which[2]) {
					continue;
				}

				int64 local = 0;

				for(int d = 0; d < COLORS; ++d) {
					local += needed[which[d]][d];
				}

				answ = std::min(answ, local);

				if(local == answ) {
					for(int d = 0; d < COLORS; ++d) {
						best_which[d] = which[d];
					}
				}
			}
		}
	}

	cout << answ << '\n';

	for(int v = 0; v < n; ++v) {
		cout << best_which[depth[v]] + 1 << ' ';
	}

	cout << '\n';
}

int main() {
	init_IO();
	solve();

	return 0;
}