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

vector<int> g[10000];
vector<int> used(10000, 0);

bool can = true;

void dfs(int v) {
	if (!can) {
		return;
	}
	used[v] = 1;

	for (auto u: g[v]) {
		if (used[u] == 1) {
			can = false;
			return;
		}
		if (!can) {
			return;
		}

		if (used[u] == 0) {
			dfs(u);
		}
	}

	used[v] = 2;
}

signed main() {
	int n, m;
	cin >> n >> m;

	vector<int> ans(m);
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;

		if (a > b) {
			ans[i] = 2;
		} else {
			ans[i] = 1;
		}
		a--;
		b--;
		g[a].push_back(b);
	}

	for (int i = 0; i < n; i++) {
		if (used[i] == 0) {
			dfs(i);
		}
	}


	if (can == true) {
		cout << 1 << endl;
		for (int i = 0; i < m; i++) {
			cout << 1 << " ";
		}
	} else {
		cout << 2 << endl;
		for (int i = 0; i < m; i++) {
			cout << ans[i] << " ";
		}
	}

}