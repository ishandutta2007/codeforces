#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
#include <cmath>
#include <map>
#include <set>
#include <deque>
#include <cassert>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <random>

using namespace std;

typedef long long ll;

ll INF = 1e18;
int INFi = 2e9;
double eps = 1e-6;
ll mod = 1e9 + 7;

vector<char> used;
vector<vector<int>> edge;
vector<int> p;
vector<int> cnt;
int sz = 0;

void add(int beg, int end) {
	while (beg != end) {
		cnt[beg]++;
		beg = p[beg];
	}
}

void sub(int beg) {
	while (used[beg] == 2) {
		cnt[beg]--;
		beg = p[beg];
	}
}

void dfs(int v) {
	used[v] = 1;
	//cout << v + 1 << endl;
	for (int u : edge[v]) {
		if (used[u] == -1) {
			continue;
		}
		if (used[u] == 2) {
			sub(u);
			continue;
		}
		if (used[u] == 1) {
			add(v, u);
			sz++;
			continue;
		}
		p[u] = v;
		dfs(u);
	}
	used[v] = 2;
}


int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	edge.resize(n);
	used.resize(n);
	p.resize(n);
	cnt.resize(n);
	int t1, t2;
	for (int i = 0; i < m; i++) {
		cin >> t1 >> t2; t1--; t2--;
		edge[t1].push_back(t2);
	}
	for (int i = 0; i < n; i++) {
		if (!used[i]) dfs(i);
		for (int j = 0; j < n; j++) {
			if (used[j] == 2) used[j] = -1;
		}
	}
	for (int i = 0; i < n; i++) {
		if (cnt[i] == sz) {
			//cout << i << endl;
			cout << "YES\n";
			return 0;
		}
	}
	if (sz == 1) {
		cout << "YES\n";
	}
	else {
		cout << "NO\n";
	}
	//system("pause");
	return 0;
}