#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <numeric>
#include <iterator>
#include <cstring>
#include <queue>
using namespace std;

int n, k, d;
vector<pair<int, int>> e[300005];
set<int> poc;

int dist[300005];

/*

int dfs(int x, int p, int gore) {
	int myr = 12313123;

	for (auto edz : e[x]) {
		int y = edz.first;
		int eid = edz.second;

		int ret;
		if (poc.count(y)) {
			ret = dfs(y, x, 0);
		} else {
			ret = dfs(y, x, gore+1);
		}

		// da li da brisem?



		myr = min(myr, ret+1);
	}

	if (poc.count(x)) {
		myr = 0;
	}

	return myr;
}

*/

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> k >> d;

	for (int i=0; i<k; i++) {
		int x;
		cin >> x;
		poc.insert(x);
	}

	set<int> ans;

	for (int i=1; i<n; i++) {
		int u, v;
		cin >> u >> v;
		e[u].push_back({v, i});
		e[v].push_back({u, i});
		ans.insert(i);
	}

	fill(dist+1, dist+n+1, 123123123);
	

	queue<int> q;
	for (int x : poc) {
		q.push(x);
		dist[x] = 0;
	}

	while (!q.empty()) {
		int x = q.front(); q.pop();

		for (auto edz : e[x]) {
			int y = edz.first;
			int eid = edz.second;
			if (dist[y] == 123123123) {
				dist[y] = dist[x] + 1;
				//cerr << x << ' ' << y << ' ' << eid << " ikr??\n";
				ans.erase(eid);
				q.push(y);
			}
		}
	}

	cout << ans.size() << '\n';
	for (int x : ans) {
		cout << x << ' ';
	}


}