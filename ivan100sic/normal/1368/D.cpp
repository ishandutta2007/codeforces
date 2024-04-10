// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int n;
int c[20], a[200005];

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	cin >> n;
	for (int i=0; i<n; i++) {
		int x;
		cin >> x;
		for (int j=0; j<20; j++) {
			if (x & (1 << j)) {
				c[j]++;
			}
		}
	}

	for (int j=0; j<20; j++) {
		for (int r=0; r<c[j]; r++) {
			a[r] |= 1 << j;
		}
	}

	ll z = 0;
	for (int i=0; i<n; i++) {
		z += a[i] * 1ll * a[i];
	}

	cout << z << '\n';
}