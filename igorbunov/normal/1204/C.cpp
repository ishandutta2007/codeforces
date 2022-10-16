#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <fstream>
#include <stdio.h>
#include <iomanip>
#include <clocale>
#include <string>
#include <vector>
#include <cmath>
#include <ctime>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
 
#pragma GCC_OPTIMIZE("ofast")
 
using namespace std;
 

#define int long long
#define endl "\n"

int INF = 1000000000LL;

signed main() {
	int n;
	cin >> n;
	vector<vector<int>> d(n, vector<int>(n, INF));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			char c;
			cin >> c;
			if (c == '0') {
				d[i][j] = INF;
			} else {
				d[i][j] = 1;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		d[i][i] = 0;
	}

	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
			}
		}
	}

	int m;
	cin >> m;
	vector<int> p(m);

	for (int i = 0; i < m; i++) {
		cin >> p[i];
		p[i]--;
	}

	vector<int> ans;
	ans.push_back(p[0]);

	int now = p[0];
	int last = 0;

	for (int i = 1; i < m; i++) {
		if (d[now][p[i]] != i - last) {
			ans.push_back(p[i - 1]);
			now = p[i - 1];
			last = i - 1;
		}
	}

	if (ans.back() != p.back()) {
		ans.push_back(p.back());
	}

	cout << ans.size() << endl;

	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] + 1 << " ";
	}
}