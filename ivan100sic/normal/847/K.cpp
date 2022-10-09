#include <bits/stdc++.h>
using namespace std;

int n, a, b, k, f;
string u[305], v[305];
map<pair<string, string>, int> total_cost;
vector<int> c;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> a >> b >> k >> f;
	for (int i=1; i<=n; i++) {
		cin >> u[i] >> v[i];

		string p = u[i];
		string q = v[i];
		if (p > q) {
			swap(p, q);
		}

		if (u[i] == v[i-1]) {
			total_cost[{p, q}] += b;
		} else {
			total_cost[{p, q}] += a;
		}
	}

	for (auto p : total_cost) {
		c.push_back(p.second);
	}

	sort(c.begin(), c.end());
	reverse(c.begin(), c.end());

	/*
	for (int x : c) {
		cerr << x << ' ';
	}
	cerr << '\n';
	*/
	
	int tot = accumulate(c.begin(), c.end(), 0);
	int sol = tot;

	for (int kupi = 0; kupi <= k && kupi <= (int)c.size(); kupi++) {
		int tmp = accumulate(c.begin() + kupi, c.end(), 0) + kupi * f;
		sol = min(tmp, sol);
	}

	cout << sol;
}