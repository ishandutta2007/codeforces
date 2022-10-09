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
	if (n <= 2) {
		cout << "1\n1\n";
	} else if (n == 3) {
		cout << "2\n1 3\n";
	} else if (n == 4) {
		cout << "4\n3 1 4 2\n";
	} else {
		cout << n << '\n';
		for (int i=1; i<=n; i+=2)
			cout << i << ' ';
		for (int i=2; i<=n; i+=2)
			cout << i << ' ';
		cout << '\n';
	}
}