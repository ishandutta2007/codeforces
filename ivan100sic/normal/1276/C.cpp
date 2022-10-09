#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int H = 400005;
int n, k;
int a[H], u[H], t[H], c[H];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=0; i<n; i++)
		cin >> a[i];
	copy(a, a+n, u);
	sort(u, u+n);
	k = unique(u, u+n) - u;
	for (int i=0; i<n; i++)
		a[i] = lower_bound(u, u+k, a[i]) - u;
	for (int i=0; i<n; i++)
		c[a[i]]++;
	for (int i=0; i<k; i++)
		t[c[i]]++;
	for (int i=n; i>=1; i--)
		t[i] += t[i+1];
	int p=0, q=0, z=0;
	for (int x=1; x<=n; x++) {
		z += t[x];
		int y = z / x;
		if (y < x)
			continue;
		if (x*y > p*q)
			p = x, q = y;
	}
	vector<pair<int, int>> v;
	vector<vector<int>> w(p, vector<int>(q));
	for (int i=0; i<k; i++)
		v.emplace_back(min(c[i], p), u[i]);
	sort(v.begin(), v.end(), greater<pair<int, int>>());
	int i=0, j=0;
	for (auto [f, x] : v) {
		while (f--) {
			w[i][(i+j)%q] = x;
			i++;
			if (i == p)
				i = 0, j++;
		}
	}
	cout << p*q << '\n' << p << ' ' << q << '\n';
	for (int i=0; i<p; i++)
		for (int j=0; j<q; j++)
			cout << w[i][j] << " \n"[j == q-1];
}