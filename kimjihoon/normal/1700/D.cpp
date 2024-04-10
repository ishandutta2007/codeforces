#include <iostream>
#include <algorithm>
using namespace std;

long long a[200009];
pair<long long, int> d[200009];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n; cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		a[i] += a[i - 1];
		d[i].first = max(d[i - 1].first, (a[i] + 1LL * (i - 1)) / i);
	}
	for (int i = 1; i <= n; i++) {
		d[i].first = max(d[i].first, (a[n] + 1LL * (i - 1)) / i);
		d[i].first *= -1;
		d[i].second = i;
	}
	int q; cin >> q;
	for (int i = 0; i < q; i++) {
		long long t; cin >> t;
		if (-d[n].first > t) cout << -1 << '\n';
		else cout << (lower_bound(d + 1, d + n + 1, make_pair(-t, -1)))->second << '\n';
	}
	return 0;
}