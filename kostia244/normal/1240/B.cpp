#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb push_back
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
using ld = long double;
using vi = vector<ll>;
using vvi = vector<vi>;
const ll mod = 998244353;
const int maxn = 2e5 + 33;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

struct solver {
	ll n;
	vector<pair<int, int>> a;
	void read() {
		cin >> n;
		a.resize(n+1, {500100, -1});
		for(int t, i = 0; i < n; i++) {
			cin >> t;
			a[t].first = min(a[t].first, i);
			a[t].second = i;
		}
	}
	ll solve() {
		int ans = 0, r = 0, q = 0, p = -1;
		for(int i = 1; i <= n; i++) {
			if(a[i].second==-1)continue;
			q++;
			if(a[i].first < p)
				ans=1;
			else
				ans++;
			r = max(r, ans);
			p = a[i].second;
		}
		return q-r;
	}
};
void solve() {
	solver x;
	x.read();
	cout << x.solve() << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	int q;
	cin >> q;
	while (q--)
		solve();
}