#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
#include <cmath>
#include <map>
#include <set>
#include <deque>

using namespace std;

typedef long long ll;

ll INF = 4e18;
int INFi = 2e9;
double eps = 1e-8;
ll mod = 1e9 + 7;

vector<vector<pair<int, int> >> edge;
vector<int> dist;
vector<pair<int, int>> ans;
vector<char> used;

bool dfs(int v) {
	used[v] = true;
	//cout << dist[v] << endl;
	for (auto u : edge[v]) {
		if (used[u.first] && dist[u.first] == dist[v]) return false;
		if (dist[v]) ans[u.second] = { v, u.first };
		else ans[u.second] = { u.first, v };
		if (used[u.first]) continue;
		dist[u.first] = dist[v] ^ 1;
		bool fl = dfs(u.first);
		if (!fl) return false;
	}
	return true;
}

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
		
	int n, m;
	cin >> n >> m;
	edge.resize(n);
	dist.resize(n);
	ans.resize(m);
	used.resize(n);
	int t1, t2;
	vector<pair<int, int>> qu(m);
	for (int i = 0; i < m; i++) {
		cin >> t1 >> t2; t1--; t2--;
		qu[i] = { t1, t2 };
		edge[t1].push_back({ t2, i });
		edge[t2].push_back({ t1, i });
	}
	bool fl = dfs(0);
	if (!fl) cout << "NO\n";
	else {
		cout << "YES\n";
		for (int i = 0; i < m; i++) {
			if (ans[i] == qu[i]) cout << 1;
			else cout << 0;
		}
		cout << endl;
	}
//	system("pause");
	return 0;
}