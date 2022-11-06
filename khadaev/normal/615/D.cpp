#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int MOD = 1000 * 1000 * 1000 + 7;

ll Pow(ll n, ll k) {
	if (k == 0) return 1;
	ll t = Pow(n, k / 2);
	t = t * t % MOD;
	if (k % 2) t = t * n % MOD;
	return t;
}

int main() {
	int m;
	scanf("%d", &m);
	vector<int> a(m);
	for (int i = 0; i < m; ++i) scanf("%d", &a[i]);
	sort(a.begin(), a.end());
	vector<pair<ll, ll> > p;
	for (int i = 0; i < m; ++i) {
		if (i == 0 || a[i] != a[i - 1])
			p.push_back({a[i], 1});
		else
			p.back().second++;
	}
	int t = p.size();
	vector<ll> pr_prod(t), sf_prod(t);
	pr_prod[0] =  1 + p[0].second;
	for (int i = 1; i < t; ++i)
		pr_prod[i] = pr_prod[i - 1] * (1 + p[i].second) % (MOD - 1);
	sf_prod[t - 1] = 1 + p[t - 1].second;
	for (int i = t - 2; i >= 0; --i)
		sf_prod[i] = sf_prod[i + 1] * (1 + p[i].second) % (MOD - 1);
	ll ans = 1;
	for (int i = 0; i < t; ++i) {
		ll deg = (i ? pr_prod[i - 1] : 1) * (i == t - 1 ? 1 :
		sf_prod[i + 1]) % (MOD - 1);
		ll s = p[i].second * (p[i].second + 1) / 2 % (MOD - 1);
		deg = deg * s % (MOD - 1);
		ans = ans * Pow(p[i].first, deg) % MOD;
	}
	printf("%d\n", (int)ans);

}