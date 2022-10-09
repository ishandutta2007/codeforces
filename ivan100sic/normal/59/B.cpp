#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int a[105];
int n;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	int z = 0;
	for (int i=0; i<n; i++) {
		cin >> a[i];
		z += a[i];
	}

	int sol = 0;
	if (z % 2)
		sol = z;
	for (int i=0; i<n; i++) {
		if ((z - a[i]) % 2)
			sol = max(sol, z - a[i]);
	}
	cout << sol << '\n';
}