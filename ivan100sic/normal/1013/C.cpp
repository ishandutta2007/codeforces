#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
ll a[200005], sol = 1.1e18;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=0; i<2*n; i++)
		cin >> a[i];

	sort(a, a+2*n);

	sol = (a[n-1] - a[0]) * (a[2*n-1] - a[n]);
	for (int i=1; i<n; i++) {
		sol = min(sol, (a[2*n-1] - a[0]) * (a[i+n-1] - a[i]));
	}

	cout << sol;
}