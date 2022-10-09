#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
int a[105], k, z;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=1; i<=n; i++) {
		cin >> a[i];
		z += a[i];
	}
	for (int i=1; i<=n; i++) {
		if ((z - a[i]) % 2 == 0)
			k++;
	}
	cout << k << '\n';
}