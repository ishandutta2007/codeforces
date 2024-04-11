#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb push_back
using namespace std;
using ll = long long;
using pi = pair<int, int>;
const int maxn = 1e5 + 55;
int n, deg[maxn], p[maxn];
vector<pair<pi, pi>> edges;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for(int f, t, i = 1; i < n; i++) {
		cin >> f >> t;
		deg[f]++, deg[t]++;
		p[f] = t;
		p[t] = f;
		edges.pb({{f, t}, {i, 0}});
	}
	sort(all(edges), [](const pair<pi, pi>& a, const pair<pi, pi>& b) {
		return min(deg[a.first.first], deg[a.first.second]) < min(deg[b.first.first], deg[b.first.second]);
	});
	for(int i = 0; i < n-1; i++) edges[i].second.second = i;
	sort(all(edges), [](const pair<pi, pi>& a, const pair<pi, pi>& b) {
		return a.second.first < b.second.first;
	});
	for(auto i : edges) cout << i.second.second << "\n";
}