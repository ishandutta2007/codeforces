#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, k;
int a[100005], t[100005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> k;
	for (int i=1; i<=n; i++)
		cin >> a[i];
	for (int i=1; i<=n; i++)
		cin >> t[i];

	int base = 0;
	for (int i=1; i<=n; i++)
		base += a[i] * t[i];

	int sum = 0, sol = 0;
	for (int i=1; i<=k; i++) {
		if (!t[i])
			sum += a[i];
	}
	sol = max(sol, sum);
	for (int i=k+1; i<=n; i++) {
		if (!t[i])
			sum += a[i];
		if (!t[i-k])
			sum -= a[i-k];
		sol = max(sol, sum);
	}

	cout << base + sol << '\n';
}