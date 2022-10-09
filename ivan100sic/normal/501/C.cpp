#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
int deg[100005], s[100005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	queue<int> q;
	for (int i=0; i<n; i++) {
		int x, y;
		cin >> x >> y;
		deg[i] = x;
		s[i] = y;
		if (deg[i] == 1)
			q.push(i);
	}

	vector<pair<int, int>> sol;

	while (q.size()) {
		int x = q.front(); q.pop();
		if (deg[x] == 0)
			continue;
		int y = s[x];
		sol.push_back({x, y});
		s[y] ^= x;
		if (--deg[y] == 1) {
			q.push(y);
		}
	}

	cout << sol.size() << '\n';
	for (auto e : sol)
		cout << e.first << ' ' << e.second << '\n';
}