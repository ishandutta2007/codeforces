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

const int maxn = 1 << 7;
const int inf = 1000000007;
const int mod = 1000000007;

int n, p, a[maxn], sum;
ll d[maxn][maxn][maxn];

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
    double fct[maxn];
	fct[0] = 1;
	for (int i = 1; i < maxn; i++)
		fct[i] = fct[i - 1] * i;

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i], sum += a[i];
	cin >> p;
	if (sum <= p) {
		cout << n;
		return 0;
	}

	double ans = 0;
	for (int o = 0; o < n; o++) {
		memset(d, 0, sizeof(d));
		d[0][0][0] = 1;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j <= n; j++) {
				for (int k = 0; k <= p; k++) {
					d[i + 1][j][k] += d[i][j][k];
					if (k + a[i] <= p && i != o)
						d[i + 1][j + 1][k + a[i]] += d[i][j][k];
				}
			}
		}

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= p; j++) if (j + a[o] > p) {
				ans += i * d[n][i][j] * fct[n - i - 1] * fct[i] / fct[n];
			}
		}
		ans = ans;
	}

	printf("%.10lf\n", ans);
	
	return 0;
}