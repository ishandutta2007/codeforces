#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
ll t, vred[100005], resenje[100005];
int cookies[100005], difficulty[100005];
basic_string<pair<int, int>> e[100005];

const int MAXN = 1 << 20;
ll a[2 * MAXN], b[2 * MAXN];

void dodaj(ll amt, ll x) {
	a[x + MAXN] += amt;
	b[x + MAXN] += amt * x;
	x += MAXN;
	while (x > 1) {
		x >>= 1;
		a[x] = a[2*x] + a[2*x+1];
		b[x] = b[2*x] + b[2*x+1];
	}
}

ll citaj(ll amt) {
	int x = 1, xl = 0, xr = MAXN-1;
	ll pojeo = 0;
	while (xl != xr) {
		if (amt >= b[2*x]) {
			amt -= b[2*x];
			pojeo += a[2*x];
			x = 2*x+1;
			xl = ((xl + xr) >> 1) + 1;
		} else {
			x = 2*x;
			xr = (xl + xr) >> 1;			
		}
	}

	ll r = pojeo + min(a[x], amt / xl);
	return r;
}

void dfs(int x, ll trem) {
	if (trem < 0)
		return;

	dodaj(cookies[x], difficulty[x]);
	vred[x] = citaj(trem);

	for (auto ee : e[x])
		dfs(ee.first, trem - 2 * ee.second);

	dodaj(-cookies[x], difficulty[x]);
}

void resi(int x) {
	resenje[x] = vred[x];
	basic_string<ll> tmp;
	for (auto ee : e[x]) {
		resi(ee.first);
		tmp += resenje[ee.first];
	}
	tmp += {0, 0};
	sort(tmp.begin(), tmp.end(), greater<ll>());
	resenje[x] = max(resenje[x], tmp[x != 1]);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> t;
	for (int i=1; i<=n; i++)
		cin >> cookies[i];
	for (int i=1; i<=n; i++)
		cin >> difficulty[i];
	for (int i=2; i<=n; i++) {
		int x, y;
		cin >> x >> y;
		e[x] += {i, y};
	}
	dfs(1, t);
	resi(1);
	cout << resenje[1] << '\n';
}