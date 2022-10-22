#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

ll BIG = 1999999999999999999;
ll ans[3001], pre[3001];
vector<pair<ll, ll>> v;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	v.resize(n);
	for(int i = 0; i < n; i++) {
		cin >> v[i].first >> v[i].second;
		ans[i] = BIG;
	}
	sort(v.begin(), v.end());
	pre[0] = v[0].first;
	for(int i = 1; i < n; i++) {
		pre[i] = pre[i-1] + v[i].first;
	}
	ans[0] = v[0].second;
	for(int i = 1; i < n; i++) {
		for(int j = 0; j <= i; j++) {
			ans[i] = min(ans[i], (j == 0 ? 0 : ans[j-1]) + ((pre[i] - pre[j]) - ((i-j) * v[j].first)) + v[j].second);
		}
	}
	cout << ans[n-1] << '\n';
}