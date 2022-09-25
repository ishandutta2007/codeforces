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
#include <cassert>
#include <ctime>


using namespace std;

#define ll long long
#pragma comment(linker, "/STACK:64000000")

const int maxn = 1 << 17;
const int inf = 1000000007;
const int mod = 1000000007;


int n;
string a, b;

void add(int &a, int b) {
	a += b;
	if (a >= mod) a -= mod;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	while (cin >> n >> a >> b) {
		vector<vector<vector<int> > > d(n + 1, vector<vector<int> >(2, vector<int>(2, 0)));
		d[0][0][0] = 1;
		for (int i = 0; i < n; i++) {
			for (int x = 0; x <= 1; x++) {
				for (int y = 0; y <= 1; y++) {
					if (a[i] != '?' && b[i] != '?') {
						int nx, ny;
						nx = x || a[i] < b[i];
						ny = y || a[i] > b[i];
						add(d[i + 1][nx][ny], d[i][x][y]);
					}
					if (a[i] == '?' && b[i] != '?') {
						add(d[i + 1][1][y], 1LL * d[i][x][y] * (b[i] - '0') % mod);
						add(d[i + 1][x][1], 1LL * d[i][x][y] * ('9' - b[i]) % mod);
						add(d[i + 1][x][y], 1LL * d[i][x][y] * 1 % mod);
					}
					if (a[i] != '?' && b[i] == '?') {
						add(d[i + 1][1][y], 1LL * d[i][x][y] * ('9' - a[i]) % mod);
						add(d[i + 1][x][1], 1LL * d[i][x][y] * (a[i] - '0') % mod);
						add(d[i + 1][x][y], 1LL * d[i][x][y] * 1 % mod);
					}
					if (a[i] == '?' && b[i] == '?') {
						add(d[i + 1][1][y], 1LL * d[i][x][y] * 45 % mod);
						add(d[i + 1][x][1], 1LL * d[i][x][y] * 45 % mod);
						add(d[i + 1][x][y], 1LL * d[i][x][y] * 10 % mod);
					}
				}
			}
		}
		cout << d[n][1][1] << endl;
	}

	return 0;
}