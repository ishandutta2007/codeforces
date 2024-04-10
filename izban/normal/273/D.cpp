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

const int maxn = 160;
const int inf = 1000000007;
const int mod = 1000000007;

int n, m, ans;
int d[maxn][maxn][2][2];

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
    
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = i; j < n; j++) 
			d[i][j][0][0] = 1;
	for (int o = 0; o < m; o++) {
		for (int i = 0; i < n; i++) {
			for (int j = i; j < n; j++) {
				for (int f1 = 0; f1 < 2; f1++) {
					for (int f2 = 0; f2 < 2; f2++) {
						ans = (ans + 1LL * d[i][j][f1][f2] * (m - o)) % mod;
					}
				}
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = i; j < n; j++) {
				for (int f1 = 0; f1 < 2; f1++) {
					for (int f2 = 0; f2 < 2; f2++) {
						if (i < j) d[i + 1][j][1][f2] = (d[i + 1][j][1][f2] + d[i][j][f1][f2]) % mod;
					}
				}
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = n - 1; j >= i; j--) {
				for (int f1 = 0; f1 < 2; f1++) {
					for (int f2 = 0; f2 < 2; f2++) {
						if (j > i) d[i][j - 1][f1][1] = (d[i][j - 1][f1][1] + d[i][j][f1][f2]) % mod;
					}
				}
			}
		}
		for (int i = n - 1; i >= 0; i--) {
			for (int j = i; j < n; j++) {
				for (int f2 = 0; f2 < 2; f2++) {
					if (i) d[i - 1][j][0][f2] = (d[i - 1][j][0][f2] + d[i][j][0][f2]) % mod;
					//d[i][j][1][f2] = (d[i][j][1][f2] + d[i][j][0][f2]) % mod;
				}
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = i; j < n; j++) {
				for (int f1 = 0; f1 < 2; f1++) {
					if (j < n - 1) d[i][j + 1][f1][0] = (d[i][j + 1][f1][0] + d[i][j][f1][0]) % mod;
					//d[i][j][f1][1] = (d[i][j][f1][1] + d[i][j][f1][0]) % mod;
				}
			}
		}
	}

	cout << ans;

	return 0;
}