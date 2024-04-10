#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int z, n, a[5005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=0; i<n; i++)
		cin >> a[i];
	sort(a, a+n);
	for (int i=1; i<n; i++) {
		int y = max(a[i], a[i-1] + 1);
		z += y - a[i];
		a[i] = y;
	}
	cout << z << '\n';
}