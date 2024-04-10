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

void solve() {
	int64 a, b, c, d, k;
	cin >> a >> b >> c >> d >> k;

	int64 x = (a + c - 1) / c;
	int64 y = (b + d - 1) / d;

	if(x + y <= k) {
		cout << x << ' ' << y << '\n';
	} else {
		cout << "-1\n";
	}
}

int main() {
	init_IO();

	int T;
	cin >> T;

	while(T--)
		solve();

	return 0;
}