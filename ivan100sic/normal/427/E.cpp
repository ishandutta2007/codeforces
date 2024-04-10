// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int n, m;
int a[1000005];
ll z[1000005];

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	cin >> n >> m;
	for (int i=0; i<n; i++)
		cin >> a[i];

	ll q = 0, t = 0;
	for (int i=0; i<n; i++) {
		z[i] += t*a[i] - q;
		if (i % m == 0) {
			q += a[i];
			t++;
		}
	}

	q = t = 0;
	for (int i=0; i<n; i++) {
		int j = n-i-1;
		z[j] += q - t*a[j];
		if (i % m == 0) {
			q += a[j];
			t++;
		}
	}

	cout << *min_element(z, z+n)*2 << '\n';
}