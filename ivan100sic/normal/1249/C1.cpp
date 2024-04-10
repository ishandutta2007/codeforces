#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

ll a[50];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int q;
	cin >> q;
	while (q--) {
		ll x;
		cin >> x;
		for (int i=0; i<50; i++)
			a[i] = x % 3, x /= 3;
		for (int i=49; i>=0; i--)
			if (a[i] == 2) {
				for (int j=i+1; j<50; j++)
					if (a[j] == 0) {
						a[j] = 1;
						fill(a, a+j, 0);
						break;
					}
			}
		for (int i=49; i>=0; i--)
			x = 3*x + a[i];
		cout << x << '\n';
	}
}