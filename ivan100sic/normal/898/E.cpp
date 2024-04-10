#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
int a[200005], b[200005], c[200005];

int ir(int x) {
	int l = 0, r = 33333, o = 0;
	while (l <= r) {
		int m = (l+r) >> 1;
		if (m*m <= x) {
			o = m;
			l = m + 1;
		} else {
			r = m - 1;
		}
	}
	return o;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> a[i];
		int r = ir(a[i]);
		if (a[i] == 0)
			b[i] = 2;
		else if (a[i] == r*r) {
			b[i] = 1;
		} else {
			b[i] = 0;
		}
		c[i] = min(a[i]-r*r, (r+1)*(r+1) - a[i]);
	}

	vector<pair<int, int>> d(n);
	for (int i=0; i<n; i++)
		d[i] = {c[i] - b[i], i};
	sort(d.begin(), d.end());
	ll z = 0;
	for (int i=0; i<n; i++)
		z += (i < n/2 ? c : b)[d[i].second];
	cout << z << '\n';
}