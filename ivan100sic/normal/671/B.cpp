#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, k;
int a[500005], lim;
ll z;

int resip(basic_string<int> a) {
	int l = lim+1;
	int r = *max_element(a.begin(), a.end());
	int o = -1;
	while (l <= r) {
		int m = (l+r) >> 1;
		ll z = 0;
		for (int x : a)
			if (x > m)
				z += x-m;
		if (z <= k) {
			o = m;
			r = m - 1;
		} else {
			l = m + 1;
		}
	}
	cerr << "plus " << o << '\n';
	return o;
}

int resim(basic_string<int> a) {
	int l = *min_element(a.begin(), a.end());
	int r = lim;
	int o = -1;
	while (l <= r) {
		int m = (l+r) >> 1;
		ll z = 0;
		for (int x : a)
			if (x < m)
				z += m-x;
		if (z <= k) {
			o = m;
			l = m + 1;
		} else {
			r = m - 1;
		}
	}
	cerr << "minus " << o << '\n';
	return o;
}

bool moze0() {
	if (z != n * 1ll * lim)
		return false;
	ll q = 0;
	for (int i=0; i<n; i++)
		if (a[i] > lim)
			q += a[i] - lim;
	return q <= k;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> k;
	for (int i=0; i<n; i++)
		cin >> a[i];
	sort(a, a+n); // yaay branch prediction

	z = accumulate(a, a+n, 0ll);
	lim = z / n;
	
	basic_string<int> veci, manji;
	for (int i=0; i<n; i++) {
		if (a[i] > lim) {
			veci += a[i];
		} else {
			manji += a[i];
		}
	}

	if (moze0()) {
		// svi su vec jednaki
		cout << "0\n";
		return 0;
	}

	cout << resip(veci) - resim(manji) << '\n';
}