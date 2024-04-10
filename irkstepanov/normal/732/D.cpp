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

	int n, m;
	cin >> n >> m;

	vector<int> v(n);
	for (int i = 0; i < n; ++i) {
		cin >> v[i];
	}
	v.pb(0);
	++n;
	vector<int> a(m + 1);
	for (int i = 1; i <= m; ++i) {
		cin >> a[i];
	}

	int lf = 0, rg = n - 1;

	while (rg - lf > 1) {
		int md = (lf + rg) >> 1;
		vector<int> pos(m + 1, -1);
		int found = 0;
		for (int i = 0; i <= md; ++i) {
			if (v[i]) {
				if (pos[v[i]] == -1) {
					++found;
				}
				pos[v[i]] = i;
			}
		}
		if (found < m) {
			lf = md;
			continue;
		}
		vector<int> order;
		for (int i = 0; i <= md; ++i) {
			if (v[i] && pos[v[i]] == i) {
				order.pb(v[i]);
			}
		}
		int occupied = 0;
		bool ok = true;
		for (int i = 0; i < sz(order); ++i) {
			int x = order[i];
			int p = pos[x];
			if (p - occupied >= a[x]) {
				occupied += a[x] + 1;
			} else {
				ok = false;
				break;
			}
		}
		if (ok) {
			rg = md;
		} else {
			lf = md;
		}
	}

	if (rg == n - 1) {
		cout << "-1\n";
		return 0;
	} else {
		cout << rg + 1 << "\n";
	}

}