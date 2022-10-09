// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

struct seg {
	int v, t;
};

int n, s;
vector<seg> a[105];

int sgn(int x) {
	return x < 0 ? -1 : (x == 0 ? 0 : 1);
}

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	cin >> n >> s;

	for (int i=0; i<n; i++) {
		int k;
		cin >> k;
		a[i].resize(k);
		for (auto& [v, t] : a[i]) cin >> v >> t;
	}

	int sol = 0;

	for (int i=0; i<n; i++) {
		for (int j=i+1; j<n; j++) {
			auto& u = a[i];
			auto& v = a[j];

			int p = 0, q = 0, f = 0, g = 0, last = 0, s1 = 0, s2 = 0;

			auto go = [&](int d) {
				s1 += d * u[p].v;
				s2 += d * v[q].v;
				if (sgn(s1 - s2) * sgn(last) == -1) {
					sol++;
				}
				if (s1 - s2) last = s1 - s2;
			};

			while (p < (int)u.size() && q < (int)v.size()) {
				int d = min(u[p].t - f, v[q].t - g);
				go(d);
				f += d;
				g += d;
				if (f == u[p].t) p++, f=0;
				if (g == v[q].t) q++, g=0;
			}
		}
	}

	cout << sol << '\n';
}