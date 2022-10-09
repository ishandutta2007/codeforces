#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, k;
int a[200005], b[200005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> k;
	for (int i=1; i<=n; i++)
		cin >> a[i];
	for (int i=1; i<=n; i++)
		cin >> b[i];
	swap(a[k], a[n]);

	sort(a+1, a+n);
	sort(b+1, b+n+1);
	reverse(b+1, b+n);

	int r = 0;
	int x = a[n] + b[n];

	
	/*cerr << "X " << x << '\n';
	for (int i=1; i<=n; i++)
		cerr << a[i] << ' ' << b[i] << '\n';*/
	

	int j = 1;
	for (int i=1; i<n; i++) {
		while (j < n && a[i] + b[j] > x) {
			j++;
		}

		// cerr << "L " << i << ' ' << j << '\n';

		if (j < n) { // ok
			r++;
			j++;
		}
	}

	cout << n-r << '\n';

}