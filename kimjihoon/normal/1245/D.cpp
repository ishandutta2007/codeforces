#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <utility>
using namespace std;

struct eg
{
	int a, b; long long c;
	bool operator<(const eg &r) const {
		return c < r.c;
	}
};

int x[2009], y[2009], k[2009], ds[2009];
vector<eg> v;
vector<int> pv;
vector<pair<int, int> > ev;

int uf(int n)
{
	if (ds[n] == n) return n;
	return ds[n] = uf(ds[n]);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n; cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> x[i] >> y[i];
		ds[i] = i;
	}
	for (int i = 1; i <= n; i++) {
		eg t; t.a = 0; t.b = i; cin >> t.c;
		v.push_back(t);
	}
	for (int i = 1; i <= n; i++)
		cin >> k[i];
	for (int i = 1; i <= n; i++)
		for (int j = i + 1; j <= n; j++) {
			eg t; t.a = i; t.b = j; t.c = 1LL * (abs(x[i] - x[j]) + abs(y[i] - y[j])) * (k[i] + k[j]);
			v.push_back(t);
		}
	sort(v.begin(), v.end());
	long long ans = 0;
	for (int i = 0; i < v.size(); i++) {
		int ua = uf(v[i].a), ub = uf(v[i].b);
		if (ua == ub) continue;
		ds[ub] = ua; ans += v[i].c;
		if (v[i].a == 0) pv.push_back(v[i].b);
		else ev.push_back(make_pair(v[i].a, v[i].b));
	}
	cout << ans << '\n';
	cout << pv.size() << '\n';
	for (int i = 0; i < pv.size(); i++)
		cout << pv[i] << " ";
	cout << '\n';
	cout << ev.size() << '\n';
	for (int i = 0; i < ev.size(); i++)
		cout << ev[i].first << " " << ev[i].second << '\n';
	return 0;
}