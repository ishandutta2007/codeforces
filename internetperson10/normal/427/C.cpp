#include <bits/stdc++.h>
typedef long long ll;

using namespace std;
const ll MOD = 1000000007;
vector<vector<int>> adj1, adj2;
vector<ll> costs;
vector<int> reach;
bool taken[100001];
multiset<ll> s;

void DFS1(int n, int p) {
	// cout << n << ' ' << p << '\n';
	taken[n] = true;
	for(int i = 0; i < adj1[n].size(); i++) {
		if(adj1[n][i] == p || taken[adj1[n][i]]) continue;
		DFS1(adj1[n][i], n);
	}
	reach.push_back(n);
}

void DFS2(int n, int p) {
	// cout << n << ' ' << p << '\n';
	taken[n] = true;
	for(int i = 0; i < adj2[n].size(); i++) {
		if(adj2[n][i] == p || taken[adj2[n][i]]) continue;
		DFS2(adj2[n][i], n);
	}
	s.insert(costs[n]);
}

int main() {
	int n;
	cin >> n;
	costs.resize(n);
	for(int i = 0; i < costs.size(); i++) {
		cin >> costs[i];
	}
	int m;
	cin >> m;
	adj1.resize(n);
	adj2.resize(n);
	for(int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		x--; y--;
		adj1[x].push_back(y);
		adj2[y].push_back(x);
	}
	for(int i = 0; i < n; i++) {
		if(taken[i]) continue;
		DFS1(i, -1);
	}
	for(int i = 0; i < n; i++) taken[i] = false;
	ll sum = 0, ans = 1;
	while(reach.size()) {
		int x = reach.back(); reach.pop_back();
		if(taken[x]) continue;
		DFS2(x, -1);
		ll g = *s.lower_bound(-1);
		sum += g;
		ans *= s.count(g);
		ans %= MOD;
		multiset<ll>().swap(s);
	}
	cout << sum << ' ' << ans << "\n";
}