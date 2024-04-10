#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, sol;
int a[5005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=0; i<n; i++)
		cin >> a[i];
	for (int i=0; i<n; i++) {
		int z = 0;
		for (int j=i; j<n; j++) {
			z += a[j];
			if (z > 100 * (j-i+1)) {
				sol = max(sol, j-i+1);
			}
		}
	}
	cout << sol << '\n';
}