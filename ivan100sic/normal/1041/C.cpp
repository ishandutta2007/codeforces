#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, m, d;
int a[200005], sol;
int b[200005];

set<pair<int, int>> s;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m >> d;
	for (int i=1; i<=n; i++) {
		cin >> a[i];
		s.insert({a[i], i});
	}

	while (s.size()) {
		auto p = *s.begin();
		s.erase(p);
		b[p.second] = ++sol;
		while (1) {
			auto it = s.lower_bound({p.first + d + 1, 0});
			if (it == s.end())
				break;
			p = *it;
			s.erase(p);
			b[p.second] = sol;
		}
	}

	cout << sol << '\n';
	for (int i=1; i<=n; i++)
		cout << b[i] << ' ';
}