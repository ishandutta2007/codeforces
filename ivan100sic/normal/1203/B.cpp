#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
int a[405];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int t;
	cin >> t;
	while (t--) {
		cin >> n;
		n <<= 2;
		for (int i=0; i<n; i++)
			cin >> a[i];
		sort(a, a+n);
		int m = n / 4;
		bool ok = true;
		for (int i=0; i<m; i++) {
			int p = a[2*i];
			int q = a[2*i+1];
			int r = a[n-2*i-1];
			int s = a[n-2*i-2];
			if (p != q || r != s)
				ok = false;
			if (p*r != a[0] * a[n-1])
				ok = false;
		}
		cout << (ok ? "YES\n" : "NO\n");
	}

}