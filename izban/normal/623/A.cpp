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

const int MAXN = -1;
const int MOD = 1; // 1000 * 1000 * 1000 + 7;
const double PHI = (sqrt(5.0) - 1) / 2.0;



int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

	int n, m;
	while (cin >> n >> m) {
		vector<vector<int> > e(n);
		vector<vector<int> > a(n, vector<int>(n));
		for (int i = 0; i < m; i++) {
			int u, v;
			cin >> u >> v;
			--u; --v;
			e[u].push_back(v);
			e[v].push_back(u);
			a[v][u] = a[u][v] = 1;
		}
		vector<char> cc(n, 0);
		bool first = 1;
		for (int i = 0; i < n; i++) {
			if (e[i].size() == n - 1) {
				cc[i] = 'b';
			}
			else {
				if (first) {
					cc[i] = 'a';
					for (int j = 0; j < n; j++) {
						if (i != j && a[i][j] && e[j].size() != n - 1) {
							cc[j] = 'a';
						}
					}
					first = 0;
				}
				else {
					if (cc[i] == 0) cc[i] = 'c';
				}
			}
		}
		string s;
		for (int i = 0; i < n; i++) s += cc[i];

		bool ok = 1;
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				ok &= a[i][j] == (abs(s[i] - s[j]) <= 1);
			}
		}
		if (ok) cout << "Yes" << endl << s << endl;
		else cout << "No" << endl;
	}

	return 0;
}