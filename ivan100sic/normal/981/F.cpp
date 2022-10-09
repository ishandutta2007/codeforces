#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, l;
int a[200005], b[200005];
int z[400005];

void mv(int& r, int v) {
	while (r < n && b[r] < v)
		r++;
}

void farbaj(vector<pair<int, int>> v, int j) {
	for (int i=1; i<3; i++) {
		v[i].first = max(v[i].first, v[i-1].second);
		v[i].second = max(v[i].first, v[i].second);
	}
	for (int i=0; i<3; i++)
		z[v[i].first + n - j]++, z[v[i].second + n - j]--;
}

bool moze(int w) {
	memset(z, 0, sizeof z);
	int la = 0, ra = 0;
	int lb = 0, rb = 0;
	int lc = 0, rc = 0;
	for (int i=0; i<n; i++) {
		mv(la, a[i] - w  - l);
		mv(ra, a[i] +w+1 - l);
		mv(lb, a[i] - w  );
		mv(rb, a[i] +w+1 );
		mv(lc, a[i] - w  + l);
		mv(rc, a[i] +w+1 + l);

		farbaj({{la, ra}, {lb, rb}, {lc, rc}}, i);
	}

	for (int i=0; i<2*n; i++)
		z[i+1] += z[i];

	for (int i=0; i<n; i++)
		if (z[i] + z[i+n] == n)
			return true;
	return false;
}

bool moze_spor(int w) {
	memset(z, 0, sizeof z);
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			int d = abs(b[j] - a[i]);
			d = min(d, l-d);
			if (d <= w) {
				z[(j-i+n)%n]++;
			}
		}
	}
	return  *max_element(z, z+n) == n;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> l;
	for (int i=0; i<n; i++)
		cin >> a[i];
	for (int i=0; i<n; i++)
		cin >> b[i];
	sort(a, a+n);
	sort(b, b+n);

	int lo = 0, hi = l-1, o = l;
	while (lo <= hi) {
		int mid = (lo+hi) / 2;
		if (moze(mid)) {
			o = mid;
			hi = mid - 1;
		} else {
			lo = mid + 1;
		}
	}

	cout << o << '\n';
}