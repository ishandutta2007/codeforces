#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

unordered_map<int, int> p, v;

void compress(int x) {
	if (p.count(x)) {
		int y = p[x];
		compress(y);
		v[x] ^= v[y];
		if (p.count(y))
			p[x] = p[y];
		else
			p[x] = y;
	}
}

int endp(int x) {
	compress(x);
	if (p.count(x))
		return p[x];
	else
		return x;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int q, last = 0;
	cin >> q;
	while (q--) {
		int t, l, r, x;
		cin >> t;
		if (t == 1) {
			cin >> l >> r >> x;
			l ^= last;
			r ^= last;
			x ^= last;
			if (l > r)
				swap(l, r);
			r++;
			if (endp(l) == endp(r))
				continue;
			if (l != endp(l)) {
				x ^= v[l];
				l = p[l];
			}
			if (r != endp(r)) {
				x ^= v[r];
				r = p[r];
			}
			p[l] = r;
			v[l] = x;
		} else {
			cin >> l >> r;
			l ^= last;
			r ^= last;
			if (l > r)
				swap(l, r);
			r++;
			if (endp(l) != endp(r)) {
				cout << "-1\n";
				last = 1;
			} else {
				x = 0;
				if (l != endp(l)) {
					x ^= v[l];
				}
				if (r != endp(r)) {
					x ^= v[r];
				}
				cout << x << '\n';
				last = x;
			}
		}
	}
}