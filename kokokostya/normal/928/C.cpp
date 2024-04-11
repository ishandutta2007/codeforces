


#define _CRT_SECURE_NO_WARNINGS


#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <set>
#include <iomanip>
#include <map>
#include <stack>
#include <bitset>
#include <deque>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <random>

using namespace std;

//#define FAST_ALLOCATOR_MEMORY 1e8
#undef LOCAL
//#include "optimization.h"

vector<int> d;
vector<string> name;
vector<int> vers, p;
const int INF = 1e9;
int timer = 0;
map< string, set< pair<int, pair<int, int> > > > q;
vector< vector< pair<string, int> > > g;

map< pair<string, int>, int > w;

vector< pair<string, int> > ans;

map<string, bool> used;

void bfs() {
	d[0] = 0;
	queue<int> q, t;
	t.push(0);
	while (!t.empty()) {
		map<string, set<pair<int, int>> > val;
		while (!t.empty()) {
			int v = t.front();
			t.pop();
			val[name[v]].insert({ -vers[v], v });
		}
		for (auto j : val) {
			if (!used[j.first]) {
				auto k = (*j.second.begin());
				q.push({ k.second });
				if (k.second)
					ans.push_back({ j.first, -k.first });
				used[j.first] = 1;
			}
		}
		while (!q.empty()) {
			int v = q.front();
			q.pop();
			for (auto j : g[v]) {
				if (d[w[j]] == INF) {
					t.push(w[j]);
					d[w[j]] = d[v] + 1;
				}
			}
		}
	}
}

int main() {
	iostream::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n;
	cin >> n;
	d.resize(n, INF); name.resize(n); vers.resize(n);
	p.resize(n); g.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> name[i] >> vers[i];
		w[{name[i], vers[i]}] = i;
		int k;
		cin >> k;
		for (int j = 0; j < k; j++) {
			string s;
			int val;
			cin >> s >> val;
			g[i].push_back(make_pair(s, val));
		}
	}
	bfs();

	sort(ans.begin(), ans.end());
	cout << ans.size() << '\n';
	for (auto i : ans)
		cout << i.first << ' ' << i.second << '\n';
	return 0;
}