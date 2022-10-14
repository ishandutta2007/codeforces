#include<bits/stdc++.h>

using namespace std;

int tc, n, k;

int main () {
	cin >> tc;
	while (tc--) {
		cin >> n >> k;
		if (k % 3 != 0) {
			if (n % 3 == 0) cout << "Bob\n"; else cout << "Alice\n";
		} else {
			n %= (k + 1);
			if (n == k || n%3) cout << "Alice\n"; else cout << "Bob\n";
		}
	}
	return 0;
}