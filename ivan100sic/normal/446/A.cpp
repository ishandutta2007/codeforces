#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
int a[100005];
int b[100005], c[100005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=1; i<=n; i++)
		cin >> a[i];
	b[1] = 1;
	for (int i=2; i<=n; i++) {
		b[i] = b[i-1] + 1;
		if (a[i-1] >= a[i])
			b[i] = 1;
	}
	c[n] = 1;
	for (int i=n-1; i>=1; i--) {
		c[i] = c[i+1] + 1;
		if (a[i+1] <= a[i])
			c[i] = 1;
	}
	int sol = 0;
	for (int i=2; i<n; i++) {
		if (a[i+1] - a[i-1] >= 2) {
			// moze
			sol = max(sol, b[i-1] + c[i+1] + 1);
		} else {
			sol = max({sol, b[i-1] + 1, c[i+1] + 1});
		}
	}
	sol = max({sol, b[n-1] + 1, c[2] + 1});
	cout << sol << '\n';
}