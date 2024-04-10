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
double eps = 1e-10;

vector<pair<int, int>> ans;
vector<char> used;
vector<vector<int>> edge;

void dfs(int v) {
	used[v] = true;
	for (int u : edge[v]) {
		if (used[u]) continue;
		ans.push_back({ v + 1, u + 1 });
		dfs(u);
	}
}

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	vector<int> cnt(n);
	int t1, t2;
	edge.resize(n);
	int maxi = 0;
	for (int i = 0; i < m; i++) {
		cin >> t1 >> t2; t1--; t2--;
		edge[t1].push_back(t2);
		edge[t2].push_back(t1);
		cnt[t1]++;
		cnt[t2]++;
		if (cnt[maxi] < cnt[t1]) maxi = t1;
		if (cnt[maxi] < cnt[t2]) maxi = t2;
	}
	used.resize(n);
	used[maxi] = true;
	for (int u : edge[maxi]) {
		used[u] = true;
		ans.push_back({ maxi + 1, u + 1 });
	}
	for (int u : edge[maxi]) {
		dfs(u);
	}
	for (auto ed : ans) {
		cout << ed.first << " " << ed.second << endl;
	}
	//system("pause");
	return 0;
}