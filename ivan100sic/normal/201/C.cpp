#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
ll a[100005], levo[100005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	n--;
	for (int i=1; i<=n; i++)
		cin >> a[i];

	ll vr = 0, par = 0;
	for (int i=1; i<=n; i++) {
		// prosiri za neparan broj
		ll t = vr + (a[i] % 2 ? a[i] : a[i]-1);
		par = a[i] == 1 ? 0 : (par + (a[i] % 2 ? a[i] - 1 : a[i]));
		vr = levo[i] = max(t, par);
	}

	// for (int i=0; i<=n; i++)
	// 	cerr << levo[i] << ' ';
	// cerr << '\n';

	ll sol = 0;

	par = 0;
	for (int i=n; i>=0; i--) {
		sol = max(sol, par + levo[i]);
		par = a[i] == 1 ? 0 : (par + (a[i] % 2 ? a[i] - 1 : a[i]));
	}

	cout << sol << '\n';
}