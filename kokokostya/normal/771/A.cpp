#define _CRT_SECURE_NO_WARNINGS
//#pragma comment(linker, "/STACK:16777216")

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map>
#include <queue>
#include <set>
#include <bitset>

using namespace std;

vector < long long > us;
vector < vector < long long > > g;

pair < long long, long long > dfs(long long v) {
	us[v] = 1;
	pair < long long, long long > x = { 1, 0 };
	for (long long i : g[v]) {
		if (us[i]) {
			x.second++;
			continue;
		}
		auto y = dfs(i);
		x.first += y.first;
		x.second += y.second + 1;
	}
	return x;
}

int main() {
	iostream::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	long long n, m;
	cin >> n >> m;

	us.resize(n, 0);
	g.resize(n);

	while (m--) {
		long long x, y;
		cin >> x >> y;
		x--, y--;
		g[x].push_back(y);
		g[y].push_back(x);
	}

	for (long long i = 0; i < n; i++) {
		if (!us[i]) {
			auto x = dfs(i);
			if (x.second != (x.first * (x.first - 1))) {
				cout << "NO\n";
				return 0;
			}
		}
	}

	cout << "YES\n";

	return 0;
}