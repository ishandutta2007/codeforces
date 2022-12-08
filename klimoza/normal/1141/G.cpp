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
long double eps = 1e-8;

int r = 1;
vector<int> ans;
vector<vector<pair<int, int>>> edge;
vector<bool> bad;

void dfs(int v, int p = -1, int col = -1) {
	int cur = 0;
	//cout << v << " " << p << " " << col << endl;
	for (auto u : edge[v]) {
		if (u.first == p) continue;
		if (cur == col) cur++;
		if (bad[v]) {
			ans[u.second] = max(col, 0);
		}
		else {
			ans[u.second] = cur;
			cur++;
		}
		dfs(u.first, v, ans[u.second]);
	}
}


int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
	
	int n, k;
	cin >> n >> k;
	vector<pair<int, int>> cnt(n);
	edge.resize(n);
	bad.resize(n);
	ans.resize(n - 1);
	int t1, t2;
	for (int i = 0; i < n; i++) {
		cnt[i] = { 0, i };
	}
	for (int i = 0; i < n - 1; i++) {
		cin >> t1 >> t2; t1--; t2--;
		edge[t1].push_back({ t2, i });
		edge[t2].push_back({ t1, i });
		cnt[t1].first++;
		cnt[t2].first++;
	}
	sort(cnt.begin(), cnt.end());
	int ind = 0;
	while (ind < n) {
		if (cnt[ind].first <= r) ind++;
		else if (n - ind <= k) break;
		else r++;
	}
	for (; ind < n; ind++) {
		bad[cnt[ind].second] = true;
	}
	dfs(0);
	cout << r << endl;
	for (int i : ans) cout << i + 1 << " ";
	cout << endl;
	//system("pause");
	return 0;
}