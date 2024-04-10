#include <sstream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <string>
#include <cassert>
#include <ctime>
#include <map>
#include <math.h>
#include <cstdio>
#include <set>
#include <deque>
#include <memory.h>
#include <queue>

#pragma comment(linker, "/STACK:64000000")
typedef long long ll;

using namespace std;

const int MAXK = -1;
const int MAXN = -1;
const int MOD = 1; // 1000 * 1000 * 1000 + 7;



int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

	int n, m;
	while (cin >> n >> m) {
		vector<vector<int> > a(n, vector<int>(m));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> a[i][j];
			}
		}

		bool ok = 0;
		for (int j1 = 0; j1 < m; j1++) {
			for (int j2 = j1; j2 < m; j2++) {
				vector<vector<int> > b = a;
				for (int i = 0; i < n; i++) swap(b[i][j1], b[i][j2]);
				bool cok = 1;
				for (int i = 0; i < n; i++) {
					int cnt = 0;
					for (int j = 0; j < m; j++) {
						cnt += b[i][j] != j + 1;
					}
					cok &= cnt <= 2;
				}
				ok |= cok;
			}
		}
		string res;
		if (ok) res = "YES";
		else res = "NO";

		cout << res << endl;
	}

	return 0;
}