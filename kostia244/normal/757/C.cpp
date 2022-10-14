#include<bits/stdc++.h>
#define pb push_back
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
using vi = vector<ll>;
using pi = pair<ll, ll>;
const int D = 30, maxn = 1e6 + 3333, mod = 1e9 + 7;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll n, m, cur[maxn], r[maxn], rr = 1;
map<int, int> cnt;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >>m;
	for(int k, x, i = 0; i < n; i++) {
		cin >> k;
		set<int> t;
		for(int j=0;j<k;j++) {
			cin >> x;
			cur[x]++;
			t.insert(x);
		}
		vector<pair<pi, int>> v;
		for(auto i : t)
			v.pb({{cur[i], r[i]}, i}), cur[i] = 0;
		sort(all(v));
		if(v.size()) {
			r[v[0].second] = ++rr;
		}
		for(int i = 1; i < v.size(); i++) {
			if(v[i].first!=v[i-1].first) ++rr;
			r[v[i].second] = rr;
		}
	}
	for(int i = 1; i <= m; i++)
		cnt[r[i]]++;
	ll ans = 1;
	for(auto i : cnt) {
		for(int j = 1; j <= i.second; j++)
			ans = (ans*j)%mod;
	}
	cout << ans;
}