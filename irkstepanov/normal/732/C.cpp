#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;

int main()
{

	//freopen("input.txt", "r", stdin);
	//ifstream cin("input.txt");

    //ios_base::sync_with_stdio(false);
	//cin.tie(0);

	ll a, b, c;
	cin >> a >> b >> c;

	ll ans = 5e18 + 100;

	for (int i = 1; i <= 3; ++i) {
		for (int j = i; j <= 3; ++j) {
			ll x = 0, y = 0, z = 0;
			if (i <= 1 && 1 <= j) {
				x = 1;
			}
			if (i <= 2 && 2 <= j) {
				y = 1;
			}
			if (i <= 3 && 3 <= j) {
				z = 1;
			}
			if (a <= x && b <= y && c <= z) {
				ans = min(ans, j - i + 1 - a - b - c);
			}
		}
	}

	for (int i = 1; i <= 3; ++i) {
		for (int j = 1; j <= 3; ++j) {
			ll x = a, y = b, z = c;
			ll skip = 0;
			if (i >= 1) {
				if (z == 0) {
					++skip;
				}
				z = max(z - 1, 0ll);
				if (i >= 2) {
					if (y == 0) {
						++skip;
					}
					y = max(y - 1, 0ll);
					if (i >= 3) {
						if (x == 0) {
							++skip;
						}
						x = max(x - 1, 0ll);
					}
				}
			}
			if (j >= 1) {
				if (x == 0) {
					++skip;
				}
				x = max(x - 1, 0ll);
				if (j >= 2) {
					if (y == 0) {
						++skip;
					}
					y = max(y - 1, 0ll);
					if (j >= 3) {
						if (z == 0) {
							++skip;
						}
						z = max(z - 1, 0ll);
					}
				}
			}
			ll extra = max(x, max(y, z));
			skip += (extra - x) + (extra - z) + (extra - y);
			ans = min(ans, skip);
		}
	}

	cout << ans << "\n";

}