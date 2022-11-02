#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;

int ds[100009], a[100009], b[100009], r[100009];
vector<pair<int, pair<int, int> > > p;

int uf(int n)
{	
	if (ds[n] == n) return n;
	return ds[n] = uf(ds[n]);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n, m; cin >> m >> n;
	for (int i = 1; i <= m; i++) 
		cin >> a[i];
	for (int i = 1; i <= n; i++) {
		cin >> b[i];
		ds[i] = i;
	}
	long long ans = 0;
	for (int i = 1; i <= m; i++) {
		int k; cin >> k;
		for (int j = 0; j < k; j++) {
			int x; cin >> x;
			p.push_back(make_pair(a[i] + b[x], make_pair(i, x)));
			ans += a[i] + b[x];
		}
	}
	sort(p.begin(), p.end()); reverse(p.begin(), p.end());
	for (int i = 0; i < p.size(); i++) {
		int gi = p[i].second.first, x = p[i].second.second;
		if (!r[gi]) {
			r[gi] = x;
			ans -= p[i].first;
		}
		else {
			int ua = uf(x), ub = uf(r[gi]);
			if (ua != ub) {
				ds[ua] = ub;
				ans -= p[i].first;
			}
		}
	}
	cout << ans << '\n';
	return 0;
}