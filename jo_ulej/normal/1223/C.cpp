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

int check(int sz, int64 k, const vector<int64>& arr, int64 x, int a, int64 y, int b) {
	int cntX = 0, cntY = 0, cntXY = 0;

	for(int i = 1; i <= sz; ++i) {
		if(i % a == 0 && i % b == 0) {
			++cntXY;
		} else if(i % a == 0) {
			++cntX;
		} else if(i % b == 0) {
			++cntY;
		}
	}

	int64 cur = 0;

	for(int i = 0; i < sz; ++i) {
		if(i < cntXY) {
			cur += arr[i] * (x + y);
		} else if(i < cntXY + cntX) {
			cur += arr[i] * x;
		} else if(i < cntXY + cntX + cntY) {
			cur += arr[i] * y;
		}

		if(cur >= k) {
			return 1;
		}
	}

	return 0;
}

void solve() {
	int n;
	cin >> n;

	vector<int64> arr(n);

	for(auto& x: arr) {
		cin >> x;

		x /= 100;
	}

	sort(arr.rbegin(), arr.rend());

	int64 x, y;
	int64 a, b;
	cin >> x >> a;
	cin >> y >> b;

	if(x < y) {
		swap(x, y);
		swap(a, b);
	}

	int64 k, cur = 0;
	cin >> k;


	if(k == 0) {
		cout << "0\n";
		return;
	}

	int low = 0, high = n;

	if(!check(high, k, arr, x, a, y, b)) {
		cout << "-1\n";
		return;
	}

	while(high - low > 1) {
		int mid = (low + high) / 2;

		if(check(mid, k, arr, x, a, y, b)) {
			high = mid;
		} else {
			low = mid;
		}
	}

	cout << high << '\n';
}

int main() {
	init_IO();

	int T;
	cin >> T;

	while(T--)
		solve();

	return 0;
}