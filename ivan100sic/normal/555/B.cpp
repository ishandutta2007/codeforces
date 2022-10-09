#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, m;
ll l[200005], r[200005];
ll b[200005];

int ans[200005];

void no() {
	cout << "No\n";
	exit(0);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m;
	for (int i=0; i<n; i++)
		cin >> l[i] >> r[i];
	for (int i=0; i<m; i++)
		cin >> b[i];

	vector<tuple<ll, ll, int>> c;
	for (int i=0; i<n-1; i++) {
		ll u = l[i+1] - r[i];
		ll v = r[i+1] - l[i];
		c.emplace_back(u, v, i);
	}

	set<pair<ll, int>> d;
	for (int i=0; i<m; i++)
		d.insert({b[i], i});

	sort(c.begin(), c.end(), [](auto u, auto v) { return get<1>(u) < get<1>(v); });
	for (auto [u, v, id] : c) {
		auto it = d.lower_bound({u, -1});
		if (it == d.end())
			no();
		if (it->first > v)
			no();
		ans[id] = it->second;
		d.erase(it);
	}

	cout << "Yes\n";
	for (int i=0; i<n-1; i++)
		cout << ans[i]+1 << " \n"[i == n-2];
}