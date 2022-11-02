#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int a[500009], d[500009], l[500009], pl[500009], c[500009];
bool vs[500009], r[500009];
vector<int> v[500009];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n; cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		c[a[i]]++;
		if (!l[a[i]]) l[a[i]] = i;
		if (i == 1 || a[i] != a[i - 1]) pl[i] = i;
		else pl[i] = pl[i - 1];
	}
	for (int i = n; i >= 1; i--) {
		if (!vs[a[i]]) {
			vs[a[i]] = true;
			r[i] = true;
		}
		v[a[i]].push_back(i);
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		d[i] = d[i - 1];
		if (!r[i]) continue;
		d[i] = max(d[i], d[l[a[i]] - 1] + c[a[i]]);
		ans = max(ans, d[i]);
		for (int j = 0; j < v[a[i]].size(); j++) {
			int t = v[a[i]][j];
			ans = max(ans, d[t - 1] + j + 1);
		}
	}
	cout << n - ans << '\n';
	return 0;
}