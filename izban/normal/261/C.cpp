#include <iostream>
#include <string>
#include <map> 
#include <math.h>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <set>
#include <queue>
#include <sstream>
#include <deque>
#include <memory.h>


using namespace std;

#define ll long long
#pragma comment(linker, "/STACK:64000000")

const int maxn = 1 << 10, maxm = 60;
const int inf = 1000000007;
const int mod = 1000000007;

ll n, t;
int a[maxn][maxn];
ll c[maxm][maxm];

void precalc() {
	c[0][0] = 1;
	for (int i = 0; i < maxm - 1; i++)
		for (int j = 0; j <= i; j++) {
			c[i + 1][j] += c[i][j];
			c[i + 1][j + 1] += c[i][j];
		}
}

void build(int m) {
	for (int i = 0; i < m; i++)
		a[0][i] = 0;
	a[0][m] = 1;
	for (int i = 1; i <= m; i++) {
		for (int j = 0; j <= m; j++) {
			if (j == 0) {
				a[i][j] = a[i - 1][j + 1];
			} else {
				if (j == m) {
					a[i][j] = a[i - 1][j - 1];
				} else {
					a[i][j] = a[i - 1][j - 1] ^ a[i - 1][j + 1];
				}
			}
		}
	}
}

void print(int m) {
	for (int i = 0; i <= m; i++)
		for (int j = 0; j <= m; j++)
			cout << a[i][j] << " \n"[j == m];
}

int sum (int m) {
	int res = 0;
	for (int i = 0; i <= m; i++)
		res += a[m][i];
	return res;
}

int lg(ll t) {
	int a = 0;
	while (t) {
		t >>= 1;
		a++;
	}
	return a;
}

ll calc(ll x, int y) {
	if (y == 0) return 1;
	if (x == 0) return y == 0;
	ll res = c[lg(x) - 1][y];
	res += calc(x - (1LL << (lg(x) - 1)), y - 1);
	return res;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
    precalc();
	cin >> n >> t;
	if (t & (t - 1)) {
		cout << 0;
		return 0;
	}
	int a = lg(t);
	cout << calc(n + 1, a) - (t == 1);
	/*for (int i = 1; i <= 1000; i++) {
		build(i);
		print(i);
		cout << i << ": " << sum(i) << endl;
	}*/

	return 0;
}