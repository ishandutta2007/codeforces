#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, h;
int a[1005];
int b[1005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> h;
	for (int i=0; i<n; i++)
		cin >> a[i];

	int ok = 0;
	for (int k=1; k<=n; k++) {
		copy(a, a+k, b);
		sort(b, b+k);
		reverse(b, b+k);
		int x = 0;
		for (int i=0; i<k; i+=2) {
			x += max(b[i], b[i+1]);
			if (x > h)
				break;
		}

		// cerr << "moze " << k << ' ' << x << '\n';

		if (x <= h)
			ok = k;
	}
	cout << ok << '\n';
}