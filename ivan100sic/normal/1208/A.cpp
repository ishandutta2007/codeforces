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

	int t;
	cin >> t;
	while (t--) {
		int a[3];
		cin >> a[0] >> a[1];
		a[2] = a[0] ^ a[1];
		int x;
		cin >> x;
		cout << a[x%3] << '\n';
	}
}