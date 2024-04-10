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
		int n, m;
		cin >> n >> m;
		cout << (min(n, m) == 1 || (n == 2 && m == 2) ? "YES\n" : "NO\n");
	}
}