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

const int maxn = 128;
const int inf = 1000000007;
const int mod = 1000000007;


int n;
vector<pair<int, int> > a;
vector<int> e[maxn], vis;
const string ans[2] = {"NO", "YES"};

void dfs(int v) {
	if (vis[v]) return;
	vis[v] = 1;
	for (int i = 0; i < e[v].size(); i++) dfs(e[v][i]);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	while (cin >> n) {
		for (int i = 0; i < n; i++) {
			int t, x, y;
			cin >> t >> x >> y;
			if (t == 1) {
				for (int i = 0; i < a.size(); i++) {
					if (x < a[i].first && a[i].first < y || x < a[i].second && a[i].second < y) e[i].push_back(a.size());
					if (a[i].first < x && x < a[i].second || a[i].first < y && y < a[i].second) e[a.size()].push_back(i);
				}
				a.push_back(make_pair(x, y));
			}
			if (t == 2) {
				vis.assign(a.size(), 0);
				dfs(x - 1);
				cout << ans[vis[y - 1]] << endl;
			}
		}
	}

	return 0;
}