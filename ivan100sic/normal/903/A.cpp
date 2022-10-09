#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int n;
	cin >> n;
	while (n--) {
		int x;
		cin >> x;
		bool ok = false;
		for (int i=0; i<=100; i++) {
			for (int j=0; j<=100; j++) {
				ok |= 3*i + 7*j == x;
			}
		}
		cout << (ok ? "YES\n" : "NO\n");
	}
}