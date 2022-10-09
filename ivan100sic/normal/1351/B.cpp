// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	int t;
	cin >> t;
	while (t--) {
		int a, b, c, d, z = 0;
		cin >> a >> b >> c >> d;
		z |= b + d == a && b + d == c;
		swap(a, b);
		z |= b + d == a && b + d == c;
		swap(c, d);
		z |= b + d == a && b + d == c;
		swap(a, b);
		z |= b + d == a && b + d == c;
		cout << (z >= 1 ? "Yes\n" : "No\n");
	}
}