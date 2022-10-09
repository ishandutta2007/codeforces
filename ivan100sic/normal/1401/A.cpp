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
		int a, d;
		cin >> a >> d;
		if (d > a) {
			cout << d-a << '\n';
		} else {
			cout << (a-d) % 2 << '\n';
		}
	}
}