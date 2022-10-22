#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
const int mn = 1e5 + 10;
pll p[mn];
vector<pll> cvx;
bool bad(pll a, pll b, pll c) {
	return a.first*b.second + b.first*c.second + c.first*a.second - a.second*b.first - b.second*c.first - c.second*a.first >= 0;
}
int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);
	int n,i;
	cin >> n;
	for (i = 0; i < n; i++) {
		cin >> p[i].first >> p[i].second;
		p[i].second -= p[i].first * p[i].first;
	}
	sort(p, p + n);
	for (i = 0; i < n; i++) {
		while (cvx.size() >= 2 && bad(cvx[cvx.size() - 2], cvx[cvx.size() - 1], p[i]))cvx.pop_back();
		cvx.push_back(p[i]);
	}
	int ans = 0;
	for (i = 0; i < cvx.size()-1; i++) {
		if (cvx[i].first != cvx[i + 1].first)ans++;
	}
	printf("%d", ans);
	getchar(); getchar();
}