#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, m;
int a[100005], c[100005];
ll zbir_ostalo;

struct stvar {
	int a, c, id;
	bool operator< (const stvar& b) const {
		if (c != b.c)
			return c < b.c;
		return id < b.id;
	}
};

set<stvar> ostalo;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m;
	for (int i=1; i<=n; i++)
		cin >> a[i];
	for (int i=1; i<=n; i++)
		cin >> c[i];

	for (int i=1; i<=n; i++) {
		ostalo.insert({a[i], c[i], i});
		zbir_ostalo += a[i];
	}

	while (m--) {
		int t, d, preselo_ti_dabogda = 0;
		cin >> t >> d;
		preselo_ti_dabogda = d <= zbir_ostalo;

		// jedi to sto si porucio
		ll amt = min(a[t], d);
		ll pare = amt * c[t];
		ostalo.erase({a[t], c[t], t});
		a[t] -= amt;
		zbir_ostalo -= amt;
		if (a[t] > 0)
			ostalo.insert({a[t], c[t], t});
		d -= amt;

		while (d > 0 && ostalo.size()) {
			t = ostalo.begin()->id;
			amt = min(a[t], d);
			ostalo.erase({a[t], c[t], t});
			a[t] -= amt;
			zbir_ostalo -= amt;
			pare += amt * c[t];
			if (a[t] > 0)
				ostalo.insert({a[t], c[t], t});
			d -= amt;
		}

		cout << pare * preselo_ti_dabogda << '\n';
	}
}