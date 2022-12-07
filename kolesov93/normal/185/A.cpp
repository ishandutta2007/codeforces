#include <stdio.h>
#include <algorithm>
#include <queue>
#include <deque>
#include <memory.h>
#include <map>
#include <set>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include <iostream>
#include <tchar.h>

using namespace std;

typedef long long ll;

const ll MOD = 1000000007;
ll a[2][2], b[2][2], c[2][2], d[2][2];

int main() {
	//freopen("in", "r", stdin);
	//freopen("out", "w", stdout);

	a[0][0] = a[1][1] = 3;
	a[1][0] = a[0][1] = 1;
	b[0][0] = b[1][1] = 1;

	ll n;
	cin >> n;


	while (n) {
		if (n & 1) {
			for (int i = 0; i < 2; ++i)
				for (int j = 0; j < 2; ++j) {
					c[i][j] = 0;
					for (int k = 0; k < 2; ++k) {
						c[i][j] = (c[i][j] + b[i][k] * a[k][j]) % MOD;
					}
				}
			for (int i = 0; i < 2; ++i)
				for (int j = 0; j < 2; ++j) b[i][j] = c[i][j];
		}

		for (int i = 0; i < 2; ++i)
				for (int j = 0; j < 2; ++j) {
					c[i][j] = 0;
					for (int k = 0; k < 2; ++k) {
						c[i][j] = (c[i][j] + a[i][k] * a[k][j]) % MOD;
					}
				}
		for (int i = 0; i < 2; ++i)
				for (int j = 0; j < 2; ++j) a[i][j] = c[i][j];

		n >>= 1;
	}

	cout << b[0][0] << endl;

	return 0;
}