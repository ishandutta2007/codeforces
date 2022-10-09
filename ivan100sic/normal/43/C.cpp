// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int c[3];

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	int t;
	cin >> t;
	while (t--) {
		int x;
		cin >> x;
		c[x%3]++;
	}

	cout << c[0]/2 + min(c[1], c[2]) << '\n';
}