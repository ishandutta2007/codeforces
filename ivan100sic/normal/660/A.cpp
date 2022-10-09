#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int a[1005], b[2005], j, n;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	int last = 1;
	for (int i=0; i<n; i++) {
		int x;
		cin >> x;
		if (gcd(x, last) == 1) {
			b[j++] = x;
		} else {
			b[j++] = 1;
			b[j++] = x;
		}
		last = x;
	}

	cout << j-n << '\n';
	for (int i=0; i<j; i++)
		cout << b[i] << ' ';
	cout << '\n';
}