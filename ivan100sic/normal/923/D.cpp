#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

string s, t;
int q;
int zs[100005], zt[100005];
int as[100005], at[100005];

void pr(string s, int* z, int* a) {
	int n = s.size();
	for (int i=0; i<n; i++) {
		z[i+1] = z[i] + (s[i] >= 'B');
		a[i+1] = (a[i] + 1) * (s[i] == 'A');
	}
}

int ea(int l, int r, int* a) {
	return min(a[r], r-l);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> s >> t;
	pr(s, zs, as);
	pr(t, zt, at);
	cin >> q;
	while (q--) {
		int l, r, u, v, k = 0;
		cin >> l >> r >> u >> v;
		l--, u--;
		char x = s[r-1], y = t[v-1];
		int d = (zt[v] - zt[u]) - (zs[r] - zs[l]);
		if (d < 0 || d % 2) {
			cout << '0';
			continue;
		}
		if (x >= 'B' && y >= 'B')
			k = 1;
		else if (x >= 'B' && y == 'A')
			k = 0;
		else if (x == 'A' && y >= 'B') {
			if (d)
				k = 1;
			else
				k = as[r] % 3 == 0;
		} else {
			int e = ea(l, r, as) - ea(u, v, at);
			if (d) {
				if (r-l == ea(l, r, as)) // samoa
					k = e > 0;
				else
					k = e >= 0;
			} else {
				k = e % 3 == 0 && e >= 0;
			}
		}
		cout << k;
	}
	cout << '\n';
}