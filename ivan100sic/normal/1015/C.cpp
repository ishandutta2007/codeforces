#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

struct pesma {
	ll compressed, raw;
	bool operator< (const pesma& o) const {
		return raw - compressed > o.raw - o.compressed;
	}
};

pesma a[100005];
ll x[100005], y[100005];
ll n, m;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m;
	for (int i=1; i<=n; i++) {
		cin >> a[i].raw >> a[i].compressed;
	}

	sort(a+1, a+n+1);

	for (int i=1; i<=n; i++)
		x[i] = x[i-1] + a[i].compressed;
	for (int i=n; i>=1; i--)
		y[i] = y[i+1] + a[i].raw;

	int sol = 123123123;

	for (int i=0; i<=n; i++) {
		if (x[i] + y[i+1] <= m)
			sol = min(sol, i);
	}

	if (sol == 123123123)
		sol = -1;

	cout << sol << '\n';

}