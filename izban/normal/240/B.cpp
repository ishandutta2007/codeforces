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
#pragma comment(linker, "/STACK:64000000")


const int maxn = 1 << 8;

int n, A, B;
int a[maxn], sum[maxn];
int d[maxn][maxn*maxn][2];

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
    
	cin >> n >> A >> B;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (i)
			sum[i] = sum[i-1] + a[i];
		else
			sum[i] = a[i];
	}
	
	memset(d, 127, sizeof(d));
	d[0][A][0] = d[0][A][1] = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= A; j++) {
			int c1 = j, c2 = B - ((i ? sum[i-1] : 0) - (A - j));
			for (int k = 0; k < 2; k++) if (d[i][j][k] < 10000000) {
				if (c2 >= a[i])
					d[i+1][c1][1] = min(d[i+1][c1][1], d[i][c1][k] + (k == 1 ? 0 : min(a[i], i ? a[i-1] : 0)));
				if (c1 >= a[i])
					d[i+1][c1-a[i]][0] = min(d[i+1][c1-a[i]][0], d[i][c1][k] +(k == 0 ? 0 : min(a[i], i ? a[i-1] : 0)));
			}
		}
	}

	int ans = 10000000;
	for (int i = 0; i <= A; i++)
		ans = min(ans, min(d[n][i][0], d[n][i][1]));
	if (ans == 10000000)
		cout << -1;
	else cout << ans;

	return 0;
}