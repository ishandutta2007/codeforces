#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int n, k; string s;
	cin >> n >> k >> s;
	s = string(" ") + s;
	if (k-1 < n-k) {
		while (k > 1)
			k--, cout << "LEFT\n";
		for (int i=1; i<=n; i++) {
			while (k < i)
				k++, cout << "RIGHT\n";
			cout << "PRINT " << s[i] << '\n';
		}
	} else {
		while (k < n)
			k++, cout << "RIGHT\n";
		for (int i=n; i>=1; i--) {
			while (k > i)
				k--, cout << "LEFT\n";
			cout << "PRINT " << s[i] << '\n';
		}
	}
}