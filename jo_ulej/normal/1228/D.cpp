#pragma GCC optimize("Ofast,unroll-loops")

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

void init_IO() {
	std::ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
}

const int MAX_N = (int)1e5 + 777;
const int MAX_M = (int)3e5 + 777;

vector<int> g[MAX_N];
int uni = 0, color[MAX_N];
int n, m;

int64 cnt[17];

void solve() {
	cin >> n >> m;

	for(int i = 0; i < m; ++i) {
		int v, u;
		cin >> v >> u;
		--v, --u;

		g[v].push_back(u);
		g[u].push_back(v);
	}

	vector<pair<vector<int>, int>> ord;

	for(int v = 0; v < n; ++v) {
		sort(g[v].begin(), g[v].end());
		ord.emplace_back(g[v], v);
	}

	sort(ord.begin(), ord.end());

	for(int v = 0; v < n; ++v) {
		if(v == 0 || ord[v - 1].first != ord[v].first) {
			++uni;
		}

		if(uni > 3)
			break;

		int real_vertex = ord[v].second;
		color[real_vertex] = uni;

		++cnt[color[real_vertex]];
	}

	if(uni != 3) {
		cout << NIL << '\n';
		return;
	}

	for(int v = 0; v < n; ++v) {
		for(auto& u: g[v]) {
			if(color[v] == color[u]) {
				cout << NIL << '\n';
				return;
			}
		}

		int magic = n - cnt[color[v]];

		if(len(g[v]) != magic) {
			cout << NIL << '\n';
			return;
		}
	}

	int64 expected_edges = 0;
	expected_edges += cnt[1] * cnt[2];
	expected_edges += cnt[2] * cnt[3];
	expected_edges += cnt[3] * cnt[1];

	int64 real_edges     = m;

	if(real_edges != expected_edges) {
		cout << NIL << '\n';
		return;
	}

	if(cnt[1] == 0 || cnt[2] == 0 || cnt[3] == 0) {
		cout << NIL << '\n';
		return;
	}

	for(int v = 0; v < n; ++v) {
		cout << color[v] << ' ';
	}

	cout << '\n';
}

int main() {
	init_IO();
	solve();

	return 0;
}