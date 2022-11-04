#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

void ProGamerMove() {
	int n; cin >> n;
	vector<int> cnt(n);
	for (int v, i = 0; i < n - 1; ++i) cin >> v, ++cnt[--v];
	priority_queue<int> p, q; p.push(1);
	for (int i = 0; i < n; ++i) if (cnt[i]) p.push(cnt[i]);
	int res = 0;
	while (p.size() || q.size()) {
		++res;
		if (q.size()) {
			vector<int> v;
			while (q.size()) { v.push_back(q.top() - 1); q.pop(); }
			for (int u : v) if (u) q.push(u);
		}
		if (p.size()) {
			if (p.top() > 1) q.push(p.top() - 1);
			p.pop();
		} else if (q.size()) {
			int u = q.top(); q.pop();
			if (u > 1) q.push(--u);
		}
	}
	cout << res << "\n";
}

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	cout << setprecision(9) << fixed;
	int tc = 1;
	cin >> tc;
	while (tc--) ProGamerMove();
}