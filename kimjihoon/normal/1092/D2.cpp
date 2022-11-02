#include <iostream>
#include <algorithm>
#include <utility>
using namespace std;

int ds[200009], s[200009], ps[200009];
pair<int, int> a[200009];

int uf(int n)
{
	if (n == ds[n]) return n;
	return ds[n] = uf(ds[n]);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n; cin >> n;
	int mx = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i].first; ps[i] = a[i].first; mx = max(mx, a[i].first);
		a[i].second = i;
		ds[i] = i; s[i] = 1;
	}
	sort(a, a + n);
	int r = 0;
	for (int i = 0; i < n; i++) {
		if (a[i].first == mx) break;
		int pi = a[i].second, p = uf(pi);
		if (pi > 0) {
			int rp = uf(pi - 1);
			if (rp != p && ps[pi - 1] <= ps[pi]) {
				ds[rp] = p; s[p] += s[rp];
			}
		}
		if (pi < n - 1) {
			int rp = uf(pi + 1);
			if (rp != p && ps[pi + 1] <= ps[pi]) {
				ds[rp] = p; s[p] += s[rp];
			}
		}
		if (i == n - 1 || a[i].first != a[i + 1].first) {
			for (int j = r; j <= i; j++)
				if (s[uf(a[j].second)] % 2 == 1) {
					cout << "NO" << '\n';
					return 0;
				}
			r = i + 1;
		}
	}
	cout << "YES" << '\n';
	return 0;
}