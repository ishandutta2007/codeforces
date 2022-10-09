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
		int a, b, c, k=0;
		cin >> a >> b >> c;
		while (max(a, b) <= c) {
			int u = max(a, b);
			int v = min(a, b);
			a = u + v;
			b = u;
			k++;
		}
		cout << k << '\n';
	}
}