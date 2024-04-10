// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int n, m, k, s;
int a[200005], b[200005];
vector<pair<int, int>> c1, c2;
int f1, f2;
ll z1[200005], z2[200005];

int gx;

bool moze(int l) {
	ll la = *min_element(a, a+l);
	ll lb = *min_element(b, b+l);

	ll u = 1e18;
	gx = -1;

	for (int g=0; g<=k; g++) {
		int h = k - g;
		if (g <= f1 && h <= f2) {
			ll u2 = z1[g] * la + z2[h] * lb;
			if (u2 < u) {
				u = u2;
				gx = g;
			}
		}
	}

	return u <= s;
}

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	cin >> n >> m >> k >> s;
	for (int i=0; i<n; i++)
		cin >> a[i];
	for (int i=0; i<n; i++)
		cin >> b[i];

	for (int i=0; i<m; i++) {
		int t, c;
		cin >> t >> c;
		(t == 1 ? c1 : c2).emplace_back(c, i+1);
	}

	sort(begin(c1), end(c1));
	sort(begin(c2), end(c2));

	f1 = c1.size();
	for (int i=0; i<f1; i++)
		z1[i+1] = z1[i] + c1[i].first;

	f2 = c2.size();
	for (int i=0; i<f2; i++)
		z2[i+1] = z2[i] + c2[i].first;

	int l = 1, r = n, o = -1;
	while (l <= r) {
		int mid = (l+r) / 2;
		if (moze(mid)) {
			o = mid;
			r = mid - 1;
		} else {
			l = mid + 1;
		}
	}

	if (o == -1) {
		cout << "-1\n";
		return 0;
	}

	moze(o);

	cout << o << '\n';
	int ia = min_element(a, a+o) - a + 1;
	int ib = min_element(b, b+o) - b + 1;

	for (int i=0; i<gx; i++)
		cout << c1[i].second << ' ' << ia << '\n';
	for (int i=0; i<k-gx; i++)
		cout << c2[i].second << ' ' << ib << '\n';

}