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
#include <assert.h>

using namespace std;

#define ll long long

const int maxn = 1 << 7;
const int mod = 1000000007;


int n, k;
ll m;
int c[maxn][maxn], d[maxn][maxn * maxn], C[maxn][2];

int binpow(int x, ll y) {
	if (!y) return 1;
	if (y == 1) return x;
	int res = binpow(x, y / 2);
	res = (1LL * res * res) % mod;
	if (y & 1)
		res = (1LL * res * x) % mod;
	return res;
}

void calcc() {
	c[0][0] = 1;
	for (int i = 0; i < maxn-1; i++)
		for (int j = 0; j <= i; j++) {
			c[i+1][j] = (c[i+1][j] + c[i][j]) % mod;
			c[i+1][j+1] = (c[i+1][j+1] + c[i][j]) % mod;
		}
	for (int i = 0; i <= n; i++) {
		C[i][0] = binpow(c[n][i], m / n);
		C[i][1] = binpow(c[n][i], m / n + 1);
	}
}

int pow(int x, int y) {
	return C[x][y];
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	cin >> n >> m >> k;
	calcc();

	d[0][0] = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= k; j++) {
			for (int o = 0; o <= n && j + o <= k; o++) {
				d[i+1][j+o] += 1LL * d[i][j] * C[o][i < m % n] % mod;
				if (d[i+1][j+o] >= mod)
					d[i+1][j+o] -= mod;
			}
		}
	}
	cout << d[n][k];

	return 0;
}