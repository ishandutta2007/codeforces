#include <bits/stdc++.h>
typedef long long ll;

using namespace std;
const ll MOD = 1000000007;

ll o = 0, e = 0, ans = 0;
vector<ll> v;
vector<vector<int>> adj;

pair<ll, ll> calc(int x, int p, int c) {
	// cout << x << ' ' << p << ' ' << c << '\n';
	vector<ll> os, es;
	for(int i = 0; i < adj[x].size(); i++) {
		if(adj[x][i] == p) continue;
		auto pa = calc(adj[x][i], x, c+1);
		os.push_back(pa.first);
		es.push_back(pa.second);
	}
	pair<ll, ll> pa;
	pa.first = pa.second = 0;
	es.push_back(1);
	for(int i = 0; i < os.size(); i++) pa.second += os[i];
	for(int i = 0; i < es.size(); i++) pa.first += es[i];
	if(c%2) {
		es.push_back(o - pa.first);
		os.push_back(e - pa.second);
	}
	else {
		es.push_back(e - pa.first);
		os.push_back(o - pa.second);
	}
	ll s1 = o*o, s2 = e*e;
	if(c%2) swap(s1, s2);
	for(int i = 0; i < os.size(); i++) {
		s1 -= os[i]*os[i];
		s1 %= MOD;
		s1 += MOD;
		s1 %= MOD;
	}
	for(int i = 0; i < es.size(); i++) {
		s2 -= es[i]*es[i];
		s2 %= MOD;
		s2 += MOD;
		s2 %= MOD;
	}
	s2 -= s1;
	s2 += MOD;
	s2 %= MOD;
	s2 *= v[x];
	s2 %= MOD;
	s2 += MOD;
	s2 %= MOD;
	ans += s2;
	ans %= MOD;
	return pa;
}

void dfs(int x, int p, int c) {
	if(c%2) o++;
	else e++;
	for(int i = 0; i < adj[x].size(); i++) {
		if(adj[x][i] == p) continue;
		dfs(adj[x][i], x, c+1);
	}
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	adj.resize(n);
	v.resize(n);
	for(int i = 0; i < n; i++) cin >> v[i];
	for(int i = 1; i < n; i++) {
		int x, y;
		cin >> x >> y;
		x--; y--;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	dfs(0, -1, 0);
	calc(0, -1, 0);
	for(int i = 0; i < n; i++) {
		ans += v[i];
		if(ans < 0 || ans >= MOD) {
			ans += MOD;
			ans %= MOD;
		}
	}
	cout << ans << '\n';
	return 0;
}