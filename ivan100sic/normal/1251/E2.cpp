#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<vector<int>> e(n);
		for (int i=0; i<n; i++) {
			int p, m;
			cin >> m >> p;
			e[m].push_back(p);
		}
		ll sol = 0;
		multiset<ll> ms;
		vector<int> z(n);
		for (int i=0; i<n-1; i++)
			z[i+1] = z[i] + e[i].size();
		int j = 0;
		for (int i=n-1; i>=0; i--) {
			for (int x : e[i])
				ms.insert(x);
			while (j<i-z[i]) {
				sol += *ms.begin();
				ms.erase(ms.begin());
				j++;
			}
		}
		cout << sol << '\n';
	}
}