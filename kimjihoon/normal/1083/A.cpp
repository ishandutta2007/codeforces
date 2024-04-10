#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
#define ll long long

ll a[300009], ans = 0;
vector<pair<int, ll> > v[300009];

ll ps(int n, int p)
{
	ll mx1 = 0, mx2 = 0;
	for (int i = 0; i < v[n].size(); i++) {
		int tn = v[n][i].first; ll tw = v[n][i].second;
		if (tn == p) continue;
		ll r = ps(tn, n) - tw;
		if (mx1 < r) {
			mx2 = mx1; mx1 = r;
		}
		else if (mx2 < r)
			mx2 = r;
	}
	ans = max(ans, mx1 + mx2 + a[n]);
	return mx1 + a[n];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n; cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 0; i < n - 1; i++) {
		int p, q; ll w; cin >> p >> q >> w;
		v[p].push_back(make_pair(q, w)); v[q].push_back(make_pair(p, w));
	}
	ps(1, -1);
	cout << ans << '\n';
	return 0;
}