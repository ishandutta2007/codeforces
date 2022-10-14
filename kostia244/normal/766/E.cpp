#include <bits/stdc++.h>
using namespace std;
const int maxn = 151000, C = 512;
using ll = long long;
int n, a[maxn];
vector<int> g[maxn];
array<ll, 2> total;
array<ll, 2> count(int v, int b, int P) {
	array<ll, 2> p = {0, 0};
	int f = (a[v]>>b)&1;
	p[f]++;
	total[f]++;
	for(auto &i : g[v]) if(i != P) {
		auto t = count(i, b, v);
		total[0] += t[0]*p[0] + t[1]*p[1];
		total[1] += t[0]*p[1] + t[1]*p[0];
		p[f] += t[0];
		p[1^f] += t[1];
	}
	return p;
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int f, t, i = 1; i < n; i++) {
		cin >> f >> t;
		g[f].push_back(t);
		g[t].push_back(f);
	}
	ll ans = 0;
	for(int i = 0; i < 20; i++) {
		total = {0, 0};
		count(1, i, -1);
		//cout << total[0] << " " << total[1] << endl;
		ans += total[1]<<i;
	}
	cout << ans << endl;
}