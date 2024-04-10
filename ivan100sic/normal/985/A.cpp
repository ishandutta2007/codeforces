#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int sol = 123123123;
	int n, a[105];
	cin >> n;
	for (int i=1; i<=n/2; i++)
		cin >> a[i];
	sort(a+1, a+n/2+1);

	int z = 0;
	for (int i=1; i<=n/2; i++) {
		z += abs(2*i-1 - a[i]);
	}
	sol = z;
	z = 0;
	for (int i=1; i<=n/2; i++) {
		z += abs(2*i - a[i]);
	}
	cout << min(z, sol);
}