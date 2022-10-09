#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int z[5005], n, k;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	double sol = 0;

	cin >> n >> k;
	for (int i=1; i<=n; i++) {
		int x;
		cin >> x;
		z[i] = z[i-1] + x;
	}

	for (int i=0; i+k<=n; i++)
		for (int j=i+k; j<=n; j++) {
			sol = max(sol, 1.0 * (z[j] - z[i]) / (j-i));
		}

	cout.precision(20);
	cout << fixed << sol;
}