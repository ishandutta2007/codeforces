#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
#define ll long long

struct edge
{
	int a, b; ll w;
	bool operator<(const edge &r) const {
		return w < r.w;
	}
};
 
pair<ll, int> a[200009];
ll ta[200009];
int ds[200009];
edge eg[200009];

int uf(int n)
{
	if (n == ds[n]) return n;
	return ds[n] = uf(ds[n]);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n, m; cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i].first; a[i].second = i;
		ta[i] = a[i].first;
		ds[i] = i;
	}
	sort(a + 1, a + n + 1);
	for (int i = 0; i < m; i++) 
		cin >> eg[i].a >> eg[i].b >> eg[i].w;
	sort(eg, eg + m);
	int ei = 0, si = a[1].second, ti = 1;
	ll ans = 0;
	for (int i = 1; i < n; i++) {
		int ui = uf(si);
		while (ui == uf(a[ti].second))
			ti++;
		ll t = a[1].first + a[ti].first;
		if (ei >= m || t <= eg[ei].w) {
			ans += t;
			ds[uf(a[ti].second)] = ui;
		}
		else {
			int ua = uf(eg[ei].a), ub = uf(eg[ei].b);
			if (ua == ub) {
				i--; ei++;
				continue;
			}
			ans += eg[ei].w;
			ds[ua] = ub;
			ei++;
		}
	}
	cout << ans << '\n';
	return 0;
}