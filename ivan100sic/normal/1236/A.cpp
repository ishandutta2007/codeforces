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
		int a, b, c;
		cin >> a >> b >> c;

		int z = 0;
		for (int i=0; i<=100; i++) {
			for (int j=0; j<=100; j++) {
				if (i <= a && 2*i + j <= b && 2*j <= c) {
					z = max(z, 3*i + 3*j);
				}
			}
		}

		cout << z << '\n';
	}
}