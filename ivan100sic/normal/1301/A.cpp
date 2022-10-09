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
		string a, b, c;
		cin >> a >> b >> c;
		int n = a.size(), k = 0;
		for (int i=0; i<n; i++) {
			if (a[i] == c[i] || b[i] == c[i]) {
				k++;
			}
		}

		cout << (n == k ? "YES\n" : "NO\n");
	}
}