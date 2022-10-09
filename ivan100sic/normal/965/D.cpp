#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

// min-cut?
int a[100005];
int z[100005];
int n, k;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> k;
	for (int i=1; i<n; i++)
		cin >> a[i];
	for (int i=1; i<=n; i++)
		z[i] = z[i-1] + a[i];

	int sol = z[k];
	for (int i=1; i+k<n; i++) {
		sol = min(sol, z[i+k] - z[i]);
	}
	cout << sol << '\n';
}