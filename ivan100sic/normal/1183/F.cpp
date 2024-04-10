#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i=0; i<n; i++)
		cin >> a[i];
	sort(a.begin(), a.end(), greater<int>());
	auto it = unique(a.begin(), a.end());
	n = it - a.begin();
	a.resize(n);
	// mora tacno jedan
	int sol = a[0];
	// mora tacno dva
	for (int i=0; i+1<n; i++) {
		if (a[i] + a[i+1] < sol)
			break;
		for (int j=i+1; j<n; j++) {
			if (a[i] + a[j] < sol)
				break;
			if (a[i] % a[j]) {
				sol = max(sol, a[i] + a[j]);
				break;
			}
		}
	}
	// mora tacno tri
	for (int i=0; i+2<n; i++) {
		if (a[i] + a[i+1] + a[i+2] < sol)
			break;
		for (int j=i+1; j+1<n; j++) {
			if (a[i] + a[j] + a[j+1] < sol)
				break;
			if (a[i] % a[j] == 0)
				continue;
			for (int k=j+1; k<n; k++) {
				if (a[i] + a[j] + a[k] < sol)
					break;
				if (a[i] % a[k] && a[j] % a[k]) {
					sol = max(sol, a[i] + a[j] + a[k]);
					break;
				}
			}
		}
	}
	cout << sol << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int t;
	cin >> t;
	while (t--) {
		solve();
	}
}