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
		int a, b;
		cin >> a >> b;
		int x = min(max(2*a, b), max(2*b, a));
		cout << x * x << '\n';
	}
}