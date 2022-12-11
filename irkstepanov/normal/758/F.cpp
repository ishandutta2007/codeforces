#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;

const int nmax = 5000;
const ll inf = 1e9;

int main()
{

	//ifstream cin("input.txt");
	//ofstream cout("output.txt");

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	ll n, l, r;
	cin >> n >> l >> r;

	if (n == 1) {
		cout << r - l + 1 << "\n";
		return 0;
	}
	if (n == 2) {
		cout << (r - l + 1) * (r - l) << "\n";
		return 0;
	}

	ll ans = 0;

	vector<ll> deg(nmax);
	for (int i = 1; i < nmax; ++i) {
		ll val = 1;
		for (int j = 0; j < n - 1; ++j) {
			val *= ll(i);
			if (val > r) {
				val = inf;
				break;
			}
		}
		deg[i] = val;
	}

	for (int q = 1; q < nmax; ++q) {
		for (int p = q + 1; p < nmax; ++p) {
			if (__gcd(p, q) != 1) {
				continue;
			}
			if (deg[p] <= r) {
				ll lf = l / deg[q];
				if (l % deg[q]) {
					++lf;
				}
				ll rg = r / deg[p];
				if (lf <= rg) {
					ans += rg - lf + 1;
				}
			}
		}
	}

	cout << ans * ll(2) << "\n";

}