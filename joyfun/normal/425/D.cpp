#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) (int)x.size()

const int N = 100005;
const int inf = 0x3f3f3f3f;

int n, x[N], y[N];
unordered_set<int> p[N];
vi r[N], c[N];

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d%d", &x[i], &y[i]);
		p[x[i]].insert(y[i]);
		r[x[i]].pb(y[i]); c[y[i]].pb(x[i]);
	}
	ll ans = 0;
	for (int i = 0; i < n; i++) {
		if (sz(r[x[i]]) < sz(c[y[i]])) {
			for (int j = 0; j < sz(r[x[i]]); j++) {
				int v = r[x[i]][j];
				if (v <= y[i]) continue;
				int len = v - y[i];
				if (x[i] + len < N && p[x[i] + len].count(y[i]) && p[x[i] + len].count(v)) ans++;
			}
		} else {
			for (int j = 0; j < sz(c[y[i]]); j++) {
				int v = c[y[i]][j];
				if (v <= x[i]) continue;
				int len = v - x[i];
				if (p[x[i]].count(y[i] + len) && p[v].count(y[i] + len)) ans++;
			}
		}
	}
	printf("%lld\n", ans);
	return 0;
}