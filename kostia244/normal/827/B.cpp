#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
const int maxn = 1<<21, mod = 1e9 + 7;
int n, k, d[maxn];
vector<array<int, 2>> edges;
signed main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> k;
	queue<int> lft;
	int fi = 0, se = 0;
	lft.push(1);
	int sz = 1;
	while(!lft.empty()) {
		int t = lft.front(); lft.pop();
		if(t > n-k) {
			if(fi < d[t]) se = fi, fi = d[t];
			else if(se < d[t]) se = d[t];
		}
		for(int C = t==1?k:1; C-- && sz < n;) {
			lft.push(++sz);
			d[sz] = d[t] + 1;
			edges.push_back({t, sz});
		}
	}
	cout << fi+se << endl;
	for(auto &[u, v] : edges) cout << u << " " << v << endl;
}