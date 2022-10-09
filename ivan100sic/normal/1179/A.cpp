#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

pair<int, int> ans[300005];
int n, q;
deque<int> a;
pair<ll, int> b[300005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> q;
	int mx = 0;
	for (int i=0; i<n; i++) {
		int x;
		cin >> x;
		a.push_back(x);
		mx = max(mx, x);
	}

	for (int i=0; i<q; i++) {
		cin >> b[i].first;
		b[i].second = i;
	}
	sort(b, b+q);

	ll t = 1;

	for (int i=0; i<q; i++) {
		ll x = b[i].first;
		int y, z;

		while (t < x && a[0] != mx) {
			y = a[0];
			z = a[1];
			a.pop_front();
			a.pop_front();
			if (y < z)
				swap(y, z);
			a.push_front(y);
			a.push_back(z);
			t++;
		}

		if (t == x) {
			y = a[0];
			z = a[1];
		} else {
			y = a[0];
			z = a[1 + (x-t) % (n-1)];
		}

		ans[b[i].second] = {y, z};
	}

	for (int i=0; i<q; i++)
		cout << ans[i].first << ' ' << ans[i].second << '\n';
}