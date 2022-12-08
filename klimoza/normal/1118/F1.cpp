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

int cnt1, cnt2;
vector<int> cols;
vector<vector<int>> edge;
vector<pair<int, int>> cnt;
int ans = 0;

void dfs(int v, int p) {
	if (cols[v] == 1) cnt[v].first++;
	else if (cols[v] == 2) cnt[v].second++;
	for (int u : edge[v]) {
		if (u == p) continue;
		dfs(u, v);
		if (cnt[u].first == cnt1 && cnt[u].second == 0) ans++;
		else if (cnt[u].first == 0 && cnt[u].second == cnt2) ans++;
		cnt[v].first += cnt[u].first;
		cnt[v].second += cnt[u].second;
	}
}

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
	
	int n;
	cin >> n;
	cols.resize(n);
	edge.resize(n);
	cnt.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> cols[i];
		if (cols[i] == 1) cnt1++;
		else if (cols[i] == 2) cnt2++;
	}
	int t1, t2;
	for (int i = 0; i < n - 1; i++) {
		cin >> t1 >> t2; t1--; t2--;
		edge[t1].push_back(t2);
		edge[t2].push_back(t1);
	}
	dfs(0, -1);
	cout << ans << endl;
	//system("pause");
	return 0;
}