#include <iostream>
#include <vector>
using namespace std;

int a[300009], r[300009], c[300009], ds[300009];
vector<int> ans;

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
		int n, m; cin >> n >> m;
		for (int i = 0; i < n; i++) {
			cin >> a[i]; a[i]--;
			r[a[i]] = i;
			c[i] = 0;
		}
		for (int i = 0; i < n; i++)
			c[(r[i] + n - i) % n]++;
		ans.clear();
		for (int i = 0; i < n; i++) {
			if (c[i] < n / 3) continue;
			for (int j = 0; j < n; j++)
				ds[j] = j;
			for (int j = 0; j < n; j++) {
				int ua = uf(j), ub = uf(a[(j + i) % n]);
				if (ua != ub)
					ds[ua] = ub;
			}
			int pc = n;
			for (int j = 0; j < n; j++)
				if (j == ds[j])
					pc--;
			if (pc <= m) ans.push_back(i);
		}
		cout << ans.size() << " ";
		for (int i = 0; i < ans.size(); i++)
			cout << ans[i] << " ";
		cout << '\n';
	}
	return 0;
}