#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

struct covek {
	ll l, r;
	bool operator< (const covek& b) const {
		return l < b.l;
	}
} a[200005];

ll al[200005], ar[200005];
ll s, n;

bool moze(ll m) {
	ll u = 0;
	int preko = 0, ispod = 0;
	vector<int> v;
	for (int i=0; i<n; i++) {
		if (a[i].l > m) {
			u += a[i].l;
			preko++;
		} else if (a[i].r < m) {
			u += a[i].l;
			ispod++;
		} else {
			v.push_back(a[i].l);
		}
	}
	nth_element(v.begin(), v.begin()+n/2-ispod, v.end());
	for (int i=0; i<n-preko-ispod; i++) {
		if (i < n/2 - ispod)
			u += v[i];
		else
			u += m;
	}
	return u <= s;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int t;
	cin >> t;
	while (t--) {
		cin >> n >> s;
		for (int i=0; i<n; i++) {
			cin >> a[i].l >> a[i].r;
			al[i] = a[i].l;
			ar[i] = a[i].r;
		}
		sort(al, al+n);
		sort(ar, ar+n);
		sort(a, a+n);

		ll lo = al[n/2], hi = ar[n/2], o = -1;

		while (lo <= hi) {
			ll mid = (lo + hi) / 2;
			if (moze(mid)) {
				o = mid;
				lo = mid + 1;
			} else {
				hi = mid - 1;
			}
		}
		cout << o << '\n';
	}
}