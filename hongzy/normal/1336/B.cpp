#include <bits/stdc++.h>
using namespace std;

#define ucin ios::sync_with_stdio(0), cin.tie(0)
#define fs first
#define sc second
#define pb push_back
#define mp make_pair
typedef pair<int, int> pii;
typedef double db;
typedef long long ll;
typedef long double ldb;
typedef unsigned long long ull;

const int N = 2e5 + 10;
int na, nb, nc;
ll dis(ll x, ll y) {
	return (x - y) * (x - y);
}
ll solve(vector<int> &a, vector<int> &b, vector<int> &c) {
	ll ans = 6e18;
	for(int i = 0; i < (int) a.size(); i ++) {
		int p1 = lower_bound(b.begin(), b.end(), a[i]) - b.begin();
		int p2 = upper_bound(c.begin(), c.end(), a[i]) - c.begin() - 1;
		if(p1 == b.size() || p2 == c.size() || p1 == -1 || p2 == -1) continue  ;
		ans = min(ans, dis(a[i], b[p1]) + dis(a[i], c[p2]) + dis(c[p2], b[p1]));
	}
	return ans;
}
int main() {
	int t; scanf("%d", &t);
	while(t --) {
		scanf("%d%d%d", &na, &nb, &nc);
		vector<int> a(na), b(nb), c(nc);
		for(int i = 0; i < na; i ++) {
			int x; scanf("%d", &x); a[i] = x;
		}
		for(int i = 0; i < nb; i ++) {
			int x; scanf("%d", &x); b[i] = x;
		}
		for(int i = 0; i < nc; i ++) {
			int x; scanf("%d", &x); c[i] = x;
		}
		sort(a.begin(), a.end());
		sort(b.begin(), b.end());
		sort(c.begin(), c.end());
		ll ans = solve(a, b, c);
		ans = min(ans, solve(a, c, b));
		ans = min(ans, solve(b, a, c));
		ans = min(ans, solve(b, c, a));
		ans = min(ans, solve(c, a, b));
		ans = min(ans, solve(c, b, a));
		printf("%lld\n", ans);
	}
	return 0;
}