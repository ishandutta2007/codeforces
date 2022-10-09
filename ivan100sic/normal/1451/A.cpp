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
		int x;
		cin >> x;
		if (x <= 3) {
			cout << x-1 << '\n';
		} else if (x % 2 == 0) {
			cout << "2\n";
		} else {
			cout << "3\n";
		}
	}
}

/*
x parno najvise 2
x -> 2 -> 1
x neparno najvise 3
x -> x-1 -> 2 -> 1

*/