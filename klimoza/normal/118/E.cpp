#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <cmath>
#include <algorithm>
#include <deque>
#include <cassert>
#include <math.h>
#include <random>

using namespace std;

#define PI 3.14159265
typedef long long ll;

const ll INF = 4 * 1e18;
const int INFi = 2 * 1e9;
ll mod = 1e9 + 7;

vector<vector<pair<int, int>>> edge;
vector<pair<int, int>> ans;
bool fl = true;

vector<char> used;
vector<int> tin;
vector<int> up;
int timer = 0;

void dfs(int v, int p) {
	tin[v] = up[v] = timer++;
	//cout << v << endl;
	used[v] = true;
	for (auto u : edge[v]) {
		if (u.first == p) continue;
		if (!used[u.first]) {
			dfs(u.first, v);
			up[v] = min(up[v], up[u.first]);
		}
		up[v] = min(tin[u.first], up[v]);
		if (ans[u.second] ==make_pair(-1, -1))
		ans[u.second] = { v + 1, u.first + 1 };
		if (up[u.first] > tin[v]) {
			fl = false;
		}
	}
}


int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	int t1, t2;
	edge.resize(n);
	for (int i = 0; i < m; i++) {
		cin >> t1 >> t2; t1--; t2--;
		edge[t1].push_back({ t2, i });
		edge[t2].push_back({ t1, i });
	}
	ans.assign(m, { -1, -1 });
	tin.resize(n);
	up.resize(n);
	used.resize(n);
	dfs(0, -1);
	if (!fl) {
		cout << 0 << endl;
	}
	else {
		for (auto e : ans) {
			cout << e.first << " " << e.second << endl;
		}
	}
	//system("pause");
	return 0;
}