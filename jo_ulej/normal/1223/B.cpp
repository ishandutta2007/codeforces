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

void solve() {
	const int A = 26;

	vector<int> mark(A, 0);

	string s, t;
	cin >> s >> t;

	for(auto& ch: s) {
		int code = ch - 'a';
		mark[code] |= 1;
	}

	for(auto& ch: t) {
		int code = ch - 'a';
		mark[code] |= 2;
	}

	for(int i = 0; i < A; ++i) {
		if(mark[i] == 3) {
			cout << "YES\n";
			return;
		}
	}

	cout << "NO\n";
}

int main() {
	init_IO();

	int T;
	cin >> T;

	while(T--)
		solve();

	return 0;
}