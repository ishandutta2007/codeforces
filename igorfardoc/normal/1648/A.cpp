#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<long long> vl;
int n, m;

ll calc(vi& a) {
	ll sumnow = 0;
	ll ans = 0;
	for(int i = 0; i < a.size(); i++) {
		ans += (ll)i * a[i] - sumnow;
		sumnow += a[i];
	}
	return ans;
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	#ifdef _FILE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
	cin >> n >> m;
	set<int> all;
	vvi a(n, vi(m));
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			cin >> a[i][j];
			all.insert(a[i][j]);
		}
	}
	map<int, int> d;
	int now = 0;
	vvi x(n * m), y(n * m);
	for(const auto& el : all) {
		d[el] = now++;
	}
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			x[d[a[i][j]]].push_back(i);
			y[d[a[i][j]]].push_back(j);
		}
	}
	ll res = 0;
	for(int i = 0; i < n * m; i++) {
		sort(x[i].begin(), x[i].end());
		sort(y[i].begin(), y[i].end());
		res += calc(x[i]) + calc(y[i]);
	}
	cout << res;
}