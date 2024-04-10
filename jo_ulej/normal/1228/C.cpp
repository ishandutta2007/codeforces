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

const int64 MOD = (int64)1e9 + 7;

int64 mult(int64 x, int64 y) {
	return (x * 1LL * y) % MOD;
}

int64 binpow(int64 x, int64 y) {
	if(x == 0)
		return 0;

	if(x == 1 || y == 0)
		return 1;

	int64 rez = binpow(x, y >> 1);
	rez = mult(rez, rez);

	if(y & 1)
		rez = mult(rez, x);

	return rez;
}

int64 solve_for_prime(int64 n, int64 prime) {
	int64 answ = 1;

	while(n > 0) {
		int64 cnt = n / prime;
		answ = mult(answ, binpow(prime, cnt));

		n = cnt;
	}

	return answ;
}

void solve() {
	int64 x, n, answ = 1;
	cin >> x >> n;

	for(int64 i = 2; i * i <= x; ++i) {
		if(x % i == 0) {
			answ = mult(answ, solve_for_prime(n, i));

			while(x % i == 0)
				x /= i;
		}
	}

	if(x > 1)
		answ = mult(answ, solve_for_prime(n, x));

	cout << answ << '\n';
}

int main() {
	init_IO();
	solve();

	return 0;
}