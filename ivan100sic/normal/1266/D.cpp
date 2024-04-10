#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

ll w[100005];

struct T {
	int x, y;
	ll z;
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int n, m;
	cin >> n >> m;
	while (m--) {
		int a, b, c;
		cin >> a >> b >> c;
		w[a] += c;
		w[b] -= c;
	}
	basic_string<int> c, d;
	basic_string<T> f;
	for (int i=0; i<100005; i++)
		if (w[i] > 0)
			c += i;
		else if (w[i] < 0)
			d += i;
	size_t i = 0, j = 0;
	while (i < c.size()) {
		ll z = min(w[c[i]], -w[d[j]]);
		f += {c[i], d[j], z};
		if ((w[c[i]] -= z) == 0)
			i++;
		if ((w[d[j]] += z) == 0)
			j++;
	}
	cout << f.size() << '\n';
	for (auto [x, y, z] : f)
		cout << x << ' ' << y << ' ' << z << '\n';
}