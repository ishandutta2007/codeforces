#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

// #define LOCAL

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		vector<ll> c(n);
		vector<pair<vector<int>, int>> nbs(n);
		for (int i=0; i<n; i++)
			cin >> c[i], nbs[i].second = i;
		for (int i=0; i<m; i++) {
			int x, y;
			cin >> x >> y;
			x--, y--;
			nbs[y].first.push_back(x);
		}
		for (int i=0; i<n; i++)
			sort(nbs[i].first.begin(), nbs[i].first.end());
		sort(nbs.begin(), nbs.end());
		ll q = 0;
		vector<int> staro;
		for (int i=0; i<n; i++) {
			if (i == 0 || nbs[i].first != nbs[i-1].first) {
				ll w = 0;
				for (int x : staro)
					w += c[x];
				#ifdef LOCAL
				for (int x : staro)
					cerr << x << ' ';
				cerr << '\n';
				#endif
				staro = {};
				if (i == 0 || nbs[i-1].first.size() == 0) {

				} else {
					q = gcd(q, w);
				}
			}
			staro.push_back(nbs[i].second);
		}

		{
			ll w = 0;
			for (int x : staro)
				w += c[x];
			#ifdef LOCAL
			for (int x : staro)
				cerr << x << ' ';
			cerr << '\n';
			#endif
			staro = {};
			q = gcd(q, w);
		}

		cout << q << '\n';
	}
}