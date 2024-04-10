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

const int maxn = 1 << 10;
const int inf = 1000000007;
const int mod = 1000000007;

int n, m;
bool row[maxn], col[maxn];

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	while (cin >> n >> m) {
		memset(row, 0, sizeof(row));
		memset(col, 0, sizeof(col));

		for (int i = 0; i < m; i++) {
			int x, y;
			cin >> x >> y;
			row[x] = true;
			col[y] = true;
		}

		int res = 0;
		for (int i = 2; i < n - i + 1; i++) {
			int j = n - i + 1;
			//row[i], !row[i], row[j], !row[j], col[i], !col[i], col[j], !col[j]
			vector<vector<int> > a(8, vector<int>(8, 1));
			a[0][1] = a[1][0] = 0;
			a[2][3] = a[3][2] = 0;
			a[4][5] = a[5][4] = 0;
			a[6][7] = a[7][6] = 0;
			a[0][4] = a[4][0] = 0;
			a[1][5] = a[5][1] = 0;
			a[2][6] = a[6][2] = 0;
			a[3][7] = a[7][3] = 0;
			if (row[i]) a[0][0] = a[1][1] = 0;
			if (row[j]) a[2][2] = a[3][3] = 0;
			if (col[i]) a[4][4] = a[5][5] = 0;
			if (col[j]) a[6][6] = a[7][7] = 0;

			int o = 0;
			for (int mask = 0; mask < 1 << 8; mask++) {
				vector<int> v;
				for (int k = 0; k < 8; k++) if (mask & (1 << k)) v.push_back(k);
				bool ok = 1;
				for (int k1 = 0; k1 < v.size(); k1++) for (int k2 = 0; k2 < v.size(); k2++) ok &= a[v[k1]][v[k2]];
				if (ok) o = max(o, (int)v.size());
			}
			res += o;

		}
		if (n % 2) {
			res += !row[(n + 1) / 2] || !col[(n + 1) / 2];
		}

		cout << res << endl;
	}

	return 0;
}