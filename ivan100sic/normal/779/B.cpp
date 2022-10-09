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

	string s;
	int k;
	cin >> s >> k;

	if (s == "0") {
		cout << "0\n";
		return 0;
	}

	int n = s.size();

	int nz = 0, z = 0;

	for (int i=n-1; i>=0; i--) {
		if (s[i] == '0') {
			z++;
		} else {
			nz++;
		}

		if (z == k) {
			cout << nz << '\n';
			return 0;
		}
	}

	cout << n-1 << '\n';
}