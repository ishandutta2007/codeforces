//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx2,tune=native")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC optimize("trapv")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
using namespace std;
using ll = long long;
using ld = long double;
using vi = vector<ll>;
using vvi = vector<vi>;
using pi = pair<ll, ll>;
const ll mod = 1e9 + 7;
void solve() {
	ll n, m;
	vector<pair<int, int>> a;
	cin >> n >> m;
	a.resize(n);
	int t = 0;
	for (auto &i : a)
		cin >> i.first, i.second = ++t;
	if (n == 2 || m < n) {
		cout << "-1\n";
		return;
	}
	ll ans = 0;
	sort(all(a));
	for(int i = 0; i < n; i++) {
		ans += 2*a[i].first;
	}
	ans += (a[0].first+a[1].first)*(m-n);
	cout << ans << "\n";
	for(int i = 1; i < n; i++) {
		cout << a[i].second << " " << a[i-1].second << "\n";
	}
	cout << a[0].second << " " << a.back().second << "\n";
	for(int i = n; i < m; i++)
		cout << a[0].second << " " << a[1].second << "\n";
}
int main() { //DINIC ORZ
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ll t;
	cin >> t;
	while (t--)
		solve();
}