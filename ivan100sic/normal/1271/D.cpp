#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, m, k;
int a[5005], b[5005], c[5005];
basic_string<int> e[5005];
int t[5005], l[5005], q[5005], r[5005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m >> k;
	for (int i=1; i<=n; i++)
		cin >> a[i] >> b[i] >> c[i];

	for (int i=0; i<m; i++) {
		int x, y;
		cin >> x >> y;
		e[x] += y;
	}

	for (int i=1; i<=n; i++)
		e[i] += i;

	t[0] = k;
	for (int i=1; i<=n; i++) {
		if (t[i-1] < a[i])
			return cout << "-1\n", 0;
		t[i] = t[i-1] + b[i];
		l[i] = t[i] - a[i+1];
	}

	q[n] = l[n];
	for (int i=n-1; i; i--)
		q[i] = min(l[i], q[i+1]);
	for (int i=1; i<=n; i++)
		r[i] = q[i] - q[i-1];

	set<pair<int, int>> s;
	set<int> ubaceni;
	ll sol = 0;
	
	for (int i=n; i>=1; i--) {
		for (int x : e[i]) {
			if (!ubaceni.count(x)) {
				ubaceni.insert(x);
				s.insert({c[x], x});
			}
		}
		while (r[i]--) {
			if (s.size()) {
				auto p = *s.rbegin();
				s.erase(p);
				sol += p.first;
			}
		}
	}

	cout << sol << '\n';
}