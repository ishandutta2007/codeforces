
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#include <string>
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <stack>
#include <bitset>
#include <cmath>
#include <iomanip>
#include <functional>
#include <cstring>

using namespace std;

typedef long long ll;
const ll md = 1e9 + 7;
const int MX = 1e6 + 1;

int ans = 1e9;
vector<vector<int>> dv(MX);
vector<vector<int>> us(MX, vector<int>(3, 0));

void bfs(int v, int d) {
	if (us[v][d]) {
		return;
	}
	us[v][d] = 1;
	if (d == 0) {
		ans = min(ans, v);
		return;
	}
	//cerr << v << '\n';
	if (dv[v].empty()) {
		return;
	}
	for (int df : dv[v]) {
		for (int bg = v - df + 1; bg <= v - df + 1; bg++) {
			bfs(bg, d - 1);
		}
	}
	bfs(v, d - 1);
}

int main() {
    iostream::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	for (int i = 2; i < MX; i++) {
		if (dv[i].size()) {
			continue;
		}
		for (int j = i + i; j < MX; j += i) {
			dv[j].push_back(i);
		}
	}
	

	int fn;
	cin >> fn;

	int mx = 0;
	for (int d : dv[fn]) {
		mx = max(mx, d);
	}

	for (int bg = fn - mx + 1; bg <= fn; bg++) {
		if (dv[bg].empty()) {
			continue;
		}
		int c = 0;
		for (int d : dv[bg]) {
			c = max(c, d);
		}
		ans = min(ans, bg - c + 1);
	}

	cout << ans;

    return 0;
}