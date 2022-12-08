#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <cmath>
#include <algorithm>
#include <deque>
#include <cassert>
#include <math.h>
#include <random>

using namespace std;

#define PI 3.14159265
typedef long long ll;

const ll INF = 4 * 1e18;
const int INFi = 2 * 1e9;
ll mod = 1e9 + 7;
long double eps = 1e-8;

vector<int> p;
vector<vector<int>> edge;
vector<ll> a;
vector<ll> s;

bool dfs(int v) {
	bool fl = true;
	if (s[v] != -1) {
		if(p[v] != -1)	a[v] = s[v] - s[p[v]];
		else a[v] = s[v];
	}
	else {
		ll mini = INF;
		for (int u : edge[v]) {
			mini = min(mini, s[u]);
		}
		if (mini < s[p[v]]) return false;
		if (mini == INF) {
			a[v] = 0;
		}
		else {
			a[v] = mini - s[p[v]];
			s[v] = s[p[v]] + a[v];
		}
	}
	for (int u : edge[v]) {
		if (s[u] != -1 && s[u] < s[v]) return false;
		if (!dfs(u)) return false;
	}
	return true;
}

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
	
	int n;
	cin >> n;
	p.resize(n);
	p[0] = -1;
	edge.resize(n);
	a.resize(n);
	s.resize(n);
	int t;
	for (int i = 1; i < n; i++) {
		cin >> t; t--;
		p[i] = t;
		edge[t].push_back(i);
	}
	for (int i = 0; i < n; i++) cin >> s[i];
	if (dfs(0)) {
		ll ans = 0;
		for (ll i : a) ans += i;
		cout << ans << endl;
	}
	else {
		cout << -1 << endl;
	}
	//system("pause");
	return 0;
}