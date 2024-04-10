// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int n;
string a[30005];

int lp(string a, string b) {
	for (int i=0; i<(int)min(a.size(), b.size()); i++) {
		if (a[i] != b[i]) {
			return i;
		}
	}
	return min(a.size(), b.size());
}

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	cin >> n;
	int z = 1234;
	for (int i=0; i<n; i++) {
		cin >> a[i];
	}
	sort(a, a+n);
	for (int i=0; i<n-1; i++) {
		z = min(z, lp(a[i], a[i+1]));
	}
	cout << z << '\n';
}