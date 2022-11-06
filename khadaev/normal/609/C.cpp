#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;


int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) cin >> a[i];
	sort(a.begin(), a.end());
	ll s = 0;
	for (int i = 0; i < n; ++i) s += a[i];
	vector<int> b(n, s / n);
	ll s_new = (ll)n * (s / n);
	for (int i = n - 1; s > s_new; --i) {
		++b[i];
		--s;
	}
	ll ans = 0;
	for (int i = 0; i < n; ++i) ans += abs(a[i] - b[i]);
	cout << ans / 2 << '\n';
}