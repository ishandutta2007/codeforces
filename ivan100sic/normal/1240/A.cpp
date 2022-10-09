#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
ll p[200005], x, a, y, b;
ll q[200005], k;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int qq;
	cin >> qq;
	while (qq--) {
		cin >> n;
		for (int i=0; i<n; i++)
			cin >> p[i];
		cin >> x >> a >> y >> b >> k;

		int l = 0, r = n, o = -1;
		while (l <= r) {
			int m = (l+r) >> 1;
			for (int i=0; i<m; i++) {
				q[i] = 0;
				if (i % a == a-1)
					q[i] += x;
				if (i % b == b-1)
					q[i] += y;
			}
			fill(q+m, q+n, 0);
			sort(p, p+n);
			sort(q, q+n);
			ll ip = inner_product(p, p+n, q, 0ll)/100;
			if (ip >= k) {
				o = m;
				r = m - 1;
			} else {
				l = m + 1;
			}
		}
		cout << o << "\n";
	}
}