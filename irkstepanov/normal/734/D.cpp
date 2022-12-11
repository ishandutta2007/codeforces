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

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	int x0, y0;
	cin >> x0 >> y0;

	vector<char> f(8, '-');
	vector<pii> pos(8);

	while (n--) {
		char type;
		cin >> type;
		int x, y;
		cin >> x >> y;
		x -= x0, y -= y0;
		if (x == 0) {
			if (y > 0) {
				if (f[0] == '-' || pos[0].second > y) {
					pos[0] = {x, y};
					f[0] = type;
				}
			}
			if (y < 0) {
				if (f[4] == '-' || pos[4].second < y) {
					pos[4] = {x, y};
					f[4] = type;
				}
			}
		}

		if (y == 0) {
			if (x > 0) {
				if (f[2] == '-' || pos[2].first > x) {
					pos[2] = {x, y};
					f[2] = type;
				}
			}
			if (x < 0) {
				if (f[6] == '-' || pos[6].first < x) {
					pos[6] = {x, y};
					f[6] = type;
				}
			}
		}

		if (x == y) {
			if (x > 0) {
				if (f[1] == '-' || pos[1].first > x) {
					pos[1] = {x, y};
					f[1] = type;
				}
			}
			if (x < 0) {
				if (f[5] == '-' || pos[5].first < x) {
					pos[5] = {x, y};
					f[5] = type;
				}
			}
		}

		if (x == -y) {
			if (x > 0) {
				if (f[3] == '-' || pos[3].first > x) {
					pos[3] = {x, y};
					f[3] = type;
				}
			}
			if (x < 0) {
				if (f[7] == '-' || pos[7].first < x) {
					pos[7] = {x, y};
					f[7] = type;
				}
			}
		}
	}

	bool ok = false;
	if (f[0] == 'R' || f[2] == 'R' || f[4] == 'R' || f[6] == 'R') {
		ok = true;
	}
	if (f[1] == 'B' || f[3] == 'B' || f[5] == 'B' || f[7] == 'B') {
		ok = true;
	}
	for (int i = 0; i < 8; ++i) {
		if (f[i] == 'Q') {
			ok = true;
		}
	}

	cout << (ok ? "YES\n" : "NO\n");

}