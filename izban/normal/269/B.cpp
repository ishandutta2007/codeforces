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

const int maxn = 5 * (1 << 10);
const int inf = 1000000007;
const int mod = 1000000007;

int n, m, a[maxn], b[maxn];
int d[maxn][maxn];
double lol;

int calc(int n, int m) {
	if (n == -1 || m == -1) return 0;
	if (d[n][m] != -1) return d[n][m];
	int res = 0;
	if (a[n] == b[m]) res = max(res, calc(n - 1, m - 1) + 1);
	else {
		res = max(res, calc(n - 1, m));
		res = max(res, calc(n, m - 1));
	}
	return d[n][m] = res;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
    
	while (cin >> n >> m) {
		memset(d, -1, sizeof(d));
		for (int i = 0; i < n; i++)
			cin >> a[i] >> lol;
		for (int i = 0; i < n; i++) b[i] = a[i];
		sort(b, b + n);
		d[0][0] = a[0] == b[0];
		for (int i = 0; i < n; i++)
			d[i][0] = a[i] == b[0], d[0][i] = a[0] == b[i];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				d[i + 1][j] = max(d[i + 1][j], d[i][j]);
				d[i][j + 1] = max(d[i][j + 1], d[i][j]);
				if (a[i + 1] == b[j + 1]) d[i + 1][j + 1] = max(d[i + 1][j + 1], d[i][j] + 1);
			}
		}
		cout << n - d[n - 1][n - 1] << endl;
		//cout << n - calc(n - 1, n - 1) << endl;
	}

	return 0;
}