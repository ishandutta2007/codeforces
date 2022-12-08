#pragma optimise("O3");
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <cmath>
#include <algorithm>
#include <deque>

using namespace std;

#define PI 3.14159265
typedef long long ll;

const ll INF = 1e18;
ll mod = 998244353;

vector<vector<pair<int, int>>> edge;

bool dfs(int v, int c, vector<int> &ans) {
	ans[v] = c;
	for (auto u : edge[v]) {
		//cout << v << " " << u.first << " " << ans[u.first] << " " << c << " " << u.second << endl;
		if (!ans[u.first]) {
			if (!dfs(u.first, c * u.second, ans)) return false;
		}
		else {
			if (ans[u.first] != c * u.second) return false;
		}
	}
	return true;
}




int main() {
	int n, m;
	cin >> n >> m;
	int t1, t2, t3;
	edge.resize(n);
	for (int i = 0; i < m; i++) {
		cin >> t1 >> t2 >> t3; t1--; t2--;
		if (t3 == 0) t3 = -1;
		edge[t1].push_back({ t2, t3 });
		edge[t2].push_back({ t1, t3 });
	}
	vector<int> ans(n);
	vector<int> an(n);
	for (int i = 0; i < n; i++) {
		if (!ans[i]) {
			if (dfs(i, 1, ans)) {
				an = ans;
			}
			else if (dfs(i, -1, an)) {
				ans = an;
			}
			else {
				cout << "Impossible" << endl;
				//system("pause");
				return 0;
			}
		}
	}
	vector<int> f;
	for (int i = 0; i < n; i++) {
		if (ans[i] == 1) f.push_back(i + 1);
	}
	cout << f.size() << endl;
	for (int i : f) cout << i << " ";
	cout << endl;
	//system("pause");
	return 0;
}