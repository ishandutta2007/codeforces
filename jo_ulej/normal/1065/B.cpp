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
	#define DBG(X) cout << #X << "=" << (X) << endl;
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
const int64 INF = (int64)2e18;

void init_IO() {
	std::ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
}

int check(int64 V, int64 E) {
	if(E == 0 && V == 0)
		return 1;

	return E <= (V * (V - 1)) / 2 && E >= (V + 1) / 2;
}

void solve() {
	int64 V, E;
	cin >> V >> E;

	int64 l = INF, r = -INF;

	for(int64 isolated = 0; isolated <= V; ++isolated) {
		if(check(V - isolated, E)) {
			l = std::min(l, isolated);
			r = std::max(r, isolated);
		}
	}

	cout << l << ' ' << r << '\n';
}

int main() {
	init_IO();
	solve();

	return 0;
}