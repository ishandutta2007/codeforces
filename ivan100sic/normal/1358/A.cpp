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
		cout << a*b/2 + a%2*b%2 << '\n';
	}
}