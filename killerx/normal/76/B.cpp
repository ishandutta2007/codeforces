#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
int main() {
// 	freopen("a.in", "r", stdin);
// 	freopen("a.out", "w", stdout);
	int n, m, y_0, y_1;
	scanf("%d %d %d %d", &n, &m, &y_0, &y_1);
	vector<int> a(n), b(m);
	rep(i, n) scanf("%d", &a[i]);
	rep(i, m) scanf("%d", &b[i]);
	int ans = 0;
	vector<int> match(m, -1);
	rep(i, n) {
		int p = lower_bound(b.begin(), b.end(), a[i]) - b.begin();
		int mn = 1e9;
		vector<int> adj;
		if (p < m) {
			if (mn > b[p] - a[i]) {
				mn = b[p] - a[i];
				adj.clear();
			}
			if (mn == b[p] - a[i]) {
				adj.pb(p);
			}
		}
		--p;
		if (p >= 0) {
			if (mn > a[i] - b[p]) {
				mn = a[i] - b[p];
				adj.clear();
			}
			if (mn == a[i] - b[p]) {
				adj.pb(p);
			}
		}
		sort(adj.begin(), adj.end());
		rep(j, adj.size()) {
			if (!~match[adj[j]] || abs(b[adj[j]] - a[match[adj[j]]]) == abs(b[adj[j]] - a[i])) {
				match[adj[j]] = i;
				++ans;
				break;
			} else if (~match[adj[j]] && abs(b[adj[j]] - a[match[adj[j]]]) > abs(b[adj[j]] - a[i])) {
				match[adj[j]] = i;
			}
		}
	}
	printf("%d\n", n - ans);
	return 0;
}