#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
int a[100005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=0; i<n; i++)
		cin >> a[i];

	for (int i=0; i<n; i++) {
		int mn = 2e9;
		if (i < n-1)
			mn = min(mn, a[i+1] - a[i]);
		if (i > 0)
			mn = min(mn, a[i] - a[i-1]);
		cout << mn << ' ';

		int mx = 0;
		mx = max(mx, a[n-1] - a[i]);
		mx = max(mx, a[i] - a[0]);

		cout << mx << '\n';
	}
}