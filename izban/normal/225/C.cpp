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

using namespace std;

#define ll long long


const int maxn = 1 << 10;
const int inf = 1000000000;


int n, m, x, y, sum[maxn][2];
string a[maxn];
int d[maxn][maxn][2];

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
    
	cin >> n >> m >> x >> y;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			sum[j][0] += a[i][j] == '.';
			sum[j][1] += a[i][j] == '#';
		}
	}

	for (int i = 0; i < maxn; i++)
		for (int j = 0; j < maxn; j++)
			d[i][j][0] = d[i][j][1] = inf;

	d[0][1][0] = sum[0][0];
	d[0][1][1] = sum[0][1];

	for (int i = 0; i < m-1; i++) {
		for (int j = 1; j <= m; j++) {
			for (int k = 0; k < 2; k++) {
				if (j < y) {
					d[i+1][j+1][k] = min(d[i+1][j+1][k], d[i][j][k] + sum[i+1][k]);
				}
				if (j >= x) {
					d[i+1][1][k^1] = min(d[i+1][1][k^1], d[i][j][k] + sum[i+1][k^1]);
				}
			}
		}
	}

	int ans = inf;
	for (int i = x; i <= y; i++)
		ans = min(ans, min(d[m-1][i][0], d[m-1][i][1]));

	cout << ans;

	return 0;
}