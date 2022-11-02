#include <iostream>
#include <algorithm>
using namespace std;

int ds[400009], a[400009];

int uf(int n)
{
	if (ds[n] == n) return n;
	return ds[n] = uf(ds[n]);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tc; cin >> tc;
	for (int ti = 0; ti < tc; ti++) {
		int n; cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
			ds[i] = i;
		}
		for (int i = 1; i <= n; i++) {
			int b; cin >> b;
			int ua = uf(a[i]), ub = uf(b);
			if (ua != ub)
				ds[ua] = ub;
		}
		long long ans = 1, md = 1000000007;
		for (int i = 1; i <= n; i++)
			if (ds[i] == i)
				ans = (ans * 2) % md;
		cout << ans << '\n';
	}
	return 0;
}