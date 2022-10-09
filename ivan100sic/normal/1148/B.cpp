#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, m, k;
ll a[200005], b[200005], ta, tb;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m >> ta >> tb >> k;
	for (int i=0; i<n; i++)
		cin >> a[i];
	for (int j=0; j<m; j++)
		cin >> b[j];

	ll sol = 0;
	// skinucu prvih i letova sa A
	for (int i=0; i<=k; i++) {
		if (i >= n) {
			sol = 3213213213213321ll;
			break;
		}
		
		auto it = lower_bound(b, b+m, a[i]+ta) - b;
		it += k-i;
		if (it < m) {
			sol = max(sol, b[it] + tb);
		} else {
			sol = 3213213213213321ll;
		}
	}

	if (sol == 3213213213213321ll)
		sol = -1;

	cout << sol << '\n';
}