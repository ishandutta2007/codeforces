#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

int n, m;
queue<pair<ll,ll>> Q;
set<ll> used;
vector<ll> poz;

int main () {
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		ll x;
		cin >> x;

		used.insert(x);

		poz.push_back(x);
	}

	for (ll x : poz) {
		if (used.count(x-1) == 0) Q.push({x-1, 1});
		if (used.count(x+1) == 0) Q.push({x+1, 1});
	}

	vector<ll> result;
	ll sum = 0;
	while (m > 0) {
		auto el = Q.front();
		Q.pop();

		if (used.count(el.first+1) == 0) Q.push({el.first+1, el.second+1});
		if (used.count(el.first-1) == 0) Q.push({el.first-1, el.second+1});

		if (used.count(el.first) == 0) {
			sum += el.second;
			used.insert(el.first);
			result.push_back(el.first);
			m--;
		}
	}

	cout << sum << "\n";
	for (ll x : result)
		cout << x << " ";

	return 0;
}