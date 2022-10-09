#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
int a[105];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=0; i<n; i++)
		cin >> a[i];

	sort(a, a+n);

	int z = 0;

	if (n % 2) {
		z = a[0] * a[0];
		for (int i=2; i<n; i+=2)
			z += a[i] * a[i] - a[i-1] * a[i-1];
	} else {
		for (int i=1; i<n; i+=2)
			z += a[i] * a[i] - a[i-1] * a[i-1];
	}

	cout.precision(20);
	cout << fixed;
	cout << z * 3.14159263538978323 << '\n';
}