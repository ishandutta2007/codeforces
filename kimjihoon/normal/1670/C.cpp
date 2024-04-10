#include <iostream>
#include <algorithm>
using namespace std;

const long long md = 1000000007;

int a[100009], b[100009], ds[100009];
bool f[100009], rf[100009];

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
			f[i] = rf[i] = false;
		}
		for (int i = 1; i <= n; i++) cin >> b[i];
		for (int i = 1; i <= n; i++) {
			int t; cin >> t;
			if (a[i] == b[i]) f[a[i]] = true;
			else if (t) f[t] = true;
			else {
				int ua = uf(a[i]), ub = uf(b[i]);
				if (ua != ub) ds[ua] = ub;
			}
		}
		long long ans = 1;
		for (int i = 1; i <= n; i++)
			if (f[i])
				rf[uf(i)] = true;
		for (int i = 1; i <= n; i++)
			if (ds[i] == i && !rf[i])
				ans = (ans * 2) % md;
		cout << ans << '\n';
	}
	return 0;
}