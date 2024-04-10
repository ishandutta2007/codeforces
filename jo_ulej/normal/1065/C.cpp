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
const int INF = (int)2e9;

void init_IO() {
	std::ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
}

const int MAX_N = (int)2e5 + 777;

int cnt[MAX_N], n, k;

void solve() {
	cin >> n >> k;
	int minheight = INF;

	for(int i = 0; i < n; ++i) {
		int value;
		cin >> value;

		++cnt[value];
		minheight = std::min(minheight, value);
	}

	for(int i = MAX_N - 1; i > 0; --i)
		cnt[i - 1] += cnt[i];

	int ptr = MAX_N - 1;
	int answ = 0, cur = 0;

	while(ptr > minheight) {
		if(cur + cnt[ptr] > k) {
			++answ;
			cur = 0;
		}

		cur += cnt[ptr--];
	}

	answ += (cur > 0);
	cout << answ << '\n';
}

int main() {
	init_IO();
	solve();

	return 0;
}