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
		int n;
		string s;
		cin >> n >> s;

		int z = 0, x = 0;

		for (char c : s) {
			x += c == '(' ? 1 : -1;
			z = min(z, x);
		}

		cout << -z << '\n';
	}
}