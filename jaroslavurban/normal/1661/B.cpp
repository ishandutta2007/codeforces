#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int C = 32768;

void ProGamerMove() {
	array<int, C> cost{}, vis{};
	array<vector<int>, C> div;
	for (int i = 1; i < C; ++i) div[2 * i % C].push_back(i);
	queue<int> q; q.push(0);
	vis[0] = true;
	while (q.size()) {
		int u = q.front(); q.pop();
		int v = (u - 1 + C) % C;
		if (!vis[v]) {
			cost[v] = cost[u] + 1;
			vis[v] = true;
			q.push(v);
		}
		for (int v : div[u]) if (!vis[v]) {
			cost[v] = cost[u] + 1;
			vis[v] = true;
			q.push(v);
		}
	}
	int n; cin >> n;
	vector<int> a(n);
	for (int& v : a) cin >> v;
	for (int v : a) cout << cost[v] << "\n";
}

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	cout << setprecision(9) << fixed;
	int tc = 1;
//	cin >> tc;
	while (tc--) ProGamerMove();
}