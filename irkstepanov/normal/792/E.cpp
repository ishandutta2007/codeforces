#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;
typedef pair<ll, ll> pll;

const int inf = 1e9 + 10;

int main()
{

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	//ifstream cin("input.txt");
	//ofstream cout("output.txt");

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	vector<ll> a(n);
	vector<ll> v;

	for (ll d = 1; d * d <= inf; ++d) {
		v.pb(d);
	}

	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	for (int i = 0; i < 1; ++i) {
		for (ll d = 1; d * d <= a[i]; ++d) {
			if (a[i] % d == 0) {
				v.pb(a[i] / d - 1);
			}
			v.pb(a[i] / d);
		}
	}

	sort(all(v));
	v.resize(unique(all(v)) - v.begin());

	ll ans = 1e18;

	for (ll k : v) {
		bool ok = true;
		ll sum = 0;
		for (int i = 0; i < n; ++i) {
			ll c = (a[i] + k) / (k + 1);
			if (a[i] - c * k < 0) {
				ok = false;
				break;
			}
			sum += c;
		}
		if (ok) {
			ans = min(ans, sum);
		}
	}

	cout << ans << "\n";

}