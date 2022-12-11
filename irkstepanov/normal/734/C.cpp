#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main()
{

	ll n;
	int m, k;
	cin >> n >> m >> k;

	ll x, s;
	cin >> x >> s;

	vector<pll> a(m);
	for (int i = 0; i < m; ++i) {
		cin >> a[i].second;
	}
	for (int i = 0; i < m; ++i) {
		cin >> a[i].first;
	}

	sort(all(a));

	ll ans = x * n;
	for (int i = 0; i < m; ++i) {
		if (a[i].first <= s) {
			ans = min(ans, n * a[i].second);
		}
	}

	vector<ll> cnt(k), cost(k);
	for (int i = 0; i < k; ++i) {
		cin >> cnt[i];
	}
	for (int i = 0; i < k; ++i) {
		cin >> cost[i];
	}

	vector<ll> minn(m);
	minn[0] = a[0].second;
	for (int i = 1; i < m; ++i) {
		minn[i] = min(minn[i - 1], a[i].second);
	}

	int ptr = m - 1;

	for (int i = 0; i < k; ++i) {
		if (cost[i] > s) {
			continue;
		}
		if (cnt[i] >= n) {
			ans = min(ans, ll(0));
			continue;
		}
		ans = min(ans, (n - cnt[i]) * x);
		while (ptr > 0 && a[ptr].first > s - cost[i]) {
			--ptr;
		}
		if (a[ptr].first <= s - cost[i]) {
			ans = min(ans, (n - cnt[i]) * minn[ptr]);
		}
	}

	cout << ans << "\n";

}