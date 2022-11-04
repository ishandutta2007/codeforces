#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

// views::zip, ranges::sort

typedef long long ll;
typedef long double ld;

void ProGamerMove() {
	int n; cin >> n;
	vector<int> p(n), id(n, -1), ip(n);
	int tmp = 0;
	for (int& v : p) cin >> v, ip[--v] = tmp++;
	int cid = -1;
	for (int i = 0; i < n; ++i) if (id[i] == -1) {
		id[i] = ++cid;
		for (int u = p[i]; u != i; u = p[u]) id[u] = cid;
	}
	vector<int> done(cid + 1, -1);
	done[id[0]] = true;
	for (int i = 0; i < n - 1; ++i) if (done[id[i]] ^ done[id[i + 1]]) {
		swap(p[ip[i]], p[ip[i + 1]]);
		swap(ip[i], ip[i + 1]);
		done[id[i]] = done[id[i + 1]] = true;
	}
	vector<int> res = {p[0] + 1};
	for (int u = p[p[0]]; u != p[0]; u = p[u]) res.push_back(u + 1);
	reverse(res.begin(), res.end());
	for (int v : res) cout << v << ' '; cout << '\n';
}

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	cout << setprecision(9) << fixed;
	int tc = 1;
	cin >> tc;
	while (tc--) ProGamerMove();
}