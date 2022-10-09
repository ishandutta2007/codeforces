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

	int n;
	cin >> n;
	if (n <= 3) {
		cout << "NO\n";
		return 0;
	}

	cout << "YES\n";
	while (n > 5) {
		cout << n << " - " << n-1 << " = 1\n";
		cout << "1 * 1 = 1\n";
		n -= 2;
	}
	if (n == 5) {
		cout << "5 * 3 = 15\n";
		cout << "2 * 4 = 8\n";
		cout << "1 + 15 = 16\n";
		cout << "16 + 8 = 24\n";
	} else {
		cout << "1 * 2 = 2\n";
		cout << "2 * 3 = 6\n";
		cout << "6 * 4 = 24\n";
	}
}