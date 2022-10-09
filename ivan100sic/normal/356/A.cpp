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

	int n, m;
	cin >> n >> m;
	set<int> zivi;
	vector<int> sol(n+1, 0);

	for (int i=1; i<=n; i++)
		zivi.insert(i);

	while (m--) {
		int l, r, x;
		cin >> l >> r >> x;
		while (1) {
			auto it = zivi.lower_bound(l);
			if (it == zivi.end() || *it > r)
				break;
			sol[*it] = x;
			zivi.erase(it);
		}
		zivi.insert(x);
	}

	for (int i=1; i<=n; i++)
		cout << (i == sol[i] ? 0 : sol[i]) << ' ';
	cout << '\n';
}