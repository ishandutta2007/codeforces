#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const ll INF = 1123123123123123ll;

int n;
ll r;
ll b[100005];
int p[100005], d[100005];

typedef pair<int, int> val;

struct node {
	int l, r;
	val v;
} a[100005 * 65]; int sz;

void add(ll p, val v, int& x, ll xl=0, ll xr=INF) {
	if (!x)
		x = ++sz;

	a[x].v = max(a[x].v, v);

	if (xl != xr) {
		ll xm = (xl+xr) >> 1;
		if (p <= xm)
			add(p, v, a[x].l, xl, xm);
		else
			add(p, v, a[x].r, xm+1, xr);
	}
}

val query(ll l, ll r, int x, ll xl=0, ll xr=INF) {
	if (!x || r < xl || xr < l || r < l)
		return {0, 0};
	if (l <= xl && xr <= r)
		return a[x].v;
	ll xm = (xl+xr) >> 1;
	return max(
		query(l, r, a[x].l, xl, xm),
		query(l, r, a[x].r, xm+1, xr)
	);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> r;
	int root = 0;

	for (int i=1; i<=n; i++) {
		cin >> b[i];

		auto val = query(b[i]+r, INF, root);
		val = max(val, query(0, b[i]-r, root));

		p[i] = val.second;
		d[i] = val.first + 1;

		add(b[i], {d[i], i}, root);
	}

	int p0 = max_element(d+1, d+n+1) - d;
	basic_string<int> sol;
	for (int i=p0; i; i=p[i])
		sol += i;

	reverse(sol.begin(), sol.end());
	cout << sol.size() << '\n';
	for (int x : sol)
		cout << x << ' ';
	cout << '\n';
}