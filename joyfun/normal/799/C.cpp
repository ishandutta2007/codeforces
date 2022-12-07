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
int n, c, d;
int b[N], p[N], t[N];
vector<pii> g;
int mx[N];

int get(int c) {
	sort(g.begin(), g.end());
	for (int i = 0; i < sz(g); i++) {
		if (i == 0) mx[i] = g[i].se;
		else mx[i] = max(mx[i - 1], g[i].se);
	}
	int ans = -inf;
	for (int i = sz(g) - 1; i >= 0; i--) {
		int sum = g[i].se;
		g.pop_back();
		int yu = c - g[i].fi;
		int v = upper_bound(g.begin(), g.end(), mp(yu, inf)) - g.begin() - 1;
		if (v < 0) continue;
		sum += mx[v];
		ans = max(ans, sum);
	}
	return ans;
}

int main() {
	scanf("%d%d%d", &n, &c, &d);
	for (int i = 1; i <= n; i++) {
		char c;
		scanf("%d%d %c", &b[i], &p[i], &c);
		if (c == 'C') t[i] = 0;
		else t[i] = 1;
	}
	int m1 = -inf, m2 = -inf;
	for (int i = 1; i <= n; i++) {
		if (t[i] == 0 && p[i] <= c) m1 = max(m1, b[i]);
		if (t[i] == 1 && p[i] <= d) m2 = max(m2, b[i]);
	}
	int ans = 0;
	ans = max(ans, m1 + m2);
	g.clear(); for (int i = 1; i <= n; i++) if (t[i] == 0) g.pb(mp(p[i], b[i]));
	ans = max(ans, get(c));
	g.clear(); for (int i = 1; i <= n; i++) if (t[i] == 1) g.pb(mp(p[i], b[i])); 
	ans = max(ans, get(d));
	printf("%d\n", ans);
	return 0;
}