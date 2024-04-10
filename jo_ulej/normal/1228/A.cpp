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

void init_IO() {
	std::ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
}

void solve() {
	int L, R;
	cin >> L >> R;

	for(int i = L; i <= R; ++i) {
		vector<int> cnt(10, 0);

		for(int j = i; j > 0; j /= 10)
			++cnt[j % 10];

		int ok = 1;

		for(int digit = 0; digit < 10; ++digit) {
			if(cnt[digit] > 1) {
				ok = 0;
				break;
			}
		}

		if(ok) {
			cout << i << '\n';
			return;
		}
	}

	cout << NIL << '\n';
}

int main() {
	init_IO();
	solve();

	return 0;
}