#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ld, ld> pld;

int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int n, q;
	ll l;
	cin >> n >> q >> l;

	vector<ll> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	int ans = 0;
	for (int i = 0; i < n; ++i) {
		if (a[i] > l) {
			++ans;
			if (i && a[i - 1] > l) {
				--ans;
			}
		}
	}

	while (q--) {
		int tp;
		cin >> tp;
		if (tp == 0) {
			cout << ans << "\n";
		} else {
			int pos;
			ll val;
			cin >> pos >> val;
			--pos;
			if (a[pos] > l) {
				continue;
			}
			a[pos] += val;
			if (a[pos] > l) {
				++ans;
				if (pos && a[pos - 1] > l) {
					--ans;
				}
				if (pos + 1 < n && a[pos + 1] > l) {
					--ans;
				}
			}
		}
	}
	
}