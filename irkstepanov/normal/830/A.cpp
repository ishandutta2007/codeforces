#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef double ld;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	//ifstream cin("input.txt");

	int n, k;
	ll pos;
	cin >> n >> k;
	cin >> pos;

	vector<ll> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	vector<ll> b(k);
	for (int i = 0; i < k; ++i) {
		cin >> b[i];
	}

	sort(all(a));
	sort(all(b));

	ll lf = -1, rg = 1e15;
	while (rg - lf > 1) {
		ll t = (lf + rg) >> 1;
		vector<vector<int> > id(k);
		vector<int> deg(n);
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < k; ++j) {
				if (abs(a[i] - b[j]) + abs(b[j] - pos) <= t) {
					++deg[i];
					id[j].pb(i);
				}
			}
		}
		vector<char> used(n, false);
		for (int j = 0; j < k; ++j) {
			if (id[j].empty()) {
				continue;
			}
			int best = -1;
			for (int i : id[j]) {
				if (used[i]) {
					continue;
				}
				if (best == -1 || deg[i] < deg[best]) {
					best = i;
				}
			}
			if (best != -1) {
				used[best] = true;
				deg[best] = 1e9;
			}
			for (int i : id[j]) {
				--deg[i];
			}
		}
		bool ok = true;
		for (int i = 0; i < n; ++i) {
			if (!used[i]) {
				ok = false;
				break;
			}
		}
		if (ok) {
			rg = t;
		} else {
			lf = t;
		}
	}

	cout << rg << "\n";

}