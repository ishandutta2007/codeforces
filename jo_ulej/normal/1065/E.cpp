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
const int MOD = 998244353;
const int INV2 = (MOD + 1) / 2;

int add(int x, int y) {
	return (x + y >= MOD ? x + y - MOD : x + y);
}

int sub(int x, int y) {
	return (x - y < 0 ? x - y + MOD : x - y);
}

int mult(int x, int y) {
	return (x * 1LL * y) % MOD;
}

int binpow(int x, int y) {
	if(x == 1 || y == 0)
		return 1;

	if(x == 0)
		return 0;

	int rez = binpow(x, y / 2);
	rez = mult(rez, rez);

	if(y & 1)
		rez = mult(rez, x);

	return rez;
}

void init_IO() {
	std::ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
}

const int MAX_M = (int)2e5 + 777;

int n, m, A;
int b[MAX_M];

int count(int sz) {
	return binpow(A, sz);
}

int count_pairs(int sz) {
	int rez = count(sz);
	rez = mult(rez, add(rez, 1));
	rez = mult(rez, INV2);

	return rez;
}

void solve() {
	cin >> n >> m >> A;
	
	if(A >= MOD)
		A -= MOD;

	for(int i = 0; i < m; ++i) {
		cin >> b[i];
		--b[i];
	}

	int answ = 1;

	if(n & 1) {
		--n;
		answ = mult(answ, A);
	}

	//cout << "answ1 = " << answ << '\n';

	for(int i = 0; i < m; ++i) {
		int d = b[i];

		if(i > 0) {
			d -= b[i - 1];
		} else {
			++d;
		}

		answ = mult(answ, count_pairs(d));
	}

	//cout << "magic = " << n / 2 - 1 - b[m - 1] << '\n';
	answ = mult(answ, count(n / 2 - 1 - b[m - 1]));
	answ = mult(answ, count(n / 2 - 1 - b[m - 1]));

	cout << answ << '\n';
}

int main() {
	init_IO();
	solve();

	return 0;
}