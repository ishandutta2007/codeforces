#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
basic_string<int> a, b, c, d;
basic_string<int> za, zb, zc, zd;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	while (n--) {
		int x, y;
		cin >> x >> y;
		if (x == 11)
			d += y;
		else if (x == 1)
			c += y;
		else if (x == 10)
			b += y;
		else
			a += y;
	}

	sort(a.begin(), a.end(), greater<int>());
	sort(b.begin(), b.end(), greater<int>());
	sort(c.begin(), c.end(), greater<int>());
	sort(d.begin(), d.end(), greater<int>());

	basic_string<int> N = {0};

	za = N + a; zb = N + b; zc = N + c; zd = N + d;

	partial_sum(a.begin(), a.end(), za.begin() + 1);
	partial_sum(b.begin(), b.end(), zb.begin() + 1);
	partial_sum(c.begin(), c.end(), zc.begin() + 1);
	partial_sum(d.begin(), d.end(), zd.begin() + 1);

	int sol = 0;
	for (int i=0; i<=(int)a.size(); i++) {
		int gap = (int)d.size() - i;
		if (gap < 0)
			continue;
		int sum = zd.back() + za[i];

		if ((int)b.size() - (int)c.size() > gap) {
			sum += zc.back() + zb[c.size() + gap];
		} else if ((int)c.size() - (int)b.size() > gap) {
			sum += zb.back() + zc[b.size() + gap];
		} else {
			sum += zc.back() + zb.back();
		}
		sol = max(sol, sum);
	}
	cout << sol << '\n';
}