#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>

using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie (NULL);
    cout.precision(10);
    cout << fixed;

	int n, m, k;
	cin >> n >> m >> k;
	vector<vector<pair<int, int>>> adj(n);
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		a--;
		b--;
		adj[a].push_back({ b, c });
		adj[b].push_back({ a, c });
	}

	vector<int> storage(k);
	for (int i = 0; i < k; i++) {
		cin >> storage[i];
		storage[i]--;
	}
	set<int> s(storage.begin(), storage.end());


	int best = -1;

	for (auto cur : storage) {
		for (auto p : adj[cur]) {
			auto a = p.first;
			auto c = p.second;
			if (s.count(a) == 0) {
				if (best == -1 || best > c)
					best = c;
			}
		}
	}

	cout << best << endl;

}