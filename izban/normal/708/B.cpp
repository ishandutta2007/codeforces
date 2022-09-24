#include <sstream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <string>
#include <cassert>
#include <ctime>
#include <map>
#include <math.h>
#include <cstdio>
#include <set>
#include <deque>
#include <memory.h>
#include <queue>

#pragma comment(linker, "/STACK:64000000")
typedef long long ll;

using namespace std;

const int MAXK = -1;
const int MAXN = -1;
const int MOD = 1; // 1000 * 1000 * 1000 + 7;

int f(int n) {
	int ans = 0;
	while (ans * (ans - 1) / 2 < n) ans++;
	if (ans * (ans - 1) / 2 != n) return -1;
	return ans;
}
const string FAIL = "Impossible";

string fastsolve(int a00, int a01, int a10, int a11) {
	int _zeroes = f(a00);
	int _ones = f(a11);

	if (_zeroes == -1) return FAIL;
	if (_ones == -1) return FAIL;

	for (int zeroes = _zeroes; zeroes <= _zeroes + !_zeroes; zeroes++) {
		for (int ones = _ones; ones <= _ones + !_ones; ones++) {
			if (a01 + a10 != 1LL * zeroes * ones) continue;
			if (zeroes == 0 && ones == 0) continue;
			string cur = "";

			/*int c01 = a01, c10 = a10;
			int c0 = zeroes;
			int c1 = ones;
			for (int i = 0; i < zeroes + ones; i++) {
				if (c01 >= c10 && (c0 > 1 || c01 == 0) || c01 > 0 && c10 == 1 && c1 == 1) {
					c01 -= c1;
					c0--;
					cur += (char)('0');
				}
				else {
					c10 -= c0;
					c1--;
					cur += (char)('1');
				}
			}
			assert(c0 == 0);
			assert(c1 == 0);
			assert(c01 == 0);
			assert(c10 == 0);
			return cur;*/
			string a = "";
			for (int i = 0; i < zeroes; i++) a += (char)('0');
			for (int i = 0; i < ones; i++) a += (char)('1');

			int c10 = a10, c01 = a01, c0 = zeroes, c1 = ones;
			for (int i = 0; i < ones; i++) {
				if (c10 >= c0) {
					swap(a[i], a[zeroes + i]);
					c10 -= c0;
				}
				else {
					swap(a[zeroes + i], a[zeroes + i - c10]);
					break;
				}
			}
			int n = a.length();
			/*vector<vector<int> > b(2, vector<int>(2));
			for (int i = 0; i < n; i++) {
				for (int j = i + 1; j < n; j++) {
					b[a[i] - '0'][a[j] - '0']++;
				}
			}
			if (b[0][0] != a00 || b[0][1] != a01 || b[1][0] != a10 || b[1][1] != a11) {
				assert(b[0][0] == a00);
				assert(b[0][1] == a01);
				assert(b[1][0] == a10);
				assert(b[1][1] == a11);
			}*/

			return a;
		}
	}
	return FAIL;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

	/*int n = 10;
	for (int mask = 0; mask < 1 << n; mask++) {
		string cur = "";
		for (int i = 0; i < n; i++) cur += (char)('0' + ((mask >> i) & 1));

		vector<vector<int> > a(2, vector<int>(2));
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				a[cur[i] - '0'][cur[j] - '0']++;
			}
		}
		cerr << cur << endl;
		string s = fastsolve(a[0][0], a[0][1], a[1][0], a[1][1]);
		assert(s != FAIL);
	}*/

	int a00, a01, a10, a11;
	while (cin >> a00 >> a01 >> a10 >> a11) {
		cout << fastsolve(a00, a01, a10, a11) << endl;

	}

	return 0;
}